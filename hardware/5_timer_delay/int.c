/*************
Function£ºinterrupt
**************/ 

#include "int.h"
#include "led.h"
#include "uart.h"
#include "timer.h"
#include "printf.h"


void irq_init(void)
{
	/* gic has been init in Start.S */
}



void enable_interrupts(void)
{
	asm volatile("msr	daifclr, #0x03");
}

/* irq interrupt install handle */
void irq_install_handler(int irq, interrupt_handler_t *handler, void *data)
{
	if (g_irq_handler[irq].m_func != handler)
		g_irq_handler[irq].m_func = handler;
}

/* enable irq handler */
int irq_handler_enable(int irq)
{
	unsigned long M, N;

	if (irq >= NR_GIC_IRQS)
		return -1;

	M = irq / 32;
	N = irq % 32;

	GICD->ISENABLER[M]  = (0x1 << N);

	return 0;
}

void do_irq(void)
{
	unsigned long nintid;
	unsigned long long irqstat;
	
	asm volatile("mrs %0, " __stringify(ICC_IAR1_EL1) : "=r" (irqstat));
	
	nintid = (unsigned long)irqstat & 0x3FF; 
	
	/* here we use gic id checking, not include gpio pin irq */
	if (nintid < NR_GIC_IRQS)
			g_irq_handler[nintid].m_func((void *)(unsigned long)nintid);

	asm volatile("msr " __stringify(ICC_EOIR1_EL1) ", %0" : : "r" ((unsigned long long)nintid));
	asm volatile("msr " __stringify(ICC_DIR_EL1) ", %0" : : "r" ((unsigned long long)nintid));
	isb();	
}	



static void board_timer_isr(void)
{
	static unsigned char led_flag = 0;
	
	TIMER3->INTSTATUS = 0x01;  //clrear interrupt
	
	if(led_flag == 0)
		led_mode(0);
	else
		led_mode(1);
	
	led_flag=!led_flag;
}

void test_timer_irq(void)
{
	/* enable exceptions */
	enable_interrupts();

	/* timer set */
	TIMER3->CURRENT_VALUE0 = 0x0FFFFFF;
	TIMER3->LOAD_COUNT0    = 0x0FFFFFF;
	TIMER3->CONTROL_REG    = 0x05; //auto reload & enable the timer
	
	/* register and enable */
	irq_install_handler(TIMER_INTR3, (interrupt_handler_t *)board_timer_isr, (void *)(0));
	irq_handler_enable(TIMER_INTR3);

}

static void board_gpio_isr(void)
{
	if (GPIO4->INT_STATUS & (0x01<<(3*8+5)))  //Interrupt status 
	{
		GPIO4->PORTA_EOI |= (0x01<<(3*8+5));  //Clear interrupt
		//if ((GPIO4->EXT_PORTA & (0x01<<(3*8+5))) == 0)
			printf("Button pressed!\n");
	}
}


//GPIO4_D5 
void test_gpio_irq(void)
{
	/* enable exceptions */
	enable_interrupts();
	
	/* GPIO set */
	GPIO4->SWPORTA_DDR   &= ~(0x01<<(3*8+5));  //should be Input
	GPIO4->INTEN         |=  (0x01<<(3*8+5));  //Interrupt enable
	GPIO4->INTMASK       &= ~(0x01<<(3*8+5));  //Interrupt bits are unmasked
	GPIO4->INTTYPE_LEVEL |=  (0x01<<(3*8+5));  //Edge-sensitive
	GPIO4->INT_POLARITY  &= ~(0x01<<(3*8+5));  //Active-low 
	GPIO4->DEBOUNCE      |=  (0x01<<(3*8+5));  //Enable debounce
	
	/* register and enable */
	irq_install_handler(GPIO4_INTR, (interrupt_handler_t *)board_gpio_isr, (void *)(0));
	irq_handler_enable(GPIO4_INTR);
}


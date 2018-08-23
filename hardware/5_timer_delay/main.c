
#include "led.h"
#include "uart.h"
#include "printf.h"


unsigned int test_a = 0x1234; //for test relocate
unsigned int test_b;          //for test clean bss

int main(void)
{
	led_mode(1); //YELLOW LED 
	
	uart_init();
	printf("uart_init ok \n");
	printf_test();
	
	if (0x1234 == test_a)
		printf("relocate ok, test val = 0x%04x \n", test_a);
	else
		printf("relocate error, test val = 0x%04x \n", test_a);
	

	if (0 == test_b)
		printf("clean bss ok, test val = %d  \n", test_b);
	else
		printf("clean bss error, test val = %d \n", test_b);

		
	
	//test_timer_irq();
	//printf("test_timer_irq \n");
	
	//test_gpio_irq();
	//printf("test_gpio_irq \n");

	
	while(1)
	{
		led_mode(3);
		delay_s(4);
		
		led_mode(0);
		delay_s(4);
	}
	
	return 0;
}
	

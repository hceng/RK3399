
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

    test_timer_irq();
    printf("test_timer_irq \n");

    test_gpio_irq();
    printf("test_gpio_irq \n");


    while(1)
    {

    }

    return 0;
}


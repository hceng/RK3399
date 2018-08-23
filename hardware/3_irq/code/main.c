
#include "led.h"

unsigned int test_a = 0x1234; //for test relocate
unsigned int test_b;          //for test clean bss

int main(void)
{
    led_mode(1); //YELLOW LED

    if ((0x1234 != test_a) || (0 != test_b))
    {
        led_mode(3);
        led_delay();

        led_mode(0);
        led_delay();
    }

    test_timer_irq();
    test_gpio_irq();


    while(1)
    {

    }

    return 0;
}


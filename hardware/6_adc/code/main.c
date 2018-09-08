
#include "led.h"
#include "uart.h"
#include "printf.h"

int main(void)
{
    led_mode(1); //YELLOW LED

    uart_init();
    printf("uart_init ok \n");

    while(1)
    {
        led_mode(3);
        delay_s(1);

        get_tsadc_temp(0);
        printf("get_saradc_val = %d\n\r", get_saradc_val(0));

        led_mode(0);
        delay_s(1);
    }
    return 0;
}


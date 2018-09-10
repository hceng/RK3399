
#include "led.h"
#include "uart.h"
#include "printf.h"

int main(void)
{
    unsigned int i, j;
    char str[20];
    unsigned int mid, pid;

    uart_init();
    printf("uart_init ok \n");

    pwm1_out(40);

    while(1)
    {

    }

    return 0;
}


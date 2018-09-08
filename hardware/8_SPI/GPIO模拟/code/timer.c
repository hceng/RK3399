
#include "timer.h"

//timer4 is used for delay.
void delay_us(volatile unsigned long int  i)
{
    unsigned long int count_value = 24 * i;  //24MHz; period=(1/24000000)*1000000=1/24us

    TIMER4->CONTROL_REG &= ~(0x01 << 0);     //Timer disable
    TIMER4->CONTROL_REG |=  (0x01 << 1);     //Timer mode:user-defined count mode
    TIMER4->CONTROL_REG &= ~(0x01 << 2);     //Timer interrupt mask

    TIMER4->LOAD_COUNT0 = count_value & 0xFFFFFFFF;             //load_count_low bits
    //TIMER4->LOAD_COUNT1 = (count_value & (0xFFFFFFFF<<8)) >> 8; //load_count_high bits 

    TIMER4->CONTROL_REG |=  (0x01 << 0);     //Timer enable

    while(!(TIMER4->INTSTATUS & (0x01 << 0)));
    TIMER4->INTSTATUS |= (0x01 << 0);        //Write 1 clear the interrupt

    TIMER4->CONTROL_REG &= ~(0x01 << 0);     //Timer enable disable
}

void delay_ms(volatile unsigned long int i)
{
    for(; i > 0; i--)
        delay_us(1000);
}

void delay_s(volatile unsigned long int i)
{
    for(; i > 0; i--)
        delay_ms(1000);
}


#include "pwm.h"
#include "gpio.h"
#include "timer.h"



//GPIO4_C6/PWM1
//0~100
void pwm1_out(unsigned char val)
{
#if 0	 //test gpio ok
    GPIO4->SWPORTA_DDR |=  (0x01 << (2 * 8 + 6));

    while(1)
    {
        GPIO4->SWPORTA_DR  &= ~(0x01 << (2 * 8 + 6));
        delay_ms(10);
        GPIO4->SWPORTA_DR  |=  (0x01 << (2 * 8 + 6));
        delay_ms(10);
    }
#else
    //1.IOMUX
    GRF_GPIO4C_IOMUX  |=  ((0x03 << 28) | (0x01 << 12)); //  1'b1: pwm_1
    //GRF_SOC_CON2  |=  ((0x01<<16) | (0x01<<0)); //P136  1'b1: pwm_1

    //2.Set PWM
    PWM1->CTRL &= ~(0x01 << 0); //PWM channel disabled
    //2.1 设置时钟源、比例系数、预分频、
    //PWM1->CTRL |= ((0x01<<16) | (0x01<<12) | (0x01<<9));//Scale Factor / Prescale Factor / Clock Source Select
    //2.2 设置模式:连续模式,占空比极性为高、左对齐(默认)
    PWM1->CTRL |=  (0x01 << 1) | (0x01 << 3); //PWM Operation Mode 01: Continuous mode.

    //3.Set Duty Cycle
    if(val > 100)
        val = 100;
    PWM1->PERIOD_HPR = 100; //总周期
    PWM1->DUTY_LPR   = val;  //占空比=val/总周期

    //4.Start
    PWM1->CTRL |=  (0x01 << 0);
#endif

}
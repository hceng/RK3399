
#include "uart.h"
#include "printf.h"
#include "timer.h"
#include "int.h"
#include "adc.h"

unsigned int get_saradc_val(unsigned char channel)
{
    unsigned int val;

    //delay between power up and start command
    //SARADC_DLY_PU_SOC = 8; //DLY_PU_SOC + 2

    SARADC_CTRL &= ~(0x01 << 3); //ADC power down control bit

    SARADC_CTRL |= (channel << 0); //ADC input source selection

    //SARADC_CTRL |= (0x01<<3); //Interrupt enable.

    SARADC_CTRL |=  (0x01 << 3); //ADC power up and reset
    delay_us(100); //不能立即就判断状态

    while(SARADC_STAS & 0x01); //The status register of A/D Converter 1’b0: ADC stop

    val = SARADC_DATA & 0x3FF; //A/D value of the last conversion (DOUT[9:0]).

    return val;
}

//channel0: CPU temperature
//channel1: GPU temperature
int get_tsadc_temp(unsigned char channel)
{
    int val;

    if ((channel != 0) && (channel != 1))
    {
        printf("get_tsadc_temp set channel error.\n");
        return -255;
    }

    //User-Define Mode
    TSADC_AUTO_CON &= ~(0x01 << 0);     //TSADC controller works at user-define mode
    TSADC_AUTO_CON |=  (0x01 << 1);     //RK3399 is negative temprature coefficient

    TSADC_USER_CON &= ~(0x07 << 0);     //clear
    TSADC_USER_CON |=  (channel << 0);  //PD_DVDD and ADC input source selection
    TSADC_USER_CON |=  (0x01 << 3);     //CHSEL_DVDD and ADC power up and reset

    TSADC_USER_CON |=  (0x01 << 4);     //the start_of_conversion will be controlled by TSADC_USER_CON[5].
    TSADC_USER_CON |=  (0x01 << 5);     //start conversion

    TSADC_INT_EN   |=  (0x01 << 16);    //eoc_interrupt enable in user defined mode
    while(!(TSADC_INT_PD & (0x01 << 16))); //wait ADC conversion stop
    TSADC_INT_PD &= ~(0x01 << 16);

    if (0 == channel)
        val = (int)(0.5823 * (float)(TSADC_DATA0) - 273.62); //y = 0.5823x - 273.62
    else
        val = (int)(0.5823 * (float)(TSADC_DATA1) - 273.62); //y = 0.5823x - 273.62

    printf("get_tsadc_temp = %d \n", val);

    return val;
}
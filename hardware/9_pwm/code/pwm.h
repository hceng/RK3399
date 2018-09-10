#ifndef  __PWM_H__
#define  __PWM_H__

#include "grf.h"



#define    PWM_BASE                        0xFF420000

typedef volatile struct pwm_reg
{
    unsigned int CNT;           //0x0000 Counter Register
    unsigned int PERIOD_HPR;    //0x0004 Period Register/High Polarity Capture Register
    unsigned int DUTY_LPR;      //0x0008 Duty Register/Low Polarity Capture Register
    unsigned int CTRL;          //0x000C Control Register
} pwm_reg, *p_pwm_reg;

#define   PWM0                   ((p_pwm_reg)(PWM_BASE + 0x00))
#define   PWM1                   ((p_pwm_reg)(PWM_BASE + 0x10))
#define   PWM2                   ((p_pwm_reg)(PWM_BASE + 0x20))
#define   PWM3                   ((p_pwm_reg)(PWM_BASE + 0x30))


#define   PWM_INTSTS             (*(volatile unsigned int *)(PWM_BASE + 0x40))       //Interrupt Status Register
#define   PWM_INT_EN             (*(volatile unsigned int *)(PWM_BASE + 0x44))       //Interrupt Enable Register
#define   PWM_FIFO_CTRL          (*(volatile unsigned int *)(PWM_BASE + 0x50))       //PWM Channel 3 FIFO Mode Control Register
#define   PWM_FIFO_INTSTS        (*(volatile unsigned int *)(PWM_BASE + 0x54))       //FIFO Interrupts Status Register
#define   PWM_FIFO_TOUTTHR		 (*(volatile unsigned int *)(PWM_BASE + 0x58))       //FIFO Timeout Threshold Register
#define   PWM_FIFO0              (*(volatile unsigned int *)(PWM_BASE + 0x60))       //FIFO Register
#define   PWM_FIFO1              (*(volatile unsigned int *)(PWM_BASE + 0x64))
#define   PWM_FIFO2              (*(volatile unsigned int *)(PWM_BASE + 0x68))
#define   PWM_FIFO3              (*(volatile unsigned int *)(PWM_BASE + 0x6C))
#define   PWM_FIFO4              (*(volatile unsigned int *)(PWM_BASE + 0x70))
#define   PWM_FIFO5              (*(volatile unsigned int *)(PWM_BASE + 0x74))
#define   PWM_FIFO6              (*(volatile unsigned int *)(PWM_BASE + 0x78))
#define   PWM_FIFO7              (*(volatile unsigned int *)(PWM_BASE + 0x7C))


//pwm3 GRF_GPIO0A_IOMUX[13:12]=2’b01     PMUGRF_SOC_CON0[5]=1’b0
//     GRF_GPIO1B_IOMUX[13:12]=2’b01     PMUGRF_SOC_CON0[5]=1’b1
//pwm2 GRF_GPIO1C_IOMUX[7:6]=2’b01
//pwm1 GRF_GPIO4C_IOMUX[13:12]=2’b01
//pwm0 GRF_GPIO4C_IOMUX[5:4]=2’b01


extern void pwm1_out(unsigned char val);


#endif
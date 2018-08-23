/*************
Function£ºLEDS
WORK_LED     BLUE    GPIO2_D3   High_level_on
DIY_LED      YELLOW  GPIO0_B5   High_level_on
**************/ 

#include "led.h"

void led_delay(void)
{
	volatile unsigned long int i,j;
	for(i=20;i>0;i--)
		for(j=10000;j>0;j--);	
}

void led_mode(int mode)
{	
	GPIO0->SWPORTA_DDR |=  (0x01<<(1*8+5)); 
	GPIO2->SWPORTA_DDR |=  (0x01<<(3*8+3)); 

	GPIO0->SWPORTA_DR  &= ~(0x01<<(1*8+5)); 
	GPIO2->SWPORTA_DR  &= ~(0x01<<(3*8+3)); 
	
	if(0 == mode) 
	{
		GPIO0->SWPORTA_DR  &= ~(0x01<<(1*8+5)); 
		GPIO2->SWPORTA_DR  &= ~(0x01<<(3*8+3)); 
	}
	else if(1 == mode) 
	{
		GPIO0->SWPORTA_DR  |=  (0x01<<(1*8+5)); 
	}
	else if(2 == mode) 
	{
		GPIO2->SWPORTA_DR  |=  (0x01<<(3*8+3)); 
	}
	else if(3 == mode) 
	{
		GPIO0->SWPORTA_DR  |=  (0x01<<(1*8+5)); 
		GPIO2->SWPORTA_DR  |=  (0x01<<(3*8+3)); 
	}
	
}






	
	

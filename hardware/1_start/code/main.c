
#include "led.h"


static void led_delay(void)
{
	volatile unsigned long int i,j;
	for(i=10;i>0;i--)
		for(j=10000;j>0;j--);	
}


int main(void)
{
	led_mode(1);
	
	while(1)
	{
		led_mode(1);
		led_delay();
		led_delay();

		led_mode(2);
		led_delay();
		led_delay();

		led_mode(3);
		led_delay();
	}
	
	return 0;
}
	


#include "led.h"
#include "uart.h"
#include "printf.h"

int main(void)
{
	int i;
	
	uart_init();
	printf("uart_init ok \n");

	
	i2c_init();
	
	//write eeprom.
	for(i=0; i<5; i++)
    {
        eeprom_write(i,2*i);
        delay_ms(4);//Must be delayed more than 4ms.
    }
	
	printf("write eeprom ok\n\r");
	delay_ms(10);
	
	//read eeprom.
    for(i=0; i<5; i++)
    {
        printf("read_data%d = %d\n\r", i, eeprom_read(i));
        delay_ms(4);
    }
	

	while(1)
	{
		led_mode(3);
		delay_s(1);
		
		led_mode(0);
		delay_s(1);
	}
    return 0;
}


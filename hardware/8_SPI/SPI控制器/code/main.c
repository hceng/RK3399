
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

    spi_init();
	
	spi_flash_read_ID(&mid, &pid);
	printf("SPI Flash : MID = 0x%02x, PID = 0x%02x\n\r", mid, pid);	

    spi_flash_init();
    while(1)
	{
        spi_flash_erase_sector(4096);
        spi_flash_program(4096, "hceng", 7);
        spi_flash_read(4096, str, 7);
        printf("SPI Flash read from 4096: %s\n\r", str);
        
        delay_s(2);
    }

	return 0;
}


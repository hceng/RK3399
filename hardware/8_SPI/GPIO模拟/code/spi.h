#ifndef  __SPI_H__
#define  __SPI_H__


extern void spi_init(void);
extern void spi_flash_read_ID(unsigned int *pMID, unsigned int *pDID);
extern void spi_flash_init(void);
extern void spi_flash_erase_sector(unsigned int addr);
extern void spi_flash_program(unsigned int addr, unsigned char *buf, int len);
extern void spi_flash_read(unsigned int addr, unsigned char *buf, int len);
//extern void printf_spi_reg(int i);


#endif
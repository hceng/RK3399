#ifndef  __SPI_H__
#define  __SPI_H__

#include "gpio.h"
#include "grf.h"

#define    SPI0_BASE          0xFF1C0000        
#define    SPI1_BASE          0xFF1D0000       
#define    SPI2_BASE          0xFF1E0000       
#define    SPI3_BASE          0xFF350000    
#define    SPI4_BASE          0xFF1F0000       
#define    SPI5_BASE          0xFF200000       

                              

typedef volatile struct spi_reg {
	unsigned int CTRLR0;                //0x0000 Control Register 0
	unsigned int CTRLR1;                //0x0004 Control Register 1
	unsigned int ENR;                   //0x0008 SPI Enable
	unsigned int SER;                   //0x000C Slave Enable Register
	unsigned int BAUDR;                 //0x0010 Baud Rate Select
	unsigned int TXFTLR;                //0x0014 Transmit FIFO Threshold Level
	unsigned int RXFTLR;                //0x0018 Receive FIFO Threshold Level
	unsigned int TXFLR;                 //0x001C Transmit FIFO Level
	unsigned int RXFLR;                 //0x0020 Receive FIFO Level
	unsigned int SR;                    //0x0024 SPI Status
	unsigned int IPR;                   //0x0028 Interrupt Polarity
	unsigned int IMR;                   //0x002C Interrupt Mask
	unsigned int ISR;                   //0x0030 Interrupt Status
	unsigned int RISR;                  //0x0034 Raw Interrupt Status
	unsigned int ICR;                   //0x0038 Interrupt Clear
	unsigned int DMACR;                 //0x003C DMA Control
	unsigned int DMATDLR;               //0x0040 DMA Transmit Data Level
	unsigned int DMARDLR;               //0x0044 DMA Receive Data Level
	unsigned int RESERVED0[238];        //0x0048
	unsigned int TXDR[256];             //0x0400 Transmit FIFO Data
	unsigned int RXDR[256];             //0x0800 Receive FIFO Data
} spi_reg, *p_spi_reg;      

#define SPI0      ((p_spi_reg)SPI0_BASE)
#define SPI1      ((p_spi_reg)SPI1_BASE)
#define SPI2      ((p_spi_reg)SPI2_BASE)
#define SPI3      ((p_spi_reg)SPI3_BASE)
#define SPI4      ((p_spi_reg)SPI4_BASE)
#define SPI5      ((p_spi_reg)SPI5_BASE)

extern void spi_init(void);
extern void spi_flash_read_ID(unsigned int *pMID, unsigned int *pDID);
extern void spi_flash_init(void);
extern void spi_flash_erase_sector(unsigned int addr);
extern void spi_flash_program(unsigned int addr, unsigned char *buf, int len);
extern void spi_flash_read(unsigned int addr, unsigned char *buf, int len);


#endif
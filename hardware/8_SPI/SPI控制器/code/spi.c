
#include "spi.h"
#include "uart.h"
#include "printf.h"
#include "timer.h"
#include "gpio.h"
#include "grf.h"

void spi_init(void)
{
    //SPI1_CSn0/GPIO1_B2_U
    //SPI1_CLK/GPIO1_B1_U
    //SPI1_TXD/GPIO1_B0_U
    //SPI1_RXD/GPIO1_A7_U

    //1.IOMUX
    PMUGRF_GPIO1A_IOMUX = 0xFFFF8000;
    PMUGRF_GPIO1B_IOMUX = 0xFFFF002A;

    SPI1->ENR &=  ~(0x01 << 0); //关闭SPI

    //2.Clock Ratios   master mode:Fspi_clk>= 2 × (maximum Fsclk_out)
    //CRU_CLKGATE2_CON &= ~(0x01<<9);  //默认SPI1 source clock开启
    //CRU_CLKGATE6_CON &= ~(0x01<<4);  //默认SPI1 APB clock开启
    SPI1->BAUDR = 24; //Fsclk_out = 48/24= 2M   48 >= 2x2

    //3.注册/使能中断(本程序未使用,用的查询)
    //register_irq(IRQ_SPI1, spi_irq_isr);
    //irq_handler_enable(IRQ_SPI1);
    //SPI1->IPR &= ~(0x01<<4); //Active Interrupt Polarity Level is HIGH(default)
    //SPI1->IMR |=  ((0x01<<4) | (0x01<<3) | (0x01<<2) | (0x01<<1) | (0x01<<0)); //Interrupt Mask

    //4.DMA(可以不用)
    //SPI1->DMACR |= ((0x01<<1) | (0x01<<0)); // Transmit/Receive DMA enabled
    //SPI1->DMATDLR = 1; //?
    //SPI1->DMARDLR = 1; //?

    //5.SPI模式
    //[1:0]Data Frame Size:8bit data
    //[5:2]Control Frame Size:8-bit serial data transfer
    //[6]SCPH:Serial clock toggles at start of first data bit
    //[7]SCPOL:Inactive state of serial clock is high
    //[13]BHT:apb 8bit write/read, spi 8bit write/read
    //[19:18]XFM(Transfer Mode):Transmit & Receive(default)
    //[20]OPM(Operation Mode):Master Mode(default)

    SPI1->CTRLR0 &= ~(0x03 << 0) ;
    SPI1->CTRLR0 |= ((0x01 << 0) | (0x07 << 2) | (0x01 << 6) | (0x01 << 7) | (0x01 << 13)); //设置SPI模式
}

void spi_send_byte(unsigned char val)
{
    SPI1->ENR |=  (0x01 << 0);      //SPI Enable

    SPI1->TXDR[0] = val & 0xFFFF;
    while(!(SPI1->SR & (0x01 << 2))); //Transmit FIFO is empty
    while(SPI1->SR & (0x01 << 0));  //SPI is idle or disabled

    SPI1->ENR &=  ~(0x01 << 0);     //SPI Disable
}

static unsigned char spi_recv_byte(void)
{
    unsigned char val = 0;

    SPI1->ENR |=  (0x01 << 0);    //SPI Enable

    SPI1->TXDR[0] = 0;            //因为是发送接收模式,FIFO在发送时也会接收数据,这里发送空数据,就可读取数据

    while(SPI1->SR & (0x01 << 3)); //SReceive FIFO is not empty
    while(SPI1->SR & (0x01 << 0)); //SPI is idle or disabled

    val = SPI1->RXDR[0] & 0xFF;  //读数据

    SPI1->ENR &=  ~(0x01 << 0);  //SPI Disable,为了清空FIFO

    return val;
}


void spi_flash_set_cs(unsigned char flag)
{
    if(!flag)
        SPI1->SER |=  (0x01 << 0);
    else
        SPI1->SER &= ~(0x01 << 0);
}




/* 通用部分 */
static void spi_flash_send_addr(unsigned int addr)
{
    spi_send_byte(addr >> 16);
    spi_send_byte(addr >> 8);
    spi_send_byte(addr & 0xff);
}

static void spi_flash_write_enable(int enable)
{
    if (enable)
    {
        spi_flash_set_cs(0);
        spi_send_byte(0x06);
        spi_flash_set_cs(1);
    }
    else
    {
        spi_flash_set_cs(0);
        spi_send_byte(0x04);
        spi_flash_set_cs(1);
    }

}

static unsigned char spi_flash_read_status_reg1(void)
{
    unsigned char val;

    spi_flash_set_cs(0);

    spi_send_byte(0x05);
    val = spi_recv_byte();

    spi_flash_set_cs(1);

    return val;
}

static unsigned char spi_flash_read_status_reg2(void)
{
    unsigned char val;

    spi_flash_set_cs(0);

    spi_send_byte(0x35);
    val = spi_recv_byte();

    spi_flash_set_cs(1);

    return val;
}

static void spi_flash_wait_when_busy(void)
{
    while (spi_flash_read_status_reg1() & 1);
}

static void spi_flash_write_status_reg(unsigned char reg1, unsigned char reg2)
{
    spi_flash_write_enable(1);

    spi_flash_set_cs(0);

    spi_send_byte(0x01);
    spi_send_byte(reg1);
    spi_send_byte(reg2);

    spi_flash_set_cs(1);

    spi_flash_wait_when_busy();
}

static void spi_flash_clear_protect_for_status_reg(void)
{
    unsigned char reg1, reg2;

    reg1 = spi_flash_read_status_reg1();
    reg2 = spi_flash_read_status_reg2();

    reg1 &= ~(1 << 7);
    reg2 &= ~(1 << 0);

    spi_flash_write_status_reg(reg1, reg2);
}


static void spi_flash_clear_protect_for_data(void)
{
    /* cmp=0,bp2,1,0=0b000 */
    unsigned char reg1, reg2;

    reg1 = spi_flash_read_status_reg1();
    reg2 = spi_flash_read_status_reg2();

    reg1 &= ~(7 << 2);
    reg2 &= ~(1 << 6);

    spi_flash_write_status_reg(reg1, reg2);
}

/* erase 4K */
void spi_flash_erase_sector(unsigned int addr)
{
    spi_flash_write_enable(1);

    spi_flash_set_cs(0);

    spi_send_byte(0x20);
    spi_flash_send_addr(addr);

    spi_flash_set_cs(1);

    spi_flash_wait_when_busy();
}

/* program */
void spi_flash_program(unsigned int addr, unsigned char *buf, int len)
{
    int i;

    spi_flash_write_enable(1);

    spi_flash_set_cs(0);

    spi_send_byte(0x02);
    spi_flash_send_addr(addr);

    for (i = 0; i < len; i++)
        spi_send_byte(buf[i]);

    spi_flash_set_cs(1);

    spi_flash_wait_when_busy();

}

void spi_flash_read(unsigned int addr, unsigned char *buf, int len)
{
    int i;

    spi_flash_set_cs(0);

    spi_send_byte(0x03);
    spi_flash_send_addr(addr);
    for (i = 0; i < len; i++)
        buf[i] = spi_recv_byte();

    spi_flash_set_cs(1);
}

void spi_flash_init(void)
{
    spi_flash_clear_protect_for_status_reg();
    spi_flash_clear_protect_for_data();
}

void spi_flash_read_ID(unsigned int *pMID, unsigned int *pDID)
{

    spi_flash_set_cs(0);

    spi_send_byte(0x90);

    spi_flash_send_addr(0);

    *pMID = spi_recv_byte();
    *pDID = spi_recv_byte();

    spi_flash_set_cs(1);
}




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


    PMUGRF_GPIO1A_IOMUX = 0xFFFF0000;
    PMUGRF_GPIO1B_IOMUX = 0xFFFF0000; //这里必须改回为GPIO,不然GPIO无法控制,怀疑头部代码修改了该引脚复用;

    GPIO1->SWPORTA_DDR |=  ((0x01 << (1 * 8 + 0)) | (0x01 << (1 * 8 + 1)) | (0x01 << (1 * 8 + 2))); //Output
    GPIO1->SWPORTA_DDR &= ~(0x01 << (0 * 8 + 7)); //Input

    GPIO1->SWPORTA_DR  |=  ((0x01 << (1 * 8 + 0)) | (0x01 << (1 * 8 + 1)) | (0x01 << (1 * 8 + 2))); //拉高
}

static void spi_set_clk(char val)
{
    if(val)
        GPIO1->SWPORTA_DR |=  (0x01 << (1 * 8 + 1));
    else
        GPIO1->SWPORTA_DR &= ~(0x01 << (1 * 8 + 1));
}

static void spi_flash_set_cs(char val)
{
    if(val)
        GPIO1->SWPORTA_DR |=  (0x01 << (1 * 8 + 2));
    else
        GPIO1->SWPORTA_DR &= ~(0x01 << (1 * 8 + 2));
}

static void spi_set_output(char val)
{
    if(val)
        GPIO1->SWPORTA_DR |=  (0x01 << (1 * 8 + 0));
    else
        GPIO1->SWPORTA_DR &= ~(0x01 << (1 * 8 + 0));
}

static char spi_set_input(void)
{
    return (GPIO1->EXT_PORTA & (0x01 << (0 * 8 + 7)) ? 1 : 0);
}


void spi_send_byte(unsigned char val)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        spi_set_clk(0);
        spi_set_output(val & 0x80);
        spi_set_clk(1);
        val <<= 1;
    }

}

unsigned char spi_recv_byte(void)
{
    int i;

    unsigned char val = 0;
    for (i = 0; i < 8; i++)
    {
        val <<= 1;
        spi_set_clk(0);
        if (spi_set_input())
            val |= 1;
        spi_set_clk(1);
    }
    return val;
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



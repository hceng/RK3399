#include "i2c.h"
#include "uart.h"
#include "printf.h"
#include "timer.h"


//GPIO1_B3/I2C4_SDA
//GPIO1_B4/I2C4_SCL

void i2c_init(void)
{
    //1.GPIO1_B3/I2C4_SDA、GPIO1_B4/I2C4_SCL设置为功能引脚,注意高位要先置为1才能写;
    PMUGRF_GPIO1B_IOMUX |= ((0xFFFF0000 << 0) | (0x01 << 6) | (0x01 << 8));

    //2.设置SCK时钟
    //3.注册/使能中断
}


void eeprom_write(unsigned char addr, unsigned char data)
{
    //0.清空控制寄存器并使能
    I2C4->CON &= ~(0x7F << 0);
    I2C4->IPD &= ~(0x7F << 0);
    I2C4->CON |= 0x01 << 0; //使能

    //1.设置模式:transmit only
    I2C4->CON &= ~(0x03 << 1);

    //2.开始信号
    I2C4->CON |= 0x01 << 3; //开始信号
    while(!(I2C4->IPD & (0x01 << 4))); //等待开始信号发完
    I2C4->IPD |=  (0x01 << 4); //清开始信号标志

    //3.I2C从机地址+写地址+数据 (3个字节)
    I2C4->TXDATA0 = 0xA0 | (addr << 8) | (data << 16);
    I2C4->MTXCNT = 3;
    while(!(I2C4->IPD & (0x01 << 2))); //MTXCNT data transmit finished interrupt pending bit
    I2C4->IPD |=  (0x01 << 2);

    //4.结束信号
    I2C4->CON &= ~(0x01 << 3); //手动清除start(注意:前面的开始信号控制位理论会自动清0,实测没有,这里必须手动清,否则是开始信号)
    I2C4->CON |= (0x01 << 4);
    while(!(I2C4->IPD & (0x01 << 5)));
    I2C4->IPD |=  (0x01 << 5);
}

//自动发送从机地址和从机寄存器地址
unsigned char eeprom_read(unsigned char addr)
{
    unsigned char data = 0;

    //0.清空控制寄存器并使能
    I2C4->CON &= ~(0x7F << 0);
    I2C4->IPD &= ~(0x7F << 0);
    I2C4->CON |= 0x01 << 0; //使能

    //必须收到ack,否则停止传输(非必需)
    //I2C4->CON |=  (0x01<<6); //stop transaction when NAK handshake is received

    //1.设置模式:transmit address (device + register address) --> restart --> transmit address –> receive only
    I2C4->CON |=  (0x01 << 1); //自动发送从机地址和从机寄存器地址

    //2.从机地址
    I2C4->MRXADDR = (0xA0 | (1 << 24));

    //3.从机寄存器地址
    I2C4->MRXRADDR = (addr | (1 << 24)); //地址只有6位,超过6位怎么办?

    //4.开始信号
    I2C4->CON |=  (0x01 << 3);
    while(!(I2C4->IPD & (0x01 << 4)));
    I2C4->IPD |=  (0x01 << 4);

    //5.接收一个数据且不响应
    I2C4->CON |= (0x01 << 5);
    I2C4->MRXCNT = 1;
    while(!(I2C4->IPD & (0x01 << 3)));
    I2C4->IPD |=  (0x01 << 3);

    //6.结束信号
    I2C4->CON &= ~(0x01 << 3); //手动清除start
    I2C4->CON |= (0x01 << 4);
    while(!(I2C4->IPD & (0x01 << 5)));
    I2C4->IPD |=  (0x01 << 5);

    return (I2C4->RXDATA0 & 0xFF);
}


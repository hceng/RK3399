#include "i2c.h"
#include "uart.h"
#include "printf.h"
#include "timer.h"


//GPIO1_B3/I2C4_SDA
//GPIO1_B4/I2C4_SCL

static void i2c_delay(volatile int time)
{
    time = time * 1;
    for (; time > 0; time--);
}

static void SDA(char x)
{
    GPIO1->SWPORTA_DDR |=  (0x01 << (1 * 8 + 3));

    if(x)
        GPIO1->SWPORTA_DR |=  (0x01 << (1 * 8 + 3));
    else
        GPIO1->SWPORTA_DR &= ~(0x01 << (1 * 8 + 3));
}

static void SCL(char x)
{
    GPIO1->SWPORTA_DDR |=  (0x01 << (1 * 8 + 4));

    if(x)
        GPIO1->SWPORTA_DR |=  (0x01 << (1 * 8 + 4));
    else
        GPIO1->SWPORTA_DR &= ~(0x01 << (1 * 8 + 4));
}

static char GET_SDA(void)
{
    GPIO1->SWPORTA_DDR &= ~(0x01 << (1 * 8 + 3));

    return (GPIO1->EXT_PORTA & (0x01 << (1 * 8 + 3)) ? 1 : 0);
}


void i2c_init(void)
{
    //GPIO1_B3/I2C4_SDA   GPIO1_B4/I2C4_SCL 设置为GPIO
    //gpio(default)

    GPIO1->SWPORTA_DDR |=  ((0x01 << (1 * 8 + 3)) | (0x01 << (1 * 8 + 4))); //Output
    GPIO1->SWPORTA_DR  |=  ((0x01 << (1 * 8 + 3)) | (0x01 << (1 * 8 + 4))); //拉高

}

static void i2c_start(void)
{
    SCL(1);
    i2c_delay(1);

    SDA(1);
    i2c_delay(1);
    SDA(0);
    i2c_delay(1);

    SCL(0);
    i2c_delay(1);
}

static void i2c_stop(void)
{
    SDA(0);
    i2c_delay(1);

    SCL(1);
    i2c_delay(1);

    SDA(1);
    i2c_delay(1);
}

static int i2c_ack(void)
{
    int pin_val;

    SCL(0);
    i2c_delay(1);

    SDA(1);
    i2c_delay(1);

    GET_SDA();

    SCL(1);
    i2c_delay(1);

    pin_val = GET_SDA();
    i2c_delay(1);

    SCL(0);
    i2c_delay(1);

    return pin_val;
}


static void i2c_write(unsigned char data)
{
    int i = 0;

    for(i = 0; i < 8; i++)
    {
        SCL(0);
        i2c_delay(1);

        if(data & 0x80)
            SDA(1);
        else
            SDA(0);
        data = data << 1;
        i2c_delay(1);

        SCL(1);
        i2c_delay(1);
    }
    SCL(0);
    i2c_delay(1);
}

static unsigned char i2c_read(void)
{
    int i = 0;
    unsigned char data = 0;

    SCL(0);
    i2c_delay(1);
    SDA(1);

    GET_SDA();//同理
    i2c_delay(1);

    for(i = 0; i < 8; i++)
    {
        SCL(1);
        i2c_delay(1);

        data = data << 1;
        if(GET_SDA()) data |= 0x01;

        SCL(0);
        i2c_delay(1);
    }

    SCL(1);//再给eeprom的ack提供一个时钟周期
    i2c_delay(1);
    SCL(0);
    i2c_delay(1);

    return data;
}


static void eeprom_write_protect(char x)
{
#if 0
    if(x)
        GPIO3->DATAOUT |=  (0x01 << 7);
    else
        GPIO3->DATAOUT &= ~(0x01 << 7);
#endif
}


void eeprom_write(unsigned char addr, unsigned char data)
{
    eeprom_write_protect(0);

    i2c_start();

    i2c_write(0xA0);
    while(i2c_ack());

    //i2c_write(addr>>8); //AT24C256W大容量
    i2c_write(addr);      //AT24C02A小容量
    while(i2c_ack());
    //i2c_write(addr);
    //while(i2c_ack());

    i2c_write(data);
    while(i2c_ack());

    i2c_stop();

    eeprom_write_protect(1);
}

unsigned char eeprom_read(unsigned char addr)
{
    unsigned char data = 0;

    eeprom_write_protect(0);

    i2c_start();

    i2c_write(0xA0);
    while(i2c_ack());

    //i2c_write(addr>>8);
    i2c_write(addr);
    while(i2c_ack());
    //i2c_write(addr);
    //while(i2c_ack());

    i2c_stop();

    i2c_delay(10);

    i2c_start();

    i2c_write(0xA1);
    while(i2c_ack());

    data = i2c_read();

    i2c_stop();

    eeprom_write_protect(1);

    return data;
}

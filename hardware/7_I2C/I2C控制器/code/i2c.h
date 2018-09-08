#ifndef  __I2C_H__
#define  __I2C_H__

#include "gpio.h"
#include "grf.h"

#define    I2C0_BASE                0xFF3C0000
#define    I2C1_BASE                0xFF110000
#define    I2C2_BASE                0xFF120000
#define    I2C3_BASE                0xFF130000
#define    I2C4_BASE                0xFF3D0000
#define    I2C5_BASE                0xFF140000
#define    I2C6_BASE                0xFF150000
#define    I2C7_BASE                0xFF160000

typedef volatile struct i2c_reg
{
    unsigned int CON;             //0x0000 control register
    unsigned int CLKDIV;          //0x0004 Clock divisor register
    unsigned int MRXADDR;	      //0x0008 the slave address accessed for master receive mode
    unsigned int MRXRADDR;        //0x000C the slave register address accessed for master recevie mode
    unsigned int MTXCNT;          //0x0010 master transmit count
    unsigned int MRXCNT;          //0x0014 master receive count
    unsigned int IEN;             //0x0018 interrupt enable register
    unsigned int IPD;             //0x001C interrupt pending register
    unsigned int FCNT;            //0x0020 finished count
    unsigned int SCL_OE_DB;       //0x0024 slave hold debounce configure register
    unsigned int RESERVED0[54];
    unsigned int TXDATA0;         //0x0100 I2C transmit data register 0
    unsigned int TXDATA1;         //0x0104
    unsigned int TXDATA2;         //0x0108
    unsigned int TXDATA3;         //0x010C
    unsigned int TXDATA4;         //0x0110
    unsigned int TXDATA5;         //0x0114
    unsigned int TXDATA6;         //0x0118
    unsigned int TXDATA7;	      //0x011C
    unsigned int RESERVED1[56];
    unsigned int RXDATA0;	      //0x0200 I2C receive data register 0
    unsigned int RXDATA1;	      //0x0204
    unsigned int RXDATA2;         //0x0208
    unsigned int RXDATA3;	      //0x020C
    unsigned int RXDATA4;         //0x0210
    unsigned int RXDATA5;         //0x0214
    unsigned int RXDATA6;         //0x0218
    unsigned int RXDATA7;         //0x021C
    unsigned int ST;              //0x0220 status debug register
} i2c_reg, *p_i2c_reg;

#define     I2C0                   ((p_i2c_reg)I2C0_BASE)
#define     I2C1                   ((p_i2c_reg)I2C1_BASE)
#define     I2C2                   ((p_i2c_reg)I2C2_BASE)
#define     I2C3                   ((p_i2c_reg)I2C3_BASE)
#define     I2C4                   ((p_i2c_reg)I2C4_BASE)
#define     I2C5                   ((p_i2c_reg)I2C5_BASE)
#define     I2C6                   ((p_i2c_reg)I2C6_BASE)
#define     I2C7                   ((p_i2c_reg)I2C7_BASE)

extern void i2c_init(void);
extern void eeprom_write(unsigned char addr, unsigned char data);
extern unsigned char eeprom_read(unsigned char addr);

#endif
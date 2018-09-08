#ifndef  __I2C_H__
#define  __I2C_H__

#include "gpio.h"
#include "grf.h"

extern void i2c_init(void);
extern void eeprom_write(unsigned char addr, unsigned char data);
extern unsigned char eeprom_read(unsigned char addr);

#endif
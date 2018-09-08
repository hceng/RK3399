#ifndef   __GPIO_H__
#define   __GPIO_H__

#define    GPIO0_BASE                0xFF720000
#define    GPIO1_BASE                0xFF730000
#define    GPIO2_BASE                0xFF780000
#define    GPIO3_BASE                0xFF788000
#define    GPIO4_BASE                0xFF790000

typedef volatile struct gpio_reg
{
    unsigned int SWPORTA_DR;        //0x0000 Port A data register
    unsigned int SWPORTA_DDR;       //0x0004 Port A data direction register
    unsigned int RESERVED0[10];     //0x0008
    unsigned int INTEN;	            //0x0030 Interrupt enable register
    unsigned int INTMASK;           //0x0034 Interrupt mask register
    unsigned int INTTYPE_LEVEL;     //0x0038 Interrupt level register
    unsigned int INT_POLARITY;      //0x003C Interrupt polarity register
    unsigned int INT_STATUS;        //0x0040 Interrupt status of port A
    unsigned int INT_RAWSTATUS;     //0x0044 Raw Interrupt status of port A
    unsigned int DEBOUNCE;          //0x0048 Debounce enable register
    unsigned int PORTA_EOI;         //0x004c Port A clear interrupt register
    unsigned int EXT_PORTA;         //0x0050 Debounce enable register
    unsigned int RESERVED1[3];      //0x0054
    unsigned int LS_SYNC;           //0x0060 Level_sensitive synchronization enable register
} gpio_reg, *p_gpio_reg;

#define     GPIO0                   ((p_gpio_reg)GPIO0_BASE)
#define     GPIO1                   ((p_gpio_reg)GPIO1_BASE)
#define     GPIO2                   ((p_gpio_reg)GPIO2_BASE)
#define     GPIO3                   ((p_gpio_reg)GPIO3_BASE)
#define     GPIO4                   ((p_gpio_reg)GPIO4_BASE)

extern void led_mode(int mode);
extern void led_delay(void);

#endif


#ifndef   __LED_H__
#define   __LED_H__

#define    GPIO0               0xFF720000                                    
#define    GPIO0_SWPORTA_DR    (*(volatile unsigned int *)(GPIO0 + 0x04*0)) 
#define    GPIO0_SWPORTA_DDR   (*(volatile unsigned int *)(GPIO0 + 0x04*1)) 

#define    GPIO2               0xFF780000  
#define    GPIO2_SWPORTA_DR    (*(volatile unsigned int *)(GPIO2 + 0x04*0)) 
#define    GPIO2_SWPORTA_DDR   (*(volatile unsigned int *)(GPIO2 + 0x04*1)) 
//#define    GPIO2_SWPORTA_DDR  (*(volatile unsigned long *)(GPIO2 + 0x04*1)) 

extern void led_mode(int mode);

#endif



#ifndef   __UART_H__
#define   __UART_H__

#define    UART0_BASE                0xFF180000
#define    UART1_BASE                0xFF190000
#define    UART2_BASE                0xFF1A0000
#define    UART3_BASE                0xFF1B0000
#define    UART4_BASE                0xFF370000

#define    UART2_THR            	 (*(volatile unsigned int *)(UART2_BASE + 0x0000))  //Transmit Holding Register
#define    UART2_DLL            	 (*(volatile unsigned int *)(UART2_BASE + 0x0000))  //Divisor Latch (Low)
#define    UART2_DLH            	 (*(volatile unsigned int *)(UART2_BASE + 0x0004))  //Divisor Latch (High)
#define    UART2_IER            	 (*(volatile unsigned int *)(UART2_BASE + 0x0004))  //Interrupt Enable Register 
#define    UART2_LCR            	 (*(volatile unsigned int *)(UART2_BASE + 0x000C))  //Line Control Register
#define    UART2_MCR            	 (*(volatile unsigned int *)(UART2_BASE + 0x0010))  //Modem Control Register
#define    UART2_SRR            	 (*(volatile unsigned int *)(UART2_BASE + 0x0088))  //Software Reset Register
#define    UART2_USR            	 (*(volatile unsigned int *)(UART2_BASE + 0x007C))  //UART Status Register
#define    UART2_SFE            	 (*(volatile unsigned int *)(UART2_BASE + 0x0098))  //Shadow FIFO Enable
#define    UART2_SRT            	 (*(volatile unsigned int *)(UART2_BASE + 0x009C))  //Shadow RCVR Trigger
#define    UART2_STET           	 (*(volatile unsigned int *)(UART2_BASE + 0x00A0))  //Shadow TX Empty Trigger

void uart_init(void);
void rk_uart_sendbyte(unsigned char byte);
void rk_uart_sendstring(char *ptr);
void rk_uart_sendhex(unsigned int val);

#endif


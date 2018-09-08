#ifndef   __INT_H__
#define   __INT_H__


#define __stringify_1(x...)	 #x
#define __stringify(x...)	 __stringify_1(x)

#define isb()                ({asm volatile(	"isb" : : : "memory");})

/* total irq */
#define NR_GIC_IRQS          (6 * 32)
#define NR_GPIO_IRQS         (5 * 32)
#define NR_IRQS              (NR_GIC_IRQS + NR_GPIO_IRQS)


/* Interrupt ID */
#define GPIO4_INTR 		     50
#define TIMER_INTR3 		 116
#define TSADC_INT  		     129

#define I2C4_INT  		     56
#define I2C0_INT  		     57



/* irq handler struct and hander table */
struct s_irq_handler
{
    void (*m_func)(void *data);
};

static struct s_irq_handler g_irq_handler[NR_IRQS];

typedef void (interrupt_handler_t)(void *);


#define RKIO_GICD_PHYS			0xFEE00000 //GIC DIST //GIC500_BASE

//DDI0516B_gic5000_r0p0_trm.pdf
/*********************************************************************************************
* 0x00000-0x0FFFF         Distributor registers (GICD_*)
* 0x10000-0x1FFFF         Distributor registers for message-based SPIs (GICD_*)
* 0x20000-0x2FFFF         Interrupt Translation Service control registers (GITS_*)
* 0x30000-0x3FFFF         Interrupt Translation Service register (GITS_TRANSLATER)
*********************************************************************************************/

/* Distributor Registers */
typedef volatile struct gicd_reg
{
    unsigned int CTLR;      	  //0x0000
    unsigned int TYPER;    	      //0x0004
    unsigned int IIDR;      	  //0x0008
    unsigned int RESERVED0[1];    //0x000C
    unsigned int STATUSR;	      //0x0010
    unsigned int RESERVED1[11];   //0x0014
    unsigned int SETSPI_NSR;      //0x0040
    unsigned int RESERVED2[1];    //0x0044
    unsigned int CLRSPI_NSR;	  //0x0048
    unsigned int RESERVED3[1];    //0x004C
    unsigned int SETSPI_SR;       //0x0050
    unsigned int RESERVED4[1];    //0x0054
    unsigned int CLRSPI_SR;       //0x0058
    unsigned int RESERVED5[3];    //0x005C
    unsigned int SEIR;            //0x0068
    unsigned int RESERVED6[5];    //0x006C
    unsigned int IGROUPR[31];     //0x0080
    unsigned int RESERVED7[1];    //0x00FC
    unsigned int ISENABLER[32];   //0x0100
    unsigned int ICENABLER[32];   //0x0180
    unsigned int ISPENDR[32];     //0x0200
    unsigned int ICPENDR[32];     //0x0280
    unsigned int ISACTIVER[32];   //0x0300
    unsigned int ICACTIVER[32];   //0x0380
    unsigned int IPRIORITYR[256]; //0x0400
    unsigned int ITARGETSR[256];  //0x0800
    unsigned int ICFGR[64];       //0x0c00
    unsigned int IGROUPMODR[64];  //0x0d00
    unsigned int NSACR[64];       //0x0e00
    unsigned int SGIR;            //0x0f00
    unsigned int RESERVED8[3];    //0x0f04
    unsigned int CPENDSGIR[4];    //0x0f10
    unsigned int SPENDSGIR[4];    //0x0f20
    unsigned int RESERVED9[5236]; //0x0f30
    unsigned int IROUTER[1918];   //0x6100
} gicd_reg, *p_gicd;

#define GICD       ((p_gicd)RKIO_GICD_PHYS)

/* Cpu Interface System Registers */
#define ICC_IAR0_EL1		S3_0_C12_C8_0
#define ICC_IAR1_EL1		S3_0_C12_C12_0
#define ICC_EOIR0_EL1		S3_0_C12_C8_1
#define ICC_EOIR1_EL1		S3_0_C12_C12_1
#define ICC_HPPIR0_EL1		S3_0_C12_C8_2
#define ICC_HPPIR1_EL1		S3_0_C12_C12_2
#define ICC_BPR0_EL1		S3_0_C12_C8_3
#define ICC_BPR1_EL1		S3_0_C12_C12_3
#define ICC_DIR_EL1			S3_0_C12_C11_1
#define ICC_PMR_EL1			S3_0_C4_C6_0
#define ICC_RPR_EL1			S3_0_C12_C11_3
#define ICC_CTLR_EL1		S3_0_C12_C12_4
#define ICC_CTLR_EL3		S3_6_C12_C12_4
#define ICC_SRE_EL1			S3_0_C12_C12_5
#define ICC_SRE_EL2			S3_4_C12_C9_5
#define ICC_SRE_EL3			S3_6_C12_C12_5
#define ICC_IGRPEN0_EL1		S3_0_C12_C12_6
#define ICC_IGRPEN1_EL1		S3_0_C12_C12_7
#define ICC_IGRPEN1_EL3		S3_6_C12_C12_7
#define ICC_SEIEN_EL1		S3_0_C12_C13_0
#define ICC_SGI0R_EL1		S3_0_C12_C11_7
#define ICC_SGI1R_EL1		S3_0_C12_C11_5
#define ICC_ASGI1R_EL1		S3_0_C12_C11_6


extern void enable_interrupts(void);
extern void irq_install_handler(int irq, interrupt_handler_t *handler, void *data);
extern int irq_handler_enable(int irq);
extern void do_irq(void);

extern void test_timer_irq(void);

#endif


#ifndef   __GRF_H__
#define   __GRF_H__

#define    GRF_BASE                  0xFF770000

#define    GRF_GPIO4B_IOMUX    		 (*(volatile unsigned int *)(GRF_BASE + 0xe024))
#define    GRF_GPIO4C_IOMUX          (*(volatile unsigned int *)(GRF_BASE + 0xe038))

//(*(volatile unsigned int  *)(GRF_BASE + 0xe024))  o
//(*(volatile unsigned long *)(GRF_BASE + 0xe024))  x
//64-bit system: sizeof(nsigned int )=4   sizeof(nsigned int )=8
//32-bit system: sizeof(nsigned int )=4   sizeof(nsigned int )=4

#endif


#ifndef  __ADC_H__
#define  __ADC_H__

#define    TS_ADC               0xFF260000
#define    SAR_ADC              0xFF100000


//SAR_ADC
#define    SARADC_DATA                 (*(volatile unsigned int *)(SAR_ADC + 0x00))      //This register contains the data after A/D Conversion.
#define    SARADC_STAS                 (*(volatile unsigned int *)(SAR_ADC + 0x04))      //The status register of A/D Converter.
#define    SARADC_CTRL                 (*(volatile unsigned int *)(SAR_ADC + 0x08))      //The control register of A/D Converter.
#define    SARADC_DLY_PU_SOC           (*(volatile unsigned int *)(SAR_ADC + 0x0C))      //delay between power up and start command


//TS_ADC
#define    TSADC_USER_CON              (*(volatile unsigned int *)(TS_ADC + 0x00))       //The control register of A/D Converter.
#define    TSADC_AUTO_CON              (*(volatile unsigned int *)(TS_ADC + 0x04))       //TSADC auto mode control register.
#define    TSADC_INT_EN                (*(volatile unsigned int *)(TS_ADC + 0x08))       //Interrupt enable.
#define    TSADC_INT_PD                (*(volatile unsigned int *)(TS_ADC + 0x0C))       //Interrupt Status.
#define    TSADC_DATA0                 (*(volatile unsigned int *)(TS_ADC + 0x20))       //This register contains the data after A/D Conversion.
#define    TSADC_DATA1                 (*(volatile unsigned int *)(TS_ADC + 0x24))       //This register contains the data after A/D Conversion.
#define    TSADC_DATA2                 (*(volatile unsigned int *)(TS_ADC + 0x28))       //This register contains the data after A/D Conversion.
#define    TSADC_DATA3                 (*(volatile unsigned int *)(TS_ADC + 0x2C))       //This register contains the data after A/D Conversion.
#define    TSADC_COMP0_INT             (*(volatile unsigned int *)(TS_ADC + 0x30))       //TSADC high temperature level for source 0
#define    TSADC_COMP1_INT             (*(volatile unsigned int *)(TS_ADC + 0x34))       //TSADC high temperature level for source 1
#define    TSADC_COMP2_INT             (*(volatile unsigned int *)(TS_ADC + 0x38))       //TSADC high temperature level for source 2
#define    TSADC_COMP3_INT             (*(volatile unsigned int *)(TS_ADC + 0x3C))       //TSADC high temperature level for source 3
#define    TSADC_COMP0_SHUT            (*(volatile unsigned int *)(TS_ADC + 0x40))       //TSADC high temperature level for source 0 
#define    TSADC_COMP1_SHUT            (*(volatile unsigned int *)(TS_ADC + 0x44))       //TSADC high temperature level for source 1
#define    TSADC_COMP2_SHUT            (*(volatile unsigned int *)(TS_ADC + 0x48))       //TSADC high temperature level for source 2
#define    TSADC_COMP3_SHUT            (*(volatile unsigned int *)(TS_ADC + 0x4C))       //TSADC high temperature level for source 3
#define    TSADC_HIGHT_INT_DEBOUNCE    (*(volatile unsigned int *)(TS_ADC + 0x60))       //high temperature debounce
#define    TSADC_HIGHT_TSHUT_DEBOUNCE  (*(volatile unsigned int *)(TS_ADC + 0x64))       //high temperature debounce
#define    TSADC_AUTO_PERIOD           (*(volatile unsigned int *)(TS_ADC + 0x68))       //TSADC auto access period
#define    TSADC_AUTO_PERIOD_HT        (*(volatile unsigned int *)(TS_ADC + 0x6C))       //TSADC auto access period when temperature is high
#define    TTSADC_COMP0_LOW_INT        (*(volatile unsigned int *)(TS_ADC + 0x80))       //TSADC low temperature level for source 0
#define    TSADC_COMP1_LOW_INT         (*(volatile unsigned int *)(TS_ADC + 0x84))       //TSADC low temperature level for source 1


extern unsigned int get_saradc_val(unsigned char channel);
extern int get_tsadc_temp(unsigned char channel);


#endif
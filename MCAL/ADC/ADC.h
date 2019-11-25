/*
 * ADC.h
 *
 * Created: 10/11/2019 2:22:52 AM
 *  Author: moham
 */ 



#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#define ADC_EN        1 << 7
#define AD_START      1 << 6
#define AD_AUTTRIG    1 << 5
#define AD_INTFLAG    1 << 4
#define AD_INTEN      1 << 3

#define ADPRE_2       0x01
#define ADPRE_4       0x02
#define ADPRE_8       0x03
#define ADPRE_16      0x04
#define ADPRE_32      0x05
#define ADPRE_64      0x06
#define ADPRE_128     0x07

#define CH0  0x00
#define CH1  0x01
#define CH2  0x02
#define CH3  0x03
#define CH4  0x04
#define CH5  0x05
#define CH6  0x06
#define CH7  0x07

#define AREF_EN 0b11 << 6
#define AVCC_EN 0x40
#define INT_VOL 0xD0

#define LEFT_ADJ  1 << 5

#define FREERUN  0x00
#define AN_COMP  0x20
#define EXT_INT  0x40


void ADC_Init();
uint16_t ADC_Read(uint8_t Channel);


#endif /* ADC_H_ */
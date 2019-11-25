/*
 * ADC.c
 *
 * Created: 10/11/2019 2:22:33 AM
 *  Author: moham
 */ 

#include "ADC.h"
#include <stdint.h>
#include <avr/io.h>

typedef volatile uint8_t* const ADC_Type;


#define ADCMUX_REG 0x27
#define ADCSRA_REG 0x26
#define ADCH_REG   0x25
#define ADCL_REG   0x24

#define ADCMUX_SET    *((ADC_Type) ADCMUX_REG)
#define ADCSTAT_SET   *((ADC_Type) ADCSRA_REG)
#define ADCDATA_HIGH  *((ADC_Type) ADCH_REG)
#define ADCDATA_LOW   *((ADC_Type) ADCL_REG)


void ADC_Init()
{
	//ADC Enable
	ADCSTAT_SET |= ADC_EN;
	
	//Pre-scalar Value
	ADCSTAT_SET |= ADPRE_128;
	
	//Set Reference Voltage
	ADCMUX_SET |= (AVCC_EN);
	
	//Set Left-Adjust or Right-Adjust
	ADCMUX_SET &= ~(LEFT_ADJ);
	
}

uint16_t ADC_Read(uint8_t Channel)
{
	uint16_t Data = 0x00;
	//Channel Selection
	ADCMUX_SET = 0xE0;
	ADCMUX_SET |= Channel;
	
	//Start Conversion
	ADCSTAT_SET |= AD_START;
	
	//Wait until conversion is completed
	while(!(ADCSTAT_SET & AD_INTFLAG));
	
	//ADC Flag Clear
	ADCSTAT_SET |= AD_INTFLAG;
	
	if((ADCMUX_SET & LEFT_ADJ) != 1 << 5)
	{
		Data |= ADCDATA_LOW;
		Data |= ADCDATA_HIGH << 8;
	}
	else
	{
		Data |= ADCDATA_LOW >> 6;
		Data |= ADCDATA_HIGH << 2;
	}
	
	return Data;
}
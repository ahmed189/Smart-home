/*
 * timer.h
 *
 * Created: 22/11/2019 5:01:19 PM
 *  Author: moham
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Atmega32a.h"

enum WAVE_FORM_GEN
{
	NORMAL;
	CTC;
};

enum TOVFIE0
{
	TOIE0_ENABLE;
	TOIE0_DISABLE;
};

enum OCMIE0
{
	OCIE0_ENABLE;
	OCIE0_DISABLE;
};

enum TM_PRESCALAR
{
	NO_CLK_SRC = 0;
	NO_PRESCALING = 1;
	PRESCALING_CLK8 = 2;
	PRESCALING_CLK64 = 3;
	PRESCALING_CLK256 = 4;
	PRESCALING_CLK1024 = 5;
	EXT_CLK_FALLING = 6;
	EXT_CLK_RISING = 7;
};


struct STimer0_Settings
{
	enum TOVFIE0 Timer0_OVFI ;
	enum OCMIE0 Timer0_OCIE;
	enum WAVE_FORM_GEN Timer0_Mode ;
	enum TM_PRESCALAR Timer0_PRESCALAR;

};

/////////////////////Timer0 Interface


extern void TMR0_Init(struct STimer0_Settings Configuration);
extern void TMR0_ReadCounterValue(u8* u8NumOfTicks);
extern void TMR0_Set_Compare_Value(u8 u8Val);
extern void TMR0_Set_OV_Number(u8 u8Val);
extern void TMR0_Get_TOV_Number(u8 *u8Val);



/**************************TCCR0 Registers*************************************/

#define FOC0 	7
#define WGM00	6
#define COM01 	5
#define COM00	4
#define WGM01	3
#define CS02 	2
#define CS01 	1
#define CS00 	0

/**************************Enable TMR0 Pin*************************************/

#define TOIE0	0
#define OCIE0	1





#endif /* TIMER_H_ */
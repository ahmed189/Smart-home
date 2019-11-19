
#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../MCAL/Atmega32a.h"
#include "../libraries_/Typedefs.h"

#define RESET_vect                 __vector_0
#define INT0_vect                  __vector_1
#define INT1_vect                  __vector_2
#define INT2_vect                  __vector_3
#define TIMER2_COMPARE_vect        __vector_4
#define TIMER2_OVERFLOW_vect       __vector_5
#define TIMER1_Capture_Event       __vector_6
#define TIMER1A_COMPARE_vect       __vector_7
#define TIMER1B_COMPARE_vect       __vector_8
#define TIMER1_OVERFLOW_vect       __vector_9
#define TIMER0_COMPARE_vect        __vector_10
#define TIMER0_OVERFLOW_vect       __vector_11
#define SERIAL_COMPLETE_vect       __vector_12
#define USART_RX_COMPLETE_vect     __vector_13
#define USART_DATA_EMPTY_vect      __vector_14
#define USART_TX_COMPLETE_vect     __vector_15
#define ADC_CONVERSION_vect        __vector_16
#define EEPROM_READY_vect          __vector_17
#define ANALOG_COMPARATOR_vect     __vector_18
#define TWO_WIRE_SERIAL_vect       __vector_19
#define STORE_PROGRAM_MEMORY_vect  __vector_20


#define ISR(vector_no) void vector_no(void)__attribute__((signal,__INTR_ATTRS)); \
					   void vector_no(void)

typedef enum
{
	  GI_DISABLE
	, GI_ENABLE
}Global_INT_STATE;

typedef enum
{
	  LOW_LEVEL
	, ANY_LOGIC_CHANGE
	, FALLING_EDGE
	, RISING_EDGE
}INT_SENSE;

typedef enum
{
	  EXT_INT0
	, EXT_INT1
	, EXT_INT2
}EXT_INTERRUPT;

typedef enum
{
	  INT0
	, INT1
	, INT2
	, TIMER2_COMPARE
	, TIMER2_OVERFLOW
	, TIMER1_Capture
	, TIMER1A_COMPARE
	, TIMER1B_COMPARE
	, TIMER1_OVERFLOW
	, TIMER0_COMPARE
	, TIMER0_OVERFLOW
	, SERIAL_COMPLETE
	, USART_RX_COMPLETE
	, USART_DATA_EMPTY
	, USART_TX_COMPLETE
	, ADC_CONVERSION
	, EEPROM_READY
	, ANALOG_COMPARATOR
	, TWO_WIRE_SERIAL
	, STORE_PROGRAM_MEMORY
}ISR_VECTORS;

u8 Interrupt_GLOBAL(Global_INT_STATE GI_SELECT);
u8 Interrupt_EXT_INT (EXT_INTERRUPT ChannelSelect,INT_SENSE Sense_Select);











#endif /* INTERRUPT_H_ */
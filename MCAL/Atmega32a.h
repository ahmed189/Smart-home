#ifndef ATMEGA32A_H_
#define ATMEGA32A_H_

#include "../libraries_/Typedefs.h"

//*****************************************************************************
//
// GPIO registers (PORTA)
//
//*****************************************************************************
#define PORTA  *((volatile u8 * const)0x3B)
#define DDRA   *((volatile u8 * const)0x3A)
#define PINA   *((volatile u8 * const)0x39)

//*****************************************************************************
//
// GPIO registers (PORTB)
//
//*****************************************************************************
#define PORTB  *((volatile u8 * const)0x38)
#define DDRB   *((volatile u8 * const)0x37)
#define PINB   *((volatile u8 * const)0x36)

//*****************************************************************************
//
// GPIO registers (PORTC)
//
//*****************************************************************************
#define PORTC  *((volatile u8 * const)0x35)
#define DDRC   *((volatile u8 * const)0x34)
#define PINC   *((volatile u8 * const)0x33)

//*****************************************************************************
//
// GPIO registers (PORTD)
//
//*****************************************************************************
#define PORTD  *((volatile u8 * const)0x32)
#define DDRD   *((volatile u8 * const)0x31)
#define PIND   *((volatile u8 * const)0x30)

//*****************************************************************************
//
// UART registers (UART1)
//
//*****************************************************************************
#define UDR     *((volatile u8 * const)0x2C)
#define UCSRA   *((volatile u8 * const)0x2B)
#define UCSRB   *((volatile u8 * const)0x2A)
#define UBRRL   *((volatile u8 * const)0x29)

//*****************************************************************************
//
//SPI
//
//*****************************************************************************
#define SPDR  *((volatile u8 * const)0x2F)
#define SPSR  *((volatile u8 * const)0x2E)
#define SPCR  *((volatile u8 * const)0x2D)


#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE  6
#define SPIE 7

#define SPI2X 0
#define WCOL 6
#define SPIF 7

//*****************************************************************************
//
// I2C registers (I2C0 MASTER)
//
//*****************************************************************************
#define TWDR   *((volatile u8 * const)0x23)
#define TWAR   *((volatile u8 * const)0x22)
#define TWSR   *((volatile u8 * const)0x21)
#define TWBR   *((volatile u8 * const)0x20)
#define TWCR   *((volatile u8 * const)0x56)
//*****************************************************************************
//
// ADC registers and analog comparator (ADC)
//
//*****************************************************************************
#define ACSR   *((volatile u8 * const)0x28)
#define ADMUX  *((volatile u8 * const)0x27)
#define ADCSRA *((volatile u8 * const)0x26)
#define ADCH   *((volatile u8 * const)0x25)
#define ADCL   *((volatile u8 * const)0x24)

//*****************************************************************************
//
// EEPROM
//
//*****************************************************************************
#define EEARH  *((volatile u8 * const)0x3F)
#define EEARL  *((volatile u8 * const)0x3E)
#define EEDR   *((volatile u8 * const)0x3D)
#define EECR   *((volatile u8 * const)0x3C)

//*****************************************************************************
//
// Timer registers (GENERIC)
//
//*****************************************************************************
#define TIMSK *((volatile u8 * const)0x59)
#define TIFR  *((volatile u8 * const)0x58)


//*****************************************************************************
//
// Timer registers (TIMER0)
//
//*****************************************************************************
#define TCCR0  *((volatile u8 * const)0x53)
#define TCNT0  *((volatile u8 * const)0x52)
#define OCR0   *((volatile u8 * const)0x5C)

//*****************************************************************************
//
// Timer registers (TIMER1)
//
//*****************************************************************************
#define TCCR1A  *((volatile u8 * const)0x4F)
#define TCCR1B  *((volatile u8 * const)0x4E)
#define TCNT1H  *((volatile u8 * const)0x4D)
#define TCNT1L  *((volatile u8 * const)0x4C)
#define OCR1AH  *((volatile u8 * const)0x4B)
#define OCR1AL  *((volatile u8 * const)0x4A)
#define OCR1BH  *((volatile u8 * const)0x49)
#define OCR1BL  *((volatile u8 * const)0x48)
#define ICR1H   *((volatile u8 * const)0x47)
#define ICR1L   *((volatile u8 * const)0x46)

//*****************************************************************************
//
// Timer registers (TIMER2)
//
//*****************************************************************************
#define TCCR2  *((volatile u8 * const)0x45)
#define TCNT2  *((volatile u8 * const)0x44)
#define OCR2   *((volatile u8 * const)0x43)

//*****************************************************************************
//
//iNTERRUPTS
//
//*****************************************************************************
#define GICR	*((volatile u8 * const)0x5B)
#define GIFR	*((volatile u8 * const)0x5A)
#define SREG	*((volatile u8 * const)0x5F)
#define MCUCR	*((volatile u8 * const)0x55)
#define MCUCSR  *((volatile u8 * const)0x54)
#endif /* ATMEGA32A_H_ */
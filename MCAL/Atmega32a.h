#ifndef ATMEGA32A_H_
#define ATMEGA32A_H_

#include "../libraries_/Typedefs.h"

//*****************************************************************************
//
// GPIO registers (PORTA)
//
//*****************************************************************************
#define PORTA  (volatile u8 * const)(0x3B)
#define DDRA   *((volatile u8 * const)0x3A)
#define PINA   *((volatile u8 * const)0x39)

//*****************************************************************************
//
// GPIO registers (PORTB)
//
//*****************************************************************************
#define PORTB  (volatile u8 * const)(0x38)
#define DDRB   *((volatile u8 * const)0x37)
#define PINB   *((volatile u8 * const)0x36)

//*****************************************************************************
//
// GPIO registers (PORTC)
//
//*****************************************************************************
#define PORTC  (volatile u8 * const)(0x35)
#define DDRC   *((volatile u8 * const)0x34)
#define PINC   *((volatile u8 * const)0x33)

//*****************************************************************************
//
// GPIO registers (PORTD)
//
//*****************************************************************************
#define PORTD  (volatile u8 * const)(0x32)
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
#define UCSRC   *((volatile u8 * const)0x40)
#define UBRRL   *((volatile u8 * const)0x29)
#define UBRRH   *((volatile u8 * const)0x40)


//*****************************************************************************
//
//SPI
//
//*****************************************************************************
#define SPDR  *((volatile u8 * const)0x2F)
#define SPSR  *((volatile u8 * const)0x2E)
#define SPCR  *((volatile u8 * const)0x2D)


#define SPR0 (u8)0u
#define SPR1 (u8)1u
#define CPHA (u8)2u
#define CPOL (u8)3u
#define MSTR (u8)4u
#define DORD (u8)5u
#define SPE  (u8)6u
#define SPIE (u8)7u

#define SPI2X (u8)0u
#define WCOL (u8)6u
#define SPIF (u8)7u

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

//*****************************************************************************
//
// EEPROM
//
//*****************************************************************************
#define EEARH  *((volatile u8 * const)0x3F)
#define EEARL  *((volatile u8 * const)0x3E)
#define EEDR   *((volatile u8 * const)0x3D)
#define EECR   *((volatile u8 * const)0x3C)

#define EEAR   *((volatile u16 * const)0x3E)

#define EEWE	(u8)1u
#define EEMWE	(u8)2u
#define EERIE	(u8)3u


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


//*******************************************************


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

//SPECIAL FUNCTION REGISTER
#define SFIOR   *((volatile u8 * const)0x50)
#endif /* ATMEGA32A_H_ */
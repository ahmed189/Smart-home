/*
 * GPIO.c
 *
 * Created: 8/9/2018 2:25:25 PM
 *  Author: MOHAMMED-PC
 */

#include "GPIO.h"
#include <stdint.h>

typedef volatile uint8_t* const GPIO_Type; //tyoe of pointer to the registers' addresses
 
#define PORTS_NUMBER 4u
#define PINS_NUMBER  8u

/*Ports Base Addresses */
#define PORTA_BASE_ADDRESS 0x3B
#define PORTB_BASE_ADDRESS 0x38
#define PORTC_BASE_ADDRESS 0x35
#define PORTD_BASE_ADDRESS 0x32

#define SPECIAL_FUN_REG 0x50

static const uint8_t PortsBaseAddressLut[PORTS_NUMBER] =
{       PORTA_BASE_ADDRESS,
	PORTB_BASE_ADDRESS,
	PORTC_BASE_ADDRESS,
	PORTD_BASE_ADDRESS,
};

/*macros for accessing registers with defined offsets*/
#define GPIO_REG_ADDRESS(Channel_ID,offset) (PortsBaseAddressLut[Channel_ID] - offset)

/*Port Control*/
#define GPIO_WRITE(PORT_ID)  *((GPIO_Type)(GPIO_REG_ADDRESS(PORT_ID,0x00)))
#define GPIO_READ(PORT_ID)   *((GPIO_Type)(GPIO_REG_ADDRESS(PORT_ID,0x02)))
#define GPIO_DDR(PORT_ID)    *((GPIO_Type)(GPIO_REG_ADDRESS(PORT_ID,0x01)))
#define SPECFUN_REG          *((GPIO_Type)(SPECIAL_FUN_REG))

/*a function that controls the pin direction, which takes 4 parameters:
PortID, Pin Number, Direction, Enabling/Disabling Pull-up resistor */

void GPIO_DIR(uint8_t PortId, uint8_t pin, uint8_t dir,uint8_t pullup)
{
	if((PortId < PORTS_NUMBER) && (pin < PINS_NUMBER))
	{
		if (dir == INPUT)
		{
			GPIO_DDR(PortId) &= ~((1 << pin) & 0xff);

			if (pullup == PULLUP_ON)
			{
				GPIO_WRITE(PortId) |= ((1 << pin) & 0xff);
				SPECFUN_REG &= ~(1 << 2);
			}

			if (pullup == PULLUP_OFF)
			{
				GPIO_WRITE(PortId) &= ~((1 << pin) & 0xff);
				SPECFUN_REG |= (1 << 2);
			}

		}
		if (dir == OUTPUT)
		{
			GPIO_DDR(PortId) |= ((1 << pin) & 0xff);
		}
	}
}

/*a function that writes data on the selected port, which takes 3 parameters:
PortID, Pin Number, Data will be written either HIGH or LOW */

void GPIO_Write(uint8_t PortId, uint8_t pin, uint8_t data)
{
	if((PortId < PORTS_NUMBER) && (pin < PINS_NUMBER))
	{
		if (data == LOW)
		{
			GPIO_WRITE(PortId) &= ~((1 << pin) & 0xff);
		}
		if (data == HIGH)
		{
			GPIO_WRITE(PortId) |= ((1 << pin) & 0xff);
		}
	}
}

void GPIO_Port_Write(uint8_t PortId, uint8_t data)
{
	if((PortId < PORTS_NUMBER))
	{
		GPIO_WRITE(PortId) = data;
		
	}
}


/*a function that reads data from the selected port, which takes 3 parameters:
PortID, Pin Number, address of the variable where the data will be stored */

void GPIO_Read(uint8_t PortId, uint8_t pin, uint8_t *dataptr)
{
	static uint8_t pin_data;
	if((PortId < PORTS_NUMBER) && (pin < PINS_NUMBER))
	{
		pin_data = (GPIO_READ(PortId) & (1 << pin));
		if ((pin_data & 0xff) == (1 << pin))
		{
			*dataptr = 0xff;
		}
		if ((pin_data & 0xff) != (1 << pin))
		{
			*dataptr = 0x00;
		}
		
	}
}
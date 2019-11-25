/*
 * UART.c
 *
 * Created: 12/11/2019 2:10:52 PM
 *  Author: moham
 */ 
#include "Atmega32a.h"
#include "UART.h"
#include <stdint.h>

typedef volatile uint8_t* const UART_Type;

#define UART_DATA              *((UART_Type) UDR)
#define UART_CONTROL_A         *((UART_Type) UCSRA)
#define UART_CONTROL_B         *((UART_Type) UCSRB)
#define UART_CONTROL_C         *((UART_Type) UCSRC)
#define UART_BAUDRATE_LOW      *((UART_Type) UBRRL)
#define UART_BAUDRATE_HIGH     *((UART_Type) UBRRH)


void UART_Init(uint16_t Baud_Rate,uint32_t clockspeed)
{
	//Set baud rate
	uint16_t BRATE;
	BRATE = (clockspeed /(16UL*(Baud_Rate))) - 1;
	
	UART_BAUDRATE_HIGH = (BRATE >> 8);
	UART_BAUDRATE_LOW = BRATE;
	UART_CONTROL_A &= ~(UART_2XSPEED); 
	
	//Set frame format
	UART_CONTROL_C |= UREG_SELECT;
	UART_CONTROL_C &= ~(SYNC_MODE);
	UART_CONTROL_C |= DATA_BITS_8;
	UART_CONTROL_C &= ~(STOP_BIT_2);
	UART_CONTROL_C &= ~(PARITY_EN_ODD);
	
	//Enable RX & TX
	UART_CONTROL_B |= RX_ENABLE;
	UART_CONTROL_B |= TX_ENABLE;
	 
}

void UART_Send(uint8_t Data)
{
	//Wait until transmission data register is empty
	while(!(UART_CONTROL_A & (UDATA_REG_EMPTY)));
	
	UART_DATA = Data;
}

uint8_t UART_Receive()
{
	uint8_t Result;
	
	//Wait unit Reception Complete
	while(!(UART_CONTROL_A & (RX_COMPLETE)));
	
	Result = UART_DATA;
	
	return Result;
}

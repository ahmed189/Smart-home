/*
 * UART.h
 *
 * Created: 12/11/2019 2:11:13 PM
 *  Author: moham
 */ 


#ifndef UART_H_
#define UART_H_

#include "Atmega32a.h"
#include <stdint.h>

/*UART Control and Status Register A bits */
#define RX_COMPLETE        1 << 7
#define TX_COMPLETE        1 << 6
#define UDATA_REG_EMPTY    1 << 5
#define FRAME_ERROR        1 << 4
#define DATA_OVERRUN       1 << 3
#define PARITY_ERROR       1 << 2
#define UART_2XSPEED       1 << 1
#define MULPROC_MODE       1 << 0

/*UART Control and Status Register B bits */
#define RX_INT_EN          1 << 7
#define TX_INT_EN          1 << 6
#define DATAEMPTY_INTEN    1 << 5
#define RX_ENABLE          1 << 4
#define TX_ENABLE          1 << 3
#define UCHAR_SIZE2        1 << 2
#define RX_BIT_8           1 << 1
#define TX_BIT_8           1 << 0

/*UART Control and Status Register C bits */
#define UREG_SELECT        1 << 7  /*Inverting will switch to baud rate register access*/ 
#define SYNC_MODE          1 << 6  /*Inverting will switch to Asynchronous Mode*/
#define PARITY_EN_ODD      3 << 4    /*Inverting will disable parity mode*/
#define PARITY_EN_EVEN     2 << 4
#define STOP_BIT_2         1 << 3  /*Inverting will make Stop bits to 1-bit mode*/   
#define DATA_BITS_8        3 << 1  /*Inverting will switch to 5-bits mode*/
#define DATA_BITS_7        1 << 2
#define DATA_BITS_6        1 << 1
#define CLOCK_POLARITY     1 << 0   /*for synchronous mode: this will make TX O/P at Rising Edge and RX I/P at Falling Edge*/


void UART_Init(uint16_t Baud_Rate,uint32_t clockspeed);
void UART_Send(uint8_t Data);
uint8_t UART_Receive();

#endif /* UART_H_ */
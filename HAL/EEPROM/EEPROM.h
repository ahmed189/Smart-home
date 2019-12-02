#ifndef EEPROM_H_
#define EEPROM_H_

#include "../MCAL/Atmega32a.h"

/*used to initialize EEPROM_Read_Init*/
enum eeprom_interrupt_state
{
	EEPROM_READ_INT_DISABLE,
	EEPROM_READ_INT_ENABLE
}EEPROM_ENTERRUPT_STATE;

/*	Prototypes	*/
void EEPROM_Read_Init(u8 Read_Interrupt_state);
void EEPROM_Write(u16 address,u8 data);
void EEPROM_Read(u16 address,u8 *data);
void EEPROM_WAIT_WRITE(void);

#endif /* EEPROM_H_ */
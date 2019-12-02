#include "../HAL/EEPROM/EEPROM.h"
#include "../libraries_/BIT_Manepulation.h"
/****************************************************************************
 * Note if u use interrupt to enable SREG
 ****************************************************************************/
void EEPROM_Read_Init(u8 Read_Interrupt_state)
{
	switch(Read_Interrupt_state)
	{
		case EEPROM_READ_INT_DISABLE:
			CLEAR_BIT(EECR,EERIE);
			break;
		case EEPROM_READ_INT_ENABLE:
			SET_BIT(EECR,EERIE);
			break;
		default :
			break;
	}
}


/****************************************************************************
 *	Note : time for writing 8448 RC Oscillator Cycles or 8.5ms
 ****************************************************************************/
void EEPROM_Write(u16 address,u8 data)
{
	static u16 Adr = 0x00;
	if(Adr != address)
	{
		EEAR = address;
	}
	EEDR = data;
	CLEAR_BIT(EECR,EEWE);
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
}

/****************************************************************************
 *  Note : 1) When the EEPROM is read, the CPU is halted for four cycles before 
 *			  the next instruction is executed
 *			2) this method need protection because of shared resource
 ****************************************************************************/
void EEPROM_Read(u16 address,u8 *data)
{
	static u16 Adr = 0x00;
	if(Adr != address)
	{
		EEAR = address;
	}
	CLEAR_BIT(EECR,EEWE);
	SET_BIT(EECR,EEWE);
	*data = EEDR;
}

/****************************************************************************
 *	Polling for completion of previous write
 ****************************************************************************/
void EEPROM_WAIT_WRITE(void)
{
	while(GET_BIT(EECR,EEWE));
}

/**************************************************************************/
/* note : Don't forget to make the interrupt pin input + activate pullup  */
/**************************************************************************/

#include "../MCAL/Interrupt/INTERRUPT.h"
#include "../libraries_/BIT_Manepulation.h"



u8 Interrupt_GLOBAL_INIT(Global_INT_STATE GI_SELECT)
{
	u8 error = (u8)0x00;
	
	switch(GI_SELECT)
	{
		case GI_DISABLE :
			CLEAR_BIT(SREG,(u8)7);
			break;
		case GI_ENABLE :
			SET_BIT(SREG,(u8)7);
			break;
		default:
			error = (u8)0x01;
			break;
	}
	return error;
}

u8 Interrupt_EXT_INT (EXT_INTERRUPT ChannelSelect,INT_SENSE Sense_Select)
{
	u8 error = (u8)0x00;
	
	switch(ChannelSelect)
	{
		case EXT_INT0:
			SET_BIT(GICR,(u8)0x06);
			switch(Sense_Select)
			{
				case LOW_LEVEL:
					CLEAR_BIT(MCUCR,(u8)0x00);
					CLEAR_BIT(MCUCR,(u8)0x01);
				break;
				case ANY_LOGIC_CHANGE:
					SET_BIT(MCUCR,(u8)0x00);
					CLEAR_BIT(MCUCR,(u8)0x01);
					break;
				case FALLING_EDGE:
					CLEAR_BIT(MCUCR,(u8)0xx0);
					SET_BIT(MCUCR,(u8)0x01);
					break;
				case RISING_EDGE:
					SET_BIT(MCUCR,(u8)0x00);
					SET_BIT(MCUCR,(u8)0x01);
					break;
				default:
					error = (u8)0x01;
					break;
			}
			break;
			
			case EXT_INT1:
			SET_BIT(GICR,(u8)0x07);
			switch(Sense_Select)
			{
				case LOW_LEVEL:
					CLEAR_BIT(MCUCR,(u8)0x02);
					CLEAR_BIT(MCUCR,(u8)0x03);
					break;
				case ANY_LOGIC_CHANGE:
					SET_BIT(MCUCR,(u8)0x02);
					CLEAR_BIT(MCUCR,(u8)0x03);
					break;
				case FALLING_EDGE:
					CLEAR_BIT(MCUCR,(u8)0x02);
					SET_BIT(MCUCR,(u8)0x03);
					break;
				case RISING_EDGE:
					SET_BIT(MCUCR,(u8)0x02);
					SET_BIT(MCUCR,(u8)0x03);
					break;
				default:
					error = (u8)0x02;
					break;
			}		
	}
	return error;
}
#include "../MCAL/Atmega32a.h"
#include "../MCAL/GPIO/GPIO.h"


typedef volatile u8*const GPIO_Type; //type of pointer to the registers' addresses



/*Ports Base Addresses */

GPIO_Type PortsBaseAddressLut[PORTS_NUMBER] =
{
 PORTA,
 PORTB,
 PORTC,
 PORTD,
};

/*macros for accessing registers with defined offsets*/
#define GPIO_REG_ADDRESS(Channel_ID,offset) (PortsBaseAddressLut[Channel_ID] - offset)

/*Port Control*/
#define GPIO_WRITE(PORT_ID)  *((GPIO_Type)(GPIO_REG_ADDRESS(PORT_ID,0x00)))
#define GPIO_READ(PORT_ID)   *((GPIO_Type)(GPIO_REG_ADDRESS(PORT_ID,0x02)))
#define GPIO_DDR(PORT_ID)    *((GPIO_Type)(GPIO_REG_ADDRESS(PORT_ID,0x01)))
#define SPECFUN_REG          (SFIOR)

static u8 GPIO_GP_State[GPIO_GP_NUM] = {0};

/*A function to initialize all the GPIO Groups in the configurations*/
void GPIO_Init(void)
{
	u8 LoopIndex;
	u8 ErrorFlag = 0;
	const GPIO_CfgType *CfgPtr;

	for(LoopIndex = 0; (LoopIndex <GPIO_GP_NUM) && (ErrorFlag == 0); LoopIndex++)
	{
		if((GPIO_ConfigParam[LoopIndex].PortID < PORTS_NUMBER) && (GPIO_ConfigParam[LoopIndex].Pin < PINS_NUMBER))
		{
			CfgPtr = &GPIO_ConfigParam[LoopIndex];
			/*Unlock the group*/
	
			if (CfgPtr->PinMode == INPUT)
			{
				GPIO_DDR(CfgPtr->PortID) &= ~((1 << CfgPtr->Pin) & 0xff);

				if (CfgPtr->PullupON_OFF == PULLUP_ON)
				{
					GPIO_WRITE(CfgPtr->PortID) |= ((1 << CfgPtr->Pin) & 0xff);
					SPECFUN_REG &= ~(1 << 2);
				}

				if (CfgPtr->PullupON_OFF == PULLUP_OFF)
				{
					GPIO_WRITE(CfgPtr->PortID) &= ~((1 << CfgPtr->Pin) & 0xff);
					SPECFUN_REG |= (1 << 2);
				}

			}
			if (CfgPtr->PinMode == OUTPUT)
			{
				GPIO_DDR(CfgPtr->PortID) |= ((1 << CfgPtr->Pin) & 0xff);
			}
			
			GPIO_GP_State[LoopIndex] = 1;
		}
		else
		{
			ErrorFlag = 1;
		}
	}
}

/*A function to Digital Write data to a specific group*/
void GPIO_Write(u8 GroupId,u8 GroupData)
{
	const GPIO_CfgType *CfgWrite;

	if (( GroupId < GPIO_GP_NUM))
	{
		CfgWrite = &GPIO_ConfigParam[GroupId];
		
		if ((CfgWrite->PinMode == OUTPUT) && (GPIO_GP_State[GroupId] == 1))
		{
			if (GroupData == LOW)
			{
				GPIO_WRITE(CfgWrite->PortID) &= ~((1 << CfgWrite->Pin) & 0xff);
			}
			if (GroupData == HIGH)
			{
				GPIO_WRITE(CfgWrite->PortID) |= ((1 << CfgWrite->Pin) & 0xff);
			}
	    }

	}
}




/*A function to Digital read data from a specific group*/
void GPIO_Read(u8 GroupId,u8* GroupDataPtr)
{
	const GPIO_CfgType * CfgRead;
	if (( GroupId < GPIO_GP_NUM))
	{

		CfgRead =  &GPIO_ConfigParam[GroupId];

		if((CfgRead->PinMode == INPUT) && (GPIO_GP_State[GroupId] == 1))
		{

			*GroupDataPtr = (GPIO_READ(CfgRead->PortID) & (1 << CfgRead->Pin));
			if ((*GroupDataPtr & 0xff) == (1 << CfgRead->Pin))
			{
				*GroupDataPtr = 0xff;
			}
			if ((*GroupDataPtr & 0xff) != (1 << CfgRead->Pin))
			{
				*GroupDataPtr = 0x00;
			}

		}
		
	}
	
}




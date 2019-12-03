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



/*A function to initialize all the GPIO Groups in the configurations*/
void GPIO_Init(void)
{
	u8 LoopIndex;
	u8 ErrorFlag = 0;
	const GPIO_CfgType *CfgPtr;
	

	/*loop through groups*/
	for(LoopIndex = 0 ; (LoopIndex < GPIO_GP_NUM && ErrorFlag == 0) ; LoopIndex++)
	{
		if(GPIO_ConfigParam[LoopIndex].PortID < PORTS_NUMBER)
		{
			CfgPtr = &GPIO_ConfigParam[LoopIndex];
			
			/*initializing the port to make all bits Anded with the mask*/
			GPIO_DDR(CfgPtr->PortID) &=~(CfgPtr->Mask);
			
			/*Put the group direction in it's register*/
			GPIO_DDR(CfgPtr->PortID) |= (CfgPtr->Direction)&(CfgPtr->Mask);

			/*initializing the port to make all bits Anded with the mask*/
			GPIO_WRITE(CfgPtr->PortID)&=~(CfgPtr->Mask);
			
			/*Put the group Pull up data in it's register*/
			GPIO_WRITE(CfgPtr->PortID)|=~(CfgPtr->Direction)&(CfgPtr->Mask)&(CfgPtr->PullupON_OFF);
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
	//u8 ErrorFlag = 0;
	
	if ( GroupId < GPIO_GP_NUM )
	{
		CfgWrite = &GPIO_ConfigParam[GroupId];
		
		/*save the value or port in another variable to work on it regards the original port*/
		u8 portcopy = GPIO_WRITE(CfgWrite->PortID);
		
		/*initializing the port to make all bits Anded with the mask*/
		portcopy &=~(CfgWrite->Mask);
		
		/*save the data in the variable*/
		portcopy |= GroupData & CfgWrite->Mask & CfgWrite->Direction;
		
		/*save data in original register*/
		GPIO_WRITE(CfgWrite->PortID) = portcopy;
	}
	else
	{
		//ErrorFlag = 1;
	}
}




/*A function to Digital read data from a specific group*/
void GPIO_Read(u8 GroupId,u8* GroupDataPtr)
{
	const GPIO_CfgType * CfgRead;
	if (( GroupId < GPIO_GP_NUM ))
	{

		CfgRead =  &GPIO_ConfigParam[GroupId];
		
		/*check if direction is input*/
		if(CfgRead->Direction == INPUT)
		{
			/*get the data from the pin register*/
			*GroupDataPtr = GPIO_READ(CfgRead->PortID) & CfgRead->Mask;
		}
		else;
		
	}
	
}




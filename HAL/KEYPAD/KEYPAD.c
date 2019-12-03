#include "../HAL/KEYPAD/KEYPAD.h"
#include "../MCAL/Atmega32a.h"
static u8 Rows = (u8)4;
static u8 Columns = (u8)4;

/*Matrix Configurable Depend on connection*/
const u8 Keypad_Arr[4][4] =
{
	{0x01 , 0x02 , 0x03 , 0x0A},
	{0x04 , 0x05 , 0x06 , 0x0B},
	{0x07 , 0x08 , 0x09 , 0x0C},
	{0x0E , 0x00 , 0x0F , 0x0D}
};

u8 Get_num_Keypad(void)
{
	u8 num1,num2;
	u8 save = NOTPRESSED;
	/*Activate Keypad*/
	//GPIO_Write(Keypad_Group_ID,(u8)(0x0F));
	*PORTB = 0x0f;
	/*Check Rows*/
	for(num1 = (u8)0 ; num1 < Rows ; num1++)
	{
		//GPIO_Write(Keypad_Group_ID,(u8)( ((~(1 << num1))&0x0F)) );
		*PORTB = ((~(1 << num1))&0x0F);
		
		/*Check Columns*/
		for(num2 = (u8)0 ; num2 < Columns ; num2++)
		{
			//if(!((GPIO_Read(Keypad_Group_ID)>>(u8)4) & ((u8)1 << num2)))
			if(!((*PORTB>>(u8)4) & ((u8)1 << num2)))
			{
				
				
				save = Keypad_Arr[num1][num2];

				/*Wait for press to finish*/
				//while(!((GPIO_Read(Keypad_Group_ID)>>(u8)4) & ((u8)1 << num2)));
				
				
				break;
			}
			else;
		}
	}
	/*Deactivate Keypad*/
	//GPIO_Write(Keypad_Group_ID,(u8)(0x00));
	*PORTB = 0x00;
	return save;
}

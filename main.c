#include "../libraries_/Typedefs.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../HAL/KEYPAD/KEYPAD.h"
#include "../MCAL/Atmega32a.h"
#define  F_CPU 1000000UL
#include <util/delay.h>


int main(void)
{
	GPIO_Init();
	
	//u8 i =0;
    while (1) 
    {
		//i =0;
		//for(i = 0 ; i  < 4 ;i++)
		//	*PORTB = Get_num_Keypad();
		GPIO_Write(group_test,0x00);
		_delay_ms(500);
		GPIO_Write(group_test,0x0f);
		_delay_ms(500);


    }
}


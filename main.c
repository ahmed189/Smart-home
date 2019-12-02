#include "../libraries_/Typedefs.h"
#include "../MCAL/GPIO/GPIO.h"

#define  F_CPU 1000000UL
#include <util/delay.h>


int main(void)
{
	GPIO_Init();
	
    while (1) 
    {
		GPIO_Write(group_test,0x00);
		_delay_ms(1000);
		GPIO_Write(group_test,0xff);
		_delay_ms(1000);
    }
}


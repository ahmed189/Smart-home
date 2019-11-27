#include "../libraries_/Typedefs.h"
#include "../MCAL/SPI/SPI.h"
#include "GPIO/GPIO.h"

#define  F_CPU 1000000UL
#include <util/delay.h>


int main(void)
{
	GPIO_Init();
	
    while (1) 
    {
		GPIO_Write(0,0x00);
		
    }
}


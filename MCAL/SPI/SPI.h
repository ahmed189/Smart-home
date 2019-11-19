#ifndef SPI_H_
#define SPI_H_

#include "../MCAL/Atmega32a.h"

enum SPI_Enable{
	SPI_Enable_OFF,
	SPI_Enable_ON
};

enum SPI_Interrupt_Enable{
	SPI_INTERRUPT_OFF,
	SPI_INTERRUPT_ON
};

enum SPI_Type{
	SPI_Slave,
	SPI_Master
};

enum SPI_Mode{
	SPI_Mode0,
	SPI_Mode1,
	SPI_Mode2,
	SPI_Mode3
};

enum SPI_Prescalar{
	SPI_Fosc4,
	SPI_Fosc16,
	SPI_Fosc64,
	SPI_Fosc128,
	Nothing
};

enum SPI_Double_Speed{
	SPI_Double_Speed_OFF,
	SPI_Double_Speed_ON
};

enum SPI_Data_Order{
	SPI_MSB,
	SPI_LSB
};

typedef struct{
	enum SPI_Enable Enable;
	enum SPI_Interrupt_Enable Enable_Interrupt;
	enum SPI_Type Type;
	enum SPI_Mode Mode;
	enum SPI_Prescalar Prescalar;
	enum SPI_Double_Speed Double_Speed;
	enum SPI_Data_Order Data_Order;
}SPI_Configuration;


/*Prototypes _ SPI*/
void SPI_Init(void);
void SPI_Data_Write(u8 Data);
u8 SPI_Data_Read(void);



#endif /* SPI_H_ */
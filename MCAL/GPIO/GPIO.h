#ifndef GPIO_H
#define GPIO_H

#include "../libraries_/Typedefs.h"
#include "../MCAL/GPIO/GPIO_Cfg.h"

#define PORTS_NUMBER 4u
#define PINS_NUMBER  8u

#define INPUT  0
#define OUTPUT 1

#define HIGH 0xff
#define LOW  0x00

#define A 0
#define B 1
#define C 2
#define D 3

#define PULLUP_ON  0
#define PULLUP_OFF 1

#define DIGITAL 0
#define ANALOG  1

typedef struct
{
	u8 PortID;
	u8 Pin;
	u8 PinMode;
	u8 PullupON_OFF;
	u8 D_A;
	
}GPIO_CfgType;

extern const GPIO_CfgType GPIO_ConfigParam [GPIO_GP_NUM];
void GPIO_Init(void);
void GPIO_Write(u8 GroupId,u8 GroupData);
void GPIO_Read(u8 GroupId,u8* GroupDataPtr);

#endif

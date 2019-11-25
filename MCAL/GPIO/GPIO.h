
/*
 * Demery_GPIO.h
 *
 * Created: 8/9/2018 2:25:46 PM
 *  Author: MOHAMMED-PC
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

#define INPUT 0
#define OUTPUT 1

#define HIGH 0xff
#define LOW 0x00

#define A 0
#define B 1
#define C 2
#define D 3

#define PULLUP_ON 0
#define PULLUP_OFF 1

//void GPIO_DIR(uint8_t PortId, uint8_t pin, uint8_t dir)
void GPIO_DIR(uint8_t PortId, uint8_t pin, uint8_t dir,uint8_t pullup);
void GPIO_Write(uint8_t PortId, uint8_t pin, uint8_t data);
void GPIO_Port_Write(uint8_t PortId, uint8_t data);
void GPIO_Read(uint8_t PortId, uint8_t pin, uint8_t *dataptr);



#endif /* DEMERY_GPIO_H_ */
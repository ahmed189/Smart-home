#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/GPIO/GPIO_Cfg.h"

/*PortID - Mask - Direction - PullupON_OFF - Digital or analog;*/
const GPIO_CfgType GPIO_ConfigParam [GPIO_GP_NUM] =
{
	{
			B,0x0f,0x0f,0x00,DIGITAL
	}
};

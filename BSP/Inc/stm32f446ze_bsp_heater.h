#ifndef INC_STM32F446ZE_BSP_HEATER_H_
#define INC_STM32F446ZE_BSP_HEATER_H_

#include "main.h"
#include "heater.h"
#include "stm32f4xx_hal.h"

typedef struct
{
	HeaterIntfc		Intfc;
    GPIO_TypeDef    *GPIOx;
    uint16_t	    GPIOPin;
} STM32F446ZEBspHeater;


void STM32F446ZEHeaterInit(HeaterStruct *pHtr, void *Priv);
void STM32F446ZEHeaterOn(HeaterStruct *pHtr);
void STM32F446ZEHeaterOff(HeaterStruct *pHtr);

#endif /* INC_STM32F446ZE_BSP_HEATER_H_ */

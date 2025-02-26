#ifndef INC_STM32F446ZE_BSP_LED_H_
#define INC_STM32F446ZE_BSP_LED_H_

#include "main.h"
#include "led.h"
#include "stm32f4xx_hal.h"

typedef struct
{
	LedIntfc		Intfc;
    GPIO_TypeDef    *GPIOx;
    uint16_t	    GPIOPin;
} STM32F446ZEBspLed;


void STM32F446ZELedInit(LedStruct *pLed, void *Priv);
void STM32F446ZELedOn(LedStruct *pLed);
void STM32F446ZELedOff(LedStruct *pLed);


#endif /* INC_STM32F446ZE_BSP_LED_H_ */

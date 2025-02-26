
#ifndef INC_STM32F446ZE_BSP_BUTTON_H_
#define INC_STM32F446ZE_BSP_BUTTON_H_

#include "button.h"
#include "gpio.h"
#include "stm32f4xx_hal.h"

typedef struct
{
	ButtonIntfc		Intfc;
    GPIO_TypeDef    *GPIOx;
    uint16_t	    GPIOPin;
    uint8_t         IdleVal;
} STM32F446ZEBspButton;


void STM32F446ZEButtonInit(ButtonState *pBtn, void *Priv);
uint8_t STM32F446ZEButtonGetVal(ButtonState *pBtn);

#endif /* INC_STM32F446ZE_BSP_BUTTON_H_ */

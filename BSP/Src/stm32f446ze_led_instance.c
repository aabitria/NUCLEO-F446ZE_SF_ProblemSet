#include "led.h"
#include "stm32f446ze_bsp_led.h"

STM32F446ZEBspLed StatLed =
{
	.Intfc =
	{
		.Init = STM32F446ZELedInit,
	},
	.GPIOx = ST_LED_GPIO_Port,
	.GPIOPin = ST_LED_Pin,
};

LedIntfc *pLedIntfc = (LedIntfc *)&StatLed;

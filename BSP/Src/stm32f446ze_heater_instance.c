#include "heater.h"
#include "stm32f446ze_bsp_heater.h"

STM32F446ZEBspHeater Htr =
{
	.Intfc =
	{
		.Init = STM32F446ZEHeaterInit,
	},
	.GPIOx = HEATER_GPIO_Port,
	.GPIOPin = HEATER_Pin,
};

HeaterIntfc *pHtrIntfc = (HeaterIntfc *)&Htr;

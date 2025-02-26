#include "button.h"
#include "gpio.h"
#include "stm32f446ze_bsp_button.h"

STM32F446ZEBspButton Stm32Up =
{
	.Intfc =
	{
		.Init = STM32F446ZEButtonInit,
	},
	.GPIOx = KEY_UP_GPIO_Port,
	.GPIOPin = KEY_UP_Pin,
	.IdleVal = 1,
};

STM32F446ZEBspButton Stm32Down =
{
	.Intfc =
	{
		.Init = STM32F446ZEButtonInit,
	},
	.GPIOx = KEY_DN_GPIO_Port,
	.GPIOPin = KEY_DN_Pin,
	.IdleVal = 1,
};

ButtonIntfc *Up = (ButtonIntfc *)&Stm32Up;
ButtonIntfc *Down = (ButtonIntfc *)&Stm32Down;


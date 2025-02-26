#include "stm32f446ze_bsp_heater.h"

void STM32F446ZEHeaterInit(HeaterStruct *pHtr, void *Priv)
{
	pHtr->Private = Priv;
	pHtr->On = STM32F446ZEHeaterOn;
	pHtr->Off = STM32F446ZEHeaterOff;
}


void STM32F446ZEHeaterOn(HeaterStruct *pHtr)
{
	STM32F446ZEBspHeater *pStm32Htr = (STM32F446ZEBspHeater *)pHtr->Private;
	HAL_GPIO_WritePin(pStm32Htr->GPIOx, pStm32Htr->GPIOPin, GPIO_PIN_SET);
}


void STM32F446ZEHeaterOff(HeaterStruct *pHtr)
{
	STM32F446ZEBspHeater *pStm32Htr = (STM32F446ZEBspHeater *)pHtr->Private;
	HAL_GPIO_WritePin(pStm32Htr->GPIOx, pStm32Htr->GPIOPin, GPIO_PIN_RESET);
}


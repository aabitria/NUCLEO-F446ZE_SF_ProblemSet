#include "stm32f446ze_bsp_led.h"

void STM32F446ZELedInit(LedStruct *pLed, void *Priv)
{
	pLed->Private = Priv;
	pLed->On = STM32F446ZELedOn;
	pLed->Off = STM32F446ZELedOff;
}

void STM32F446ZELedOn(LedStruct *pLed)
{
	STM32F446ZEBspLed *pStm32Led = (STM32F446ZEBspLed *)pLed->Private;
	HAL_GPIO_WritePin(pStm32Led->GPIOx, pStm32Led->GPIOPin, GPIO_PIN_SET);
}

void STM32F446ZELedOff(LedStruct *pLed)
{
	STM32F446ZEBspLed *pStm32Led = (STM32F446ZEBspLed *)pLed->Private;
	HAL_GPIO_WritePin(pStm32Led->GPIOx, pStm32Led->GPIOPin, GPIO_PIN_RESET);
}

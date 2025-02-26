#include "stm32f446ze_bsp_button.h"

void STM32F446ZEButtonInit(ButtonState *pBtn, void *Priv)
{
	STM32F446ZEBspButton *pStm32Btn = (STM32F446ZEBspButton *)Priv;

	pBtn->Private = pStm32Btn;
	pBtn->GetVal = STM32F446ZEButtonGetVal;

	if (pStm32Btn->IdleVal)
	{
		pStm32Btn->IdleVal = 1;		// force idleval to be 1 if non-zero
	}

	pBtn->IdleVal = pStm32Btn->IdleVal;
	if (pBtn->IdleVal == 0)			// Idle = 0
	{
		pBtn->ActiveVal = 1;
	}
	else							// Idle = 1
	{
		pBtn->ActiveVal = 0;
	}

	return;
}


uint8_t STM32F446ZEButtonGetVal(ButtonState *pBtn)
{
	STM32F446ZEBspButton *pStm32Btn = (STM32F446ZEBspButton *)pBtn->Private;

	return HAL_GPIO_ReadPin(pStm32Btn->GPIOx, pStm32Btn->GPIOPin);
}

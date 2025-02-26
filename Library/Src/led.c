#include "led.h"

void LedInit(LedStruct *pLed, void *Priv)
{
	LedIntfc *Intfc = (LedIntfc *)Priv;

	if (Intfc->Init)
	{
		Intfc->Init(pLed, Priv);
	}

	pLed->LedState = 0;
	pLed->LedInit = 1;
}

void LedOn(LedStruct *pLed)
{
	pLed->On(pLed);
	pLed->LedState = 1;
}

void LedOff(LedStruct *pLed)
{
	pLed->Off(pLed);
	pLed->LedState = 0;
}

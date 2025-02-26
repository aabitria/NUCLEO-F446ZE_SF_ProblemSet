#include "heater.h"



void HeaterInit(HeaterStruct *pHtr, void *Priv)
{
	HeaterIntfc *Intfc = (HeaterIntfc *)Priv;

	if (Intfc->Init)
	{
		Intfc->Init(pHtr, Priv);
	}
}

void HeaterOn(HeaterStruct *pHtr)
{
    pHtr->On(pHtr);
}

void HeaterOff(HeaterStruct *pHtr)
{
    pHtr->Off(pHtr);
}

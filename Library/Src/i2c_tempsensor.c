#include "i2c_tempsensor.h"

int I2cTempSenseInit(I2cTempSenseStruct *pTsense, void *Priv)
{
	I2cTempSenseIntfc *Intfc = (I2cTempSenseIntfc *)Priv;
	int Stat = 1;

	if (Intfc->Init)
	{
		Stat = Intfc->Init(pTsense, Priv);
	}

    return Stat;
}


void I2cTempSenseReadTemp(I2cTempSenseStruct *pTsense)
{
    pTsense->ReadTemp(pTsense, pTsense->Buff, sizeof(pTsense->Buff));
}

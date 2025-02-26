#include "i2c_tempsensor.h"
#include "stm32f446ze_bsp_i2c_temp.h"

STM32F446ZEBspI2cTempSense I2cTemp =
{
	.Intfc =
	{
		.Init = STM32F446ZEI2cTempSenseInit,
	},
	.I2CHandle = &hi2c2,
	.SlaveAddr = I2C_TEMP_SENSE_ADDR,
};

I2cTempSenseIntfc *pI2cTemp = (I2cTempSenseIntfc *)&I2cTemp;

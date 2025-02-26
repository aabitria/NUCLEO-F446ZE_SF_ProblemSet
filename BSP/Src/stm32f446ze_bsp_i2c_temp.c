#include "stm32f446ze_bsp_i2c_temp.h"

#define TEMP_REG_ADDR				(0x0)


int STM32F446ZEI2cTempSenseInit(I2cTempSenseStruct *pTs, void *Priv)
{
    pTs->Private = Priv;
    pTs->ReadTemp = STM32F446ZEI2cTempSenseGetVal;

    return 1;
}


void STM32F446ZEI2cTempSenseGetVal(I2cTempSenseStruct *pTs, uint8_t *Buff, uint16_t BufLen)
{
	STM32F446ZEBspI2cTempSense *pI2C = (STM32F446ZEBspI2cTempSense *)pTs->Private;

    HAL_I2C_Mem_Read(pI2C->I2CHandle,
    		         (pI2C->SlaveAddr << 1),
					 TEMP_REG_ADDR,
					 1,
					 Buff,
					 BufLen,
					 2);
    return;
}

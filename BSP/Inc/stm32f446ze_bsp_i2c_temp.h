#ifndef INC_STM32F446ZE_BSP_I2C_TEMP_H_
#define INC_STM32F446ZE_BSP_I2C_TEMP_H_

#include "i2c_tempsensor.h"
#include "stm32f4xx_hal.h"
#include "i2c.h"


#define I2C_TEMP_SENSE_ADDR				(0x60)

typedef struct
{
	I2cTempSenseIntfc		Intfc;
    I2C_HandleTypeDef       *I2CHandle;
    uint8_t         		SlaveAddr;
} STM32F446ZEBspI2cTempSense;


int STM32F446ZEI2cTempSenseInit(I2cTempSenseStruct *pTs, void *Priv);
void STM32F446ZEI2cTempSenseGetVal(I2cTempSenseStruct *pTs, uint8_t *Buff, uint16_t BufLen);


#endif /* INC_STM32F446ZE_BSP_I2C_TEMP_H_ */

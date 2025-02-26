#ifndef INC_I2C_TEMPSENSOR_H_
#define INC_I2C_TEMPSENSOR_H_

#include <stdint.h>

#define I2C_TEMPSENSE_BUFF_BYTE_LEN			(2)

typedef struct I2cTempSense
{
	void 		*Private;
	uint8_t     Buff[I2C_TEMPSENSE_BUFF_BYTE_LEN];
	void        (*ReadTemp)(struct I2cTempSense *pTSense, uint8_t *pBuff, uint16_t BufLen);
} I2cTempSenseStruct;


typedef struct
{
    int			(*Init)(I2cTempSenseStruct *pTsense, void *Priv);
} I2cTempSenseIntfc;


int I2cTempSenseInit(I2cTempSenseStruct *pTsense, void *Priv);
void I2cTempSenseReadTemp(I2cTempSenseStruct *pTsense);


#endif /* INC_I2C_TEMPSENSOR_H_ */

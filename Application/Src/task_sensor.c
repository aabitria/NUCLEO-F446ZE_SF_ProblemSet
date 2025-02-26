#include "FreeRTOS.h"
#include "queue.h"
#include "tasks.h"
#include "i2c_tempsensor.h"

#define TASK_SENSOR_FREQ_MS			(50)

typedef struct
{
	int32_t 	TempAvg;
	int32_t 	TempBuffer[TEMP_FILT_BUFFER_LEN];
	uint8_t 	WrIdx;
	uint8_t 	InitFlag;
	uint16_t 	NumRuns;
} SensorReadStruct;

extern I2cTempSenseIntfc *pI2cTemp;
extern xQueueHandle xTempMeasuredQueue;

void SensorFilter(SensorReadStruct *pvTemp, int32_t TempVal)
{
	int32_t Sum;

	pvTemp->TempBuffer[pvTemp->WrIdx] = TempVal;
	++pvTemp->WrIdx;
	pvTemp->WrIdx %= TEMP_FILT_BUFFER_LEN;

	if (pvTemp->InitFlag == 0) {
		pvTemp->TempAvg = TempVal;
		pvTemp->NumRuns++;

		if (pvTemp->NumRuns >= TEMP_FILT_BUFFER_LEN)
		{
			pvTemp->InitFlag = 1;
		}
		return;
	}

	Sum = 0;
	for (int i = 0; i < TEMP_FILT_BUFFER_LEN; i++) {
		Sum += pvTemp->TempBuffer[i];
	}

	pvTemp->TempAvg = (Sum >> TEMP_FILT_BUFFER_LEN_LOG2) / 10;
	return;
}


void StartSensorReadTask(void * argument)
{
	SensorReadStruct Temp = {0};
	I2cTempSenseStruct I2cTs;
	int32_t Value = 0;
	uint16_t TempRaw;
	int Ret;

	Ret = I2cTempSenseInit(&I2cTs, (void *)pI2cTemp);
	if (Ret == 0)
	{
		while(1);
	}

	for(;;)
	{
		I2cTempSenseReadTemp(&I2cTs);
		TempRaw = ((uint16_t)I2cTs.Buff[1] << 8) | (uint16_t)I2cTs.Buff[0];  // move to i2c_temp driver
		Value = (int16_t)TempRaw;

		SensorFilter(&Temp, Value);

		if (Temp.TempAvg < TEMP_LIMIT_MIN)
		{
			Temp.TempAvg = TEMP_LIMIT_MIN;
		}

		if (Temp.TempAvg > TEMP_LIMIT_MAX)
		{
			Temp.TempAvg = TEMP_LIMIT_MAX;
		}

		(void)xQueueSend(xTempMeasuredQueue, &Temp.TempAvg, 0);

		vTaskDelay(pdMS_TO_TICKS(TASK_SENSOR_FREQ_MS));
	}
}


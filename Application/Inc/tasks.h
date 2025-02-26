#ifndef INC_TASKS_H_
#define INC_TASKS_H_

#include "FreeRTOS.h"
#include "task.h"

#define TEMP_LIMIT_MIN						(160)
#define TEMP_LIMIT_MAX						(300)
#define TEMP_SETPT_CHANGE_PER_STEP			(5)
#define TEMP_FILT_BUFFER_LEN				(16)
#define TEMP_FILT_BUFFER_LEN_LOG2			(4)

typedef struct
{
	int16_t	TempMeas;
	int16_t TempSetpoint;
	uint8_t HeaterStatus;
} TempData;


void StartSensorReadTask(void * argument);
void StartControlTask(void * argument);
void StartSetpointTask(void * argument);
void StartLoggerTask(void *argument);

#endif /* INC_TASKS_H_ */

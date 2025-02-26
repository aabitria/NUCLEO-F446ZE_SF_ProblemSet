#include "FreeRTOS.h"
#include "queue.h"
#include "tasks.h"
#include "heater.h"

#define TASK_CONTROL_FREQ_MS		(50)

extern xQueueHandle xTempMeasuredQueue;
extern xQueueHandle xSetpointDataQueue;
extern xQueueHandle xTempDataQueue;
extern HeaterIntfc *pHtrIntfc;

void StartControlTask(void * argument)
{
	TempData Temp;
	HeaterStruct Heater;

	Temp.TempMeas = 270;
	Temp.TempSetpoint = 200;
	Temp.HeaterStatus = 0;

    HeaterInit(&Heater, pHtrIntfc);

	/* Infinite loop */
	for(;;)
	{
		(void)xQueueReceive(xSetpointDataQueue, &Temp.TempSetpoint, 0);

		(void)xQueueReceive(xTempMeasuredQueue, &Temp.TempMeas, 0);

		if (Temp.TempMeas < Temp.TempSetpoint)
		{
			// Turn on heater
			HeaterOn(&Heater);
			Temp.HeaterStatus = 1;
		}
		else
		{
			// Turn off heater
			HeaterOff(&Heater);
			Temp.HeaterStatus = 0;
		}

		(void)xQueueSend(xTempDataQueue, &Temp, 0);

		vTaskDelay(pdMS_TO_TICKS(TASK_CONTROL_FREQ_MS));
	}
}

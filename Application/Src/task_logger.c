#include "FreeRTOS.h"
#include "queue.h"
#include "tasks.h"
#include <stdio.h>
#include <string.h>
#include "log.h"

extern xQueueHandle xLoggerQueue;
extern LogIntfc *pLogIntfc;

void StartLoggerTask(void *argument)
{
	TempData Tmp = {0};
	LogStruct Log = {0};
	char buffer[64] = {0};

	LogInit(&Log, (void *)pLogIntfc);

	for(;;)
	{
		// If no new data, don't run and keep on sleeping until data update
		// arrives, which only happens every minute.
        xQueueReceive(xLoggerQueue, &Tmp, portMAX_DELAY);

		sprintf(buffer, "\rActual(degC): %d.%d; Target(degC): %d.%d; Heater: %s\n",
				(Tmp.TempMeas / 10),
				(Tmp.TempMeas % 10),
				(Tmp.TempSetpoint / 10),
				(Tmp.TempSetpoint % 10),
				(Tmp.HeaterStatus != 0) ? "ON" : "OFF");

		LogWrite(&Log, buffer);
		LogSend(&Log);

	}
}


#include "timer_svc.h"
#include "queue.h"
#include "led.h"
#include "tasks.h"

#define TIMER_LED_FREQ				(50)
#define TASK_LOGGER_WAKE_CNT_1MIN	((1000 / TIMER_LED_FREQ) * 60)
#define TIMER_BLINK_CNTR			(10)

LedStruct Led;
extern LedIntfc *pLedIntfc;
extern xQueueHandle xLoggerQueue;
extern xQueueHandle xTempDataQueue;

void TimerLedCallback ( TimerHandle_t xTimer )
{
	TempData TempTimer;
	static uint16_t MinuteCtr = 0;
	static uint16_t BlnkCtr = 0;

	if (Led.LedInit == 0)
	{
		LedInit(&Led, pLedIntfc);
	}

	// Update it's own record of temp and heater status
	(void)xQueueReceive(xTempDataQueue, &TempTimer, 0);

	if (TempTimer.HeaterStatus)
	{
		LedOn(&Led);
	}
	else
	{
		++BlnkCtr;
		if (BlnkCtr >= TIMER_BLINK_CNTR)
		{
			if (Led.LedState == 1)
			{
				LedOff(&Led);
			}
			else
			{
				LedOn(&Led);
			}

			BlnkCtr = 0;
		}
	}

	// How many 50ms intervals within a minute? - 1200
	++MinuteCtr;
	if (MinuteCtr >= TASK_LOGGER_WAKE_CNT_1MIN)
	{
		// send the logs
		// reset the MinuteCtr;
		MinuteCtr = 0;

		// Because this is inside timer, it cannot sleep.
        (void)xQueueSend(xLoggerQueue, &TempTimer, 0);
	}
}


#include "FreeRTOS.h"
#include "queue.h"
#include "tasks.h"
#include "button.h"

#define TASK_SETPOINT_FREQ_MS		(25)
#define SETPOINT_DFLT_10TH_DEGC		(200)
#define COUNTER_50MS				(50 / TASK_SETPOINT_FREQ_MS)
// How many runs of this task to get 50ms?

extern xQueueHandle xSetpointDataQueue;
extern ButtonIntfc *Up;
extern ButtonIntfc *Down;

void StartSetpointTask(void * argument)
{
	uint8_t counter = 0;
	int16_t TempSetpoint = SETPOINT_DFLT_10TH_DEGC;   // 20.0 degrees celsius
	ButtonState TempUp, TempDown;

	button_init(&TempUp, (void *)Up);   // move to button driver
	button_init(&TempDown, (void *)Down); // this too

	for(;;)
	{
		if (button_detect_press_event(&TempUp))
		{
		    TempSetpoint += TEMP_SETPT_CHANGE_PER_STEP;
		}

		if (button_detect_press_event(&TempDown))
		{
		    TempSetpoint -= TEMP_SETPT_CHANGE_PER_STEP;
		}

		if (TempSetpoint > TEMP_LIMIT_MAX)
		{
		    TempSetpoint = TEMP_LIMIT_MAX;
		}

		if (TempSetpoint < TEMP_LIMIT_MIN)
		{
		    TempSetpoint = TEMP_LIMIT_MIN;
		}

		// Send the setpoint data every 50ms, same frequency as control task.
		// to ensure that each send will be consumed.
		++counter;
		if (counter >= COUNTER_50MS)
		{
			(void)xQueueSend(xSetpointDataQueue, &TempSetpoint, 0);
			counter = 0;
		}

		vTaskDelay(pdMS_TO_TICKS(TASK_SETPOINT_FREQ_MS));
	}
}

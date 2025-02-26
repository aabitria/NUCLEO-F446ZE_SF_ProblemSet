/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
//#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include "tasks.h"
#include "timer_svc.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

// Timer svc
#define TIMER_LED_FREQ_MS			(50)

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
TaskHandle_t xSensorReadHandle = NULL;
TaskHandle_t xControlHandle = NULL;
TaskHandle_t xSetpointHandle = NULL;
TaskHandle_t xLoggerHandle = NULL;

xQueueHandle xTempMeasuredQueue;
xQueueHandle xSetpointDataQueue;
xQueueHandle xTempDataQueue;
xQueueHandle xLoggerQueue;

TimerHandle_t TimerStatLed = NULL;

/* USER CODE END Variables */
//osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void)
{
  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	xTempMeasuredQueue = xQueueCreate(1, sizeof(int16_t));
	if (xTempMeasuredQueue == 0)
	{
		while(1);
	}

	xSetpointDataQueue = xQueueCreate(1, sizeof(int16_t));
	if (xSetpointDataQueue == 0)
	{
		while(1);
	}

	xTempDataQueue = xQueueCreate(1, sizeof(TempData));
	if (xTempDataQueue == 0)
	{
		while(1);
	}

	xLoggerQueue = xQueueCreate(1, sizeof(TempData));
	if (xLoggerQueue == 0)
	{
		while(1);
	}

    xTaskCreate(StartSensorReadTask,
		        "SENSOR_READ",
			    512,
			    NULL,
			    8,
			    &xSensorReadHandle);

    xTaskCreate(StartControlTask,
		        "CONTROL",
			    512,
			    NULL,
			    8,
			    &xControlHandle);

    xTaskCreate(StartSetpointTask,
		        "SETPOINT",
			    512,
			    NULL,
			    8,
			    &xSetpointHandle);

    xTaskCreate(StartLoggerTask,
		        "LOGGER",
			    512,
			    NULL,
			    8,
			    &xLoggerHandle);

    TimerStatLed = xTimerCreate("LED-TIMER",
    		                    pdMS_TO_TICKS(TIMER_LED_FREQ_MS),
								pdTRUE,
								NULL,
								TimerLedCallback);

    xTimerStart(TimerStatLed, pdMS_TO_TICKS(0));
    /* USER CODE END RTOS_THREADS */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */


/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

#include "log.h"
#include "stm32f446ze_bsp_log.h"

STM32F446ZEBspLog Logs =
{
	.Intfc =
	{
		.Init = STM32F446ZELogInit,
	},
	.UartHandle = &huart3,
};

LogIntfc *pLogIntfc = (LogIntfc *)&Logs;

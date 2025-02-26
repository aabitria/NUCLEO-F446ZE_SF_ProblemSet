#ifndef INC_STM32F446ZE_BSP_LOG_H_
#define INC_STM32F446ZE_BSP_LOG_H_

#include "log.h"
#include "usart.h"
#include "stm32f4xx_hal.h"

typedef struct
{
	LogIntfc				Intfc;
    UART_HandleTypeDef      *UartHandle;
} STM32F446ZEBspLog;


void STM32F446ZELogInit(LogStruct *pLog, void *Priv);
void STM32F446ZELogSend(LogStruct *pLog, char *pBuff, uint16_t BufLen);


#endif /* INC_STM32F446ZE_BSP_LOG_H_ */

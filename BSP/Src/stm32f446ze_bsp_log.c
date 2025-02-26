#include "stm32f446ze_bsp_log.h"

void STM32F446ZELogInit(LogStruct *pLog, void *Priv)
{
	pLog->Private = Priv;
	pLog->Send = STM32F446ZELogSend;
}


void STM32F446ZELogSend(LogStruct *pLog, char *pBuff, uint16_t BufLen)
{
	STM32F446ZEBspLog *pStmLog = (STM32F446ZEBspLog *)pLog->Private;
	uint32_t count = strlen(pBuff);

	for (int i = 0; i < count; i++)
	{
		while (!__HAL_UART_GET_FLAG(pStmLog->UartHandle, UART_FLAG_TXE));
		pStmLog->UartHandle->Instance->DR = pBuff[i];
	}

}

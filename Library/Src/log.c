#include "log.h"

void LogInit(LogStruct *pLog, void *Priv)
{
	LogIntfc *Intfc = (LogIntfc *)Priv;

	if (Intfc->Init)
	{
		Intfc->Init(pLog, Priv);
	}

	memset(pLog->Buff, 0, LOG_BUFF_BYTE_LEN);
}

void LogSend(LogStruct *pLog)
{
    pLog->Send(pLog, pLog->Buff, sizeof(pLog->Buff));
}

void LogWrite(LogStruct *pLog, char *Str)
{
	uint16_t len = strlen(Str);
    if (len >= LOG_BUFF_BYTE_LEN)
    {
    	memcpy(pLog->Buff, Str, LOG_BUFF_BYTE_LEN - 1);
    	pLog->Buff[LOG_BUFF_BYTE_LEN - 1] = '\0';
    }
    else
    {
    	memcpy(pLog->Buff, Str, len);
    	pLog->Buff[len] = '\0';
    }
}


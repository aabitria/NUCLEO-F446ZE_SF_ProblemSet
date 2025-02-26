#ifndef INC_LOG_H_
#define INC_LOG_H_

#include "string.h"
#include <stdint.h>

#define LOG_BUFF_BYTE_LEN			(64)

typedef struct Log
{
	void 		*Private;
	char	    Buff[LOG_BUFF_BYTE_LEN];
	void        (*Send)(struct Log *pLog, char *pBuff, uint16_t BufLen);
} LogStruct;


typedef struct
{
    void		(*Init)(LogStruct *pLog, void *Priv);
} LogIntfc;


void LogInit(LogStruct *pLog, void *Priv);
void LogWrite(LogStruct *pLog, char *Str);
void LogSend(LogStruct *pLog);

#endif /* INC_LOG_H_ */

#ifndef INC_HEATER_H_
#define INC_HEATER_H_

#include <stdint.h>

typedef struct Heater
{
	void 		*Private;
	void        (*On)(struct Heater *pHtr);
	void        (*Off)(struct Heater *pHtr);
} HeaterStruct;


typedef struct
{
    void		(*Init)(HeaterStruct *pHtr, void *Priv);
} HeaterIntfc;


void HeaterInit(HeaterStruct *pHtr, void *Priv);
void HeaterOn(HeaterStruct *pHtr);
void HeaterOff(HeaterStruct *pHtr);




#endif /* INC_HEATER_H_ */

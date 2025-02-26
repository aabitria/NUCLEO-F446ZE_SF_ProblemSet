#ifndef INC_LED_H_
#define INC_LED_H_

#include <stdint.h>

typedef struct Led
{
	void 		*Private;
	uint8_t		LedState;
	uint8_t     LedInit;
	void        (*On)(struct Led *pHtr);
	void        (*Off)(struct Led *pHtr);
} LedStruct;


typedef struct
{
    void		(*Init)(LedStruct *pLed, void *Priv);
} LedIntfc;


void LedInit(LedStruct *pLed, void *Priv);
void LedOn(LedStruct *pLed);
void LedOff(LedStruct *pLed);


#endif /* INC_LED_H_ */

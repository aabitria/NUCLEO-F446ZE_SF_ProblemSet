#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdint.h>

typedef struct Button
{
	void *   		Private;
	uint8_t			ActiveVal;
	uint8_t			IdleVal;
	uint8_t			ActiveMaskDbounce;
	uint8_t			IdleMaskDbounce;
    uint8_t	        StdyState;
    uint8_t         PrevStdyState;
    uint8_t	        State;
    uint8_t			(*GetVal)(struct Button *pBtn);
} ButtonState;

typedef struct
{
    void			(*Init)(ButtonState *pBtn, void *Priv);
} ButtonIntfc;

void button_init (ButtonState *Btn, void *Private);
uint8_t button_detect_press_event(ButtonState *pButton);

#endif /* INC_BUTTON_H_ */

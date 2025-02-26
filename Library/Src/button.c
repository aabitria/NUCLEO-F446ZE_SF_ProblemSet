#include "button.h"

void button_init (ButtonState *Btn, void *Private)
{
	ButtonIntfc *Intfc = (ButtonIntfc *)Private;

	if (Intfc->Init)
	{
		Intfc->Init(Btn, Private);
	}

	if (Btn->ActiveVal)
	{
		Btn->ActiveMaskDbounce = 0x0F;
		Btn->IdleMaskDbounce = 0xF0;
	}
	else
	{
		Btn->ActiveMaskDbounce = 0xF0;
		Btn->IdleMaskDbounce = 0x0F;
	}

	if (Btn->IdleVal != 0)
    {
        Btn->StdyState = 1;
        Btn->State = 1;
        Btn->PrevStdyState = 1;
    }
    else
    {
        Btn->StdyState = 0;
        Btn->State = 0;
        Btn->PrevStdyState = 0;
    }
}


static uint8_t button_debounce (ButtonState *pButton)
{
    uint8_t val = pButton->GetVal(pButton);

    pButton->State = ((pButton->State << 1) | val);

    // continuous low (pressed) state
    if ((pButton->State & pButton->ActiveMaskDbounce) == pButton->ActiveMaskDbounce)
    {
    	pButton->StdyState = pButton->ActiveVal;
        return pButton->ActiveVal;
    }

    // continuous high (not pressed) state
    if ((pButton->State & pButton->IdleMaskDbounce) == pButton->IdleMaskDbounce)
    {
    	pButton->StdyState = pButton->IdleVal;
        return pButton->IdleVal;
    }

    // none of the above; glitch input that got filtered state
    return pButton->StdyState;
}



uint8_t button_detect_press_event(ButtonState *pButton)
{
    uint8_t State = button_debounce(pButton);

    if ((State != pButton->PrevStdyState) && (State == 0))
    {
    	pButton->PrevStdyState = State;
        return 1;
    }

    pButton->PrevStdyState = State;
    return 0;
}




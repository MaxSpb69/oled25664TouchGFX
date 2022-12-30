#include <F401_Buttons.hpp>
#include <main.h>
#include <touchgfx/hal/HAL.hpp>


void F401ButtonController::init()
{
	previousState = 0;

}

bool F401ButtonController::sample(uint8_t& key)
{

	uint8_t state= HAL_GPIO_ReadPin(ENCODER_KEY_GPIO_Port, ENCODER_KEY_Pin);
	if (state == previousState)
	{
	    return false;
	}
	previousState = state;
	if (state == GPIO_PIN_RESET)
	{
	    key = 49;
	    return true;
	}
	return false;

}

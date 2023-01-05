#include <F401_Buttons.hpp>
#include <main.h>
#include <touchgfx/hal/HAL.hpp>

extern TIM_HandleTypeDef htim4;

void F401ButtonController::init()
{
	previousState = 0;
	Prev_Encoder_count = Encoder_count;
}

bool F401ButtonController::sample(uint8_t& key)
{
    int16_t Encoder_count;

	Encoder_count = ((int16_t)__HAL_TIM_GET_COUNTER(&htim4)) / 4;
	if(Prev_Encoder_count < Encoder_count)
	{
		// Encoder clockwise step
		key = 50;
		Prev_Encoder_count = Encoder_count;
		return true;
	}
	else if(Prev_Encoder_count > Encoder_count)
	{
		//  Encoder counterclockwise step
		key = 51;
		Prev_Encoder_count = Encoder_count;
		return true;
	}
	else
	{
		// Encoder button_pressed

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

}

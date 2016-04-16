/*
 New enterprise RFID authentication controller

 Copyright (C) 2016 Tadeusz Magura-Witkowski

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include <stdint.h>

#include "wiegand.h"
#include "stm32f0xx_hal.h"

// TODO: optimize this
static uint8_t GPIO_To_Wiegand_Channel(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
	case D0_0_Pin:
	case D1_0_Pin:
		return 0;

	case D0_1_Pin:
	case D1_1_Pin:
		return 1;

	case D0_2_Pin:
	case D1_2_Pin:
		return 2;

	case D0_3_Pin:
	case D1_3_Pin:
		return 3;

	case D0_4_Pin:
	case D1_4_Pin:
		return 4;

	case D0_5_Pin:
	case D1_5_Pin:
		return 5;

	case D0_6_Pin:
	case D1_6_Pin:
		return 6;
	default:
		return 0;
	}
}

// TODO: optimize this
static uint8_t GPIO_To_Wiegand_Bit(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
	case D0_0_Pin:
	case D0_1_Pin:
	case D0_2_Pin:
	case D0_3_Pin:
	case D0_4_Pin:
	case D0_5_Pin:
	case D0_6_Pin:
		return 0;
	default:
		return 1;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	uint8_t channel_id = GPIO_To_Wiegand_Channel(GPIO_Pin);
	uint8_t bit = GPIO_To_Wiegand_Bit(GPIO_Pin);

	Wiegand_HandleTransmission(channel_id, bit);
}

void HAL_SYSTICK_Callback(void)
{
	Wiegand_SysTickHandler();
}

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

#include <assert.h>

#include "stm32f0xx_hal.h"

#include "gpio_mapper.h"

uint8_t GPIO_To_Wiegand_Channel(uint16_t GPIO_Pin)
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
		assert(0);
		return 0; // never reached
	}
}

uint8_t GPIO_To_Wiegand_Bit(uint16_t GPIO_Pin)
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

static const GPIO_TypeDef *GPIO_MAP_PORT_BUZZER[] = {
		BUZZER_0_GPIO_Port,
		BUZZER_1_GPIO_Port,
		BUZZER_2_GPIO_Port,
		BUZZER_3_GPIO_Port,
		BUZZER_4_GPIO_Port,
		BUZZER_5_GPIO_Port,
		BUZZER_6_GPIO_Port
};


static const GPIO_TypeDef *GPIO_MAP_PORT_LED[] = {
		LED_0_GPIO_Port,
		LED_1_GPIO_Port,
		LED_2_GPIO_Port,
		LED_3_GPIO_Port,
		LED_4_GPIO_Port,
		LED_5_GPIO_Port,
		LED_6_GPIO_Port
};


static const GPIO_TypeDef *GPIO_MAP_PORT_OPEN[] = {
		OPEN_0_GPIO_Port,
		OPEN_1_GPIO_Port,
		OPEN_2_GPIO_Port,
		OPEN_3_GPIO_Port,
		OPEN_4_GPIO_Port,
		OPEN_5_GPIO_Port,
		OPEN_6_GPIO_Port
};

static const GPIO_TypeDef *GPIO_MAP_PORT_TAMPER[] = {
		TAMPER_0_GPIO_Port,
		TAMPER_1_GPIO_Port,
		TAMPER_2_GPIO_Port,
		TAMPER_3_GPIO_Port,
		TAMPER_4_GPIO_Port,
		TAMPER_5_GPIO_Port,
		TAMPER_6_GPIO_Port
};

static const uint16_t GPIO_MAP_PIN_BUZZER[] = {
		BUZZER_0_Pin,
		BUZZER_1_Pin,
		BUZZER_2_Pin,
		BUZZER_3_Pin,
		BUZZER_4_Pin,
		BUZZER_5_Pin,
		BUZZER_6_Pin,
};

static const uint16_t GPIO_MAP_PIN_LED[] = {
		LED_0_Pin,
		LED_1_Pin,
		LED_2_Pin,
		LED_3_Pin,
		LED_4_Pin,
		LED_5_Pin,
		LED_6_Pin,
};

static const uint16_t GPIO_MAP_PIN_OPEN[] = {
		OPEN_0_Pin,
		OPEN_1_Pin,
		OPEN_2_Pin,
		OPEN_3_Pin,
		OPEN_4_Pin,
		OPEN_5_Pin,
		OPEN_6_Pin,
};

static const uint16_t GPIO_MAP_PIN_TAMPER[] = {
		TAMPER_0_Pin,
		TAMPER_1_Pin,
		TAMPER_2_Pin,
		TAMPER_3_Pin,
		TAMPER_4_Pin,
		TAMPER_5_Pin,
		TAMPER_6_Pin,
};

GPIO_TypeDef *GPIO_Port_ForChannel(uint8_t channel, GPIO_Mapper_DeviceTypeDef device)
{
	assert(channel < GPIO_MAPPER_NUMBER_OF_CHANNELS);
	assert(device < GPIO_MAPPER_DEVICE_NUM);

	switch(device)
	{
	case GPIO_MAPPER_BUZZER:
		return GPIO_MAP_PORT_BUZZER[channel];
	case GPIO_MAPPER_LED:
		return GPIO_MAP_PORT_LED[channel];
	case GPIO_MAPPER_OPEN:
		return GPIO_MAP_PORT_OPEN[channel];
	case GPIO_MAPPER_TAMPER:
		return GPIO_MAP_PORT_TAMPER[channel];

	default:
		assert(0);
		return 0; // never reached

	}
}

uint16_t GPIO_Pin_ForChannel(uint8_t channel, GPIO_Mapper_DeviceTypeDef device)
{
	assert(channel < GPIO_MAPPER_NUMBER_OF_CHANNELS);
	assert(device < GPIO_MAPPER_DEVICE_NUM);

	switch(device)
	{
	case GPIO_MAPPER_BUZZER:
		return GPIO_MAP_PIN_BUZZER[channel];
	case GPIO_MAPPER_LED:
		return GPIO_MAP_PIN_LED[channel];
	case GPIO_MAPPER_OPEN:
		return GPIO_MAP_PIN_OPEN[channel];
	case GPIO_MAPPER_TAMPER:
		return GPIO_MAP_PIN_TAMPER[channel];

	default:
		assert(0);
		return 0; // never reached

	}
}

void GPIO_Write_Channel(uint8_t channel_id, GPIO_Mapper_DeviceTypeDef device, GPIO_PinState state)
{
	HAL_GPIO_WritePin(GPIO_Port_ForChannel(channel_id, device),
			GPIO_Pin_ForChannel(channel_id, device), state);
}

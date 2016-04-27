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

#include "zone.h"
#include "gpio_mapper.h"

volatile static uint8_t zone_configured = 0;
volatile static Zone_InitConfigTypeDef zone_config;
volatile static Zone_ChannelTypeDef zone_channels[ZONE_MAX_CHANNELS];

void Zone_Init(Zone_InitConfigTypeDef *config)
{
	assert(config->channels < ZONE_MAX_CHANNELS);

	zone_config.channels = config->channels;
	zone_configured = 1;
}

static Zone_ChannelTypeDef *Zone_Channel_Get(Wiegand_Channel_NumberTypeDef id)
{
	assert(id < zone_config.channels);

	return (Zone_ChannelTypeDef *)&zone_channels[id]; // I know it discards volatile
}

Zone_DataInputTypeDef *Zone_HasData()
{
	return 0;
}

void Zone_Accept(Wiegand_Channel_NumberTypeDef zone_number)
{

}

void Zone_Reject(Wiegand_Channel_NumberTypeDef zone_number)
{

}

void Zone_Block(Wiegand_Channel_NumberTypeDef zone_number)
{

}

void Zone_Callback(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number)
{
	if(! zone_configured)
	{
		return;
	}

	Zone_ChannelTypeDef *channel = Zone_Channel_Get(channel_id);

	if(channel->state == ZONE_STATE_LOCKED)
	{
		return;
	}
}

static void Zone_Process_Timers(uint8_t channel_id)
{
	Zone_ChannelTypeDef *channel = Zone_Channel_Get(channel_id);

	if(channel->beep_timer)
	{
		channel->beep_timer--;
		GPIO_Write_Channel(channel_id, GPIO_MAPPER_BUZZER, GPIO_PIN_SET);
	}
	else
	{
		GPIO_Write_Channel(channel_id, GPIO_MAPPER_BUZZER, GPIO_PIN_RESET);
	}

	if(channel->led_timer)
	{
		channel->led_timer--;
		GPIO_Write_Channel(channel_id, GPIO_MAPPER_LED, GPIO_PIN_SET);
	}
	else
	{
		GPIO_Write_Channel(channel_id, GPIO_MAPPER_LED, GPIO_PIN_RESET);
	}

	if(channel->open_timer)
	{
		channel->open_timer--;
		GPIO_Write_Channel(channel_id, GPIO_MAPPER_OPEN, GPIO_PIN_SET);
	}
	else
	{
		GPIO_Write_Channel(channel_id, GPIO_MAPPER_OPEN, GPIO_PIN_RESET);
	}
}

// called from interrupt
void Zone_SysTickHandler()
{
	if(! zone_configured)
	{
		return;
	}

	int i;

	for (i = 0; i < zone_config.channels; ++i) {
		Zone_ChannelTypeDef *channel = Zone_Channel_Get(i);

		Zone_Process_Timers(i);
	}
}

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

// TODO: Add rate limiting..
// TODO: Move GPIO operations to interrupt_routines

#include <assert.h>

#include "stm32f0xx_hal.h"

#include "zone.h"
#include "gpio_mapper.h"
#include "timer.h"

volatile static uint8_t zone_configured = 0;
volatile static Zone_InitTypeDef zone_config;
volatile static Zone_ChannelTypeDef zone_channels[ZONE_MAX_CHANNELS];

volatile static Timer_TimerTypeDef timers;

static Zone_ChannelTypeDef *Zone_Channel_Get(Wiegand_Channel_NumberTypeDef id)
{
	assert(id < zone_config.channels);

	return (Zone_ChannelTypeDef *)&zone_channels[id]; // I know it discards volatile
}

static void Zone_Channel_InitStruct(Zone_ChannelTypeDef *channel, Zone_IdTypeDef id)
{
	channel->id = id;

	channel->state = ZONE_STATE_NORMAL;

	channel->tamper_timer = 0;
}

void Zone_Config(Zone_InitTypeDef *config)
{
	assert(config->channels <= ZONE_MAX_CHANNELS);

	zone_config.channels = config->channels;

	int i;
	for(i = 0; i < config->channels; ++i)
	{
		Zone_Channel_InitStruct(Zone_Channel_Get(i), i);
	}

	Timer_Init(&timers);

	zone_configured = 1;
}

static void Zone_AcceptTimeout(void *channel_p)
{
	Zone_ChannelTypeDef *channel = (Zone_ChannelTypeDef *)channel_p;

	GPIO_Write_Channel(channel->id, GPIO_MAPPER_OPEN, GPIO_PIN_RESET);
}
void Zone_Accept(Wiegand_Channel_NumberTypeDef zone_number)
{
	Zone_ChannelTypeDef *channel = Zone_Channel_Get(zone_number);

	GPIO_Write_Channel(channel->id, GPIO_MAPPER_OPEN, GPIO_PIN_SET);
	Timer_Cancel(&timers, Zone_AcceptTimeout, (void*) channel);
	Timer_Start(&timers, ZONE_OPEN_TIMEOUT, Zone_AcceptTimeout, (void*) channel);
}

static void Zone_RejectTimeout(void *channel_p)
{
	Zone_ChannelTypeDef *channel = (Zone_ChannelTypeDef *)channel_p;

	GPIO_Write_Channel(channel->id, GPIO_MAPPER_BUZZER, GPIO_PIN_RESET);
}
void Zone_Reject(Wiegand_Channel_NumberTypeDef zone_number)
{
	Zone_ChannelTypeDef *channel = Zone_Channel_Get(zone_number);

	GPIO_Write_Channel(zone_number, GPIO_MAPPER_BUZZER, GPIO_PIN_SET);
	Timer_Cancel(&timers, Zone_AcceptTimeout, (void*) channel);
	Timer_Start(&timers, ZONE_BEEP_TIMEOUT, Zone_RejectTimeout, (void*) channel);
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

	switch(length)
	{
	case ZONE_CARD_LENGTH:
		Zone_Callback_CardRead(channel_id, length, card_number);
		break;

	case ZONE_KEYPRESS_LENGTH:
		Zone_Callback_KeyPress(channel_id, card_number);
		break;

	default:
		break;
	}
}


static void Zone_Process_Tamper(uint8_t channel_id)
{
	Zone_ChannelTypeDef *channel = Zone_Channel_Get(channel_id);


	if(channel->tamper_timer)
	{
		channel->tamper_timer--;

		return;
	}

	if(HAL_GPIO_ReadPin(
			GPIO_Port_ForChannel(channel_id, GPIO_MAPPER_TAMPER),
			GPIO_Pin_ForChannel(channel_id, GPIO_MAPPER_TAMPER)) == GPIO_PIN_SET)
	{
		Zone_Callback_Tamper(channel_id);

		channel->tamper_timer = ZONE_TAMPER_TIMEOUT;
	}
}

static void Zone_Process(uint8_t channel_id)
{
	// tamper
	Zone_Process_Tamper(channel_id);
}

// called from interrupt
void Zone_SysTickHandler(void)
{
	if(! zone_configured)
	{
		return;
	}

	int i;

	Timer_SysTickHandler(&timers);

	for (i = 0; i < zone_config.channels; ++i) {
		Zone_Process(i);
	}
}

__weak void Zone_Callback_CardRead(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number)
{
//
}

__weak void Zone_Callback_KeyPress(Wiegand_Channel_NumberTypeDef channel_id, Zone_Keypress_KeyTypeDef key)
{
//
}

__weak void Zone_Callback_Tamper(Wiegand_Channel_NumberTypeDef channel_id)
{
//
}

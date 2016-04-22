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
#include <stdlib.h>

#include "wiegand.h"

typedef struct {
	Wiegand_Channel_Number number;
	uint8_t position;
	Wiegand_CardNumberTypeDef buffer;
	uint32_t last_read_timer;
} Wiegand_ChannelTypeDef;

volatile static uint8_t wiegand_configured = 0;
volatile static Wiegand_ChannelTypeDef wiegand_channels[WIEGAND_MAX_CHANNELS];
volatile static WiegandInitTypeDef wiegand_config;

static void Wiegand_Channel_InitStruct(Wiegand_ChannelTypeDef *channel, Wiegand_Channel_Number number)
{
	channel->number = number;
	channel->position = 0;
	channel->buffer = 0;
	channel->last_read_timer = 0;
}

static void Wiegand_Channel_Clear(Wiegand_ChannelTypeDef *channel)
{
	channel->position = 0;
	channel->buffer = 0;
}

static Wiegand_ChannelTypeDef *Wiegand_Channel_Get(Wiegand_Channel_Number id)
{
	assert(id < wiegand_config.channels_number);

	return (Wiegand_ChannelTypeDef *)&wiegand_channels[id]; // I know it discards volatile
}


void Wiegand_Config(WiegandInitTypeDef *init_config)
{
	int i;

//	wiegand_channels = (void*) malloc(sizeof(Wiegand_ChannelTypeDef) * init_config->channels_number);
	assert(init_config->channels_number < WIEGAND_MAX_CHANNELS);

	wiegand_config.channels_number = init_config->channels_number;
	wiegand_config.check_parity = init_config->check_parity;

	for(i = 0; i < init_config->channels_number; i++)
	{
		Wiegand_Channel_InitStruct(Wiegand_Channel_Get(i), i);
	}

	wiegand_configured = 1;
}

static uint8_t Wiegand_Parity_Calc(Wiegand_CardNumberTypeDef bitstream, uint8_t from, uint8_t len)
{
	bitstream >>= from;

	int i = 0;
	uint8_t calc_parity = 0;

	while(i < len)
	{
		calc_parity ^= (uint8_t) bitstream & 1;

		bitstream >>= 1;
		i++;
	}

	return calc_parity;
}

static uint8_t Wiegand_Channel_IsValid(Wiegand_ChannelTypeDef *channel)
{
	if(! wiegand_config.check_parity)
	{
		return 1;
	}

	uint8_t parity_calc;
	uint8_t bitstream_length = channel->position - 2; // length of data bits (len-2 parity bits)
	uint8_t bitstream_length_2 = bitstream_length/2;

	parity_calc = Wiegand_Parity_Calc(channel->buffer, 0, bitstream_length_2+1);

	if(parity_calc != 0)
	{
		return 0;
	}

	parity_calc = Wiegand_Parity_Calc(channel->buffer, bitstream_length_2+1, bitstream_length_2+1);

	if(parity_calc != 1)
	{
		return 0;
	}

	return 1;
}

static Wiegand_CardNumberTypeDef Wiegand_Channel_StripParityBits(Wiegand_ChannelTypeDef *channel)
{
	return (channel->buffer & (~(1<<(channel->position)-1)))>>1;
}

static void Wiegand_Channel_Call(Wiegand_ChannelTypeDef *channel)
{
	if(Wiegand_Channel_IsValid(channel))
	{
		Wiegand_Callback(channel->number, channel->position, Wiegand_Channel_StripParityBits(channel));
	}
}


static void Wiegand_Channel_Run(Wiegand_ChannelTypeDef *channel)
{
	Wiegand_Channel_Call(channel);
	Wiegand_Channel_Clear(channel);
}

// called from interrupt
void Wiegand_HandleTransmission(Wiegand_Channel_Number channel_id, uint8_t bit)
{
	if(! wiegand_configured)
	{
		return;
	}

	Wiegand_ChannelTypeDef *channel = Wiegand_Channel_Get(channel_id);
	channel->buffer |= bit << channel->position;
	channel->position++;
	channel->last_read_timer = 0;

	if(channel->position >= WIEGAND_MAX_LENGTH)
	{
		Wiegand_Channel_Run(channel);
	}
}

// called from interrupt
void Wiegand_SysTickHandler(void)
{
	if(! wiegand_configured)
	{
		return;
	}

	int i;

	for(i = 0; i < wiegand_config.channels_number; i++)
	{
		Wiegand_ChannelTypeDef *channel = Wiegand_Channel_Get(i);

		if(channel->position > 0 &&
				channel->last_read_timer++ > WIEGAND_SYSTICKS_TIMEOUT)
		{
			Wiegand_Channel_Run(channel);
		}
	}
}

__weak void Wiegand_Callback(Wiegand_Channel_Number channel_id, uint8_t channel_position, Wiegand_CardNumberTypeDef card_number)
{
	// Will be overridden by user
}

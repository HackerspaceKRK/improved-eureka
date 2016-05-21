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

#include "stm32f0xx_hal.h"

#include "uart_controller.h"
#include "wiegand.h"

static UART_Controller_InitTypeDef config;
static UART_Controller_MessageQueueTypeDef runtime;
static uint8_t configured = 0;


static void UART_Controller_CopyConfig(UART_Controller_InitTypeDef *new_config)
{
	config.uart = new_config->uart;
}

static void UART_Controller_ResetSlot(UART_Controller_MessageTypeDef *message)
{
	message->length = 0;
}

static UART_Controller_MessageTypeDef *UART_Controller_Get(UART_Controller_ChannelIdTypeDef id)
{
	assert(id < UART_CONTROLLER_MAX_MESSAGE_QUEUE_LENGTH);

	return &runtime.queue[id];
}

static void UART_Controller_InitRuntime(void)
{
	runtime.last = 0;
	runtime.sending = 0;

	UART_Controller_ChannelIdTypeDef i;
	for (i = 0; i < UART_CONTROLLER_MAX_MESSAGE_QUEUE_LENGTH; ++i) {
		UART_Controller_ResetSlot(UART_Controller_Get(i));
	}
}

static UART_Controller_MessageTypeDef *UART_Controller_GetFreeSlot(void)
{
	UART_Controller_ChannelIdTypeDef i;
	for (i = 0; i < UART_CONTROLLER_MAX_MESSAGE_QUEUE_LENGTH; ++i) {
		UART_Controller_MessageTypeDef *message = UART_Controller_Get(i);

		if(message->length == 0)
			return message;
	}

	return 0;
}

static UART_Controller_MessageTypeDef *UART_Controller_GetToSend(void)
{
	UART_Controller_ChannelIdTypeDef i;
	for (i = 0; i < UART_CONTROLLER_MAX_MESSAGE_QUEUE_LENGTH; ++i) {
		UART_Controller_MessageTypeDef *message = UART_Controller_Get(i);

		if(message->length != 0)
			return message;
	}

	return 0;
}


void UART_Controller_Config(UART_Controller_InitTypeDef *new_config)
{

	UART_Controller_CopyConfig(new_config);
	UART_Controller_InitRuntime();

	configured = 1;
}

void UART_Controller_SendCard(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number)
{
	if( !configured)
	{
		return;
	}

	UART_Controller_MessageTypeDef *message = UART_Controller_GetFreeSlot();

	if(! message)
	{
		return;
	}

	message->length = snprintf((char*)message->message, UART_CONTROLLER_MAX_MESSAGE_LENGTH, "*%d#C#%d\n", (int)channel_id, (int)card_number);
}

void UART_Controller_SendKey(Wiegand_Channel_NumberTypeDef channel_id, Zone_Keypress_KeyTypeDef key)
{
	if( !configured)
	{
		return;
	}

	UART_Controller_MessageTypeDef *message = UART_Controller_GetFreeSlot();

	if(! message)
	{
		return;
	}

	message->length = snprintf((char*)message->message, UART_CONTROLLER_MAX_MESSAGE_LENGTH, "*%d#K#%d\n", (int)channel_id, (int)key);
}

static void UART_Controller_SendMessage(UART_Controller_MessageTypeDef *message)
{
	runtime.sending = 1;
	assert(HAL_UART_Transmit_DMA(config.uart, message->message, message->length) == HAL_OK);
}

void UART_Controller_Process(void)
{
	if(! configured)
	{
		return;
	}

	if(runtime.sending)
	{
		return;
	}

	// find victim
	UART_Controller_MessageTypeDef *message = UART_Controller_GetToSend();
	if(! message)
	{
		return;
	}

	runtime.last = message;
	UART_Controller_SendMessage(message);
}

// called from interrupt
void UART_Controller_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart != config.uart)
		return; // not mine

	UART_Controller_ResetSlot(runtime.last);
	runtime.sending = 0;
}

__weak void UART_Controller_Action_Open(Wiegand_Channel_NumberTypeDef channel_id)
{
	//
}

__weak void UART_Controller_Action_Reject(Wiegand_Channel_NumberTypeDef channel_id)
{
	//
}

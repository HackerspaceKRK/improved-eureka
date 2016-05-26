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
#include <string.h>

#include "stm32f0xx_hal.h"

#include "uart_controller.h"
#include "wiegand.h"

static UART_Controller_InitTypeDef config;
volatile static UART_Controller_MessageQueueTypeDef runtime;
static uint8_t configured = 0;


static void UART_Controller_CopyConfig(UART_Controller_InitTypeDef *new_config)
{
	config.uart = new_config->uart;
}

static void UART_Controller_InitRuntime(void)
{
	runtime.current_out_message = 0;

	runtime.in_buffer_position = 0;

	Message_Queue_Init(&runtime.out_queue);
	Message_Queue_Init(&runtime.in_queue);
}

void UART_Controller_Config(UART_Controller_InitTypeDef *new_config)
{

	UART_Controller_CopyConfig(new_config);
	UART_Controller_InitRuntime();

	configured = 1;

	assert(HAL_UART_Receive_DMA(config.uart, &runtime.in_char, 1) == HAL_OK);
}

void UART_Controller_SendCard(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number)
{
	Message_Queue_MessageTypeDef *message = Message_Queue_GetFree(&runtime.out_queue);

	assert(message);

	message->length = snprintf((char*)message->message, MESSAGE_QUEUE_MAX_MESSAGE_LENGTH, "*C#%d#%d\n", (int)channel_id, (int)card_number);
}

void UART_Controller_SendKey(Wiegand_Channel_NumberTypeDef channel_id, Zone_Keypress_KeyTypeDef key)
{
	Message_Queue_MessageTypeDef *message = Message_Queue_GetFree(&runtime.out_queue);

	assert(message);

	message->length = snprintf((char*)message->message, MESSAGE_QUEUE_MAX_MESSAGE_LENGTH, "*K#%d#%d\n", (int)channel_id, (int)key);
}

void UART_Controller_SendTamper(Wiegand_Channel_NumberTypeDef channel_id)
{
	Message_Queue_MessageTypeDef *message = Message_Queue_GetFree(&runtime.out_queue);

	assert(message);

	message->length = snprintf((char*)message->message, MESSAGE_QUEUE_MAX_MESSAGE_LENGTH, "*T#%d\n", (int)channel_id);
}

void UART_Controller_SendWatchdog(void)
{
	Message_Queue_MessageTypeDef *message = Message_Queue_GetFree(&runtime.out_queue);

	assert(message);

	message->length = snprintf((char*)message->message, MESSAGE_QUEUE_MAX_MESSAGE_LENGTH, "*W\n");
}

void UART_Controller_SendPong(void)
{
	Message_Queue_MessageTypeDef *message = Message_Queue_GetFree(&runtime.out_queue);

	assert(message);

	message->length = snprintf((char*)message->message, MESSAGE_QUEUE_MAX_MESSAGE_LENGTH, "*P\n");
}

static void UART_Controller_SendMessage(Message_Queue_MessageTypeDef *message)
{
	runtime.current_out_message = message;
	UART_Controller_SendStart();

	assert(HAL_UART_Transmit_DMA(config.uart, message->message, message->length) == HAL_OK);
}

static void UART_Controller_ProcessAction(void)
{
	Message_Queue_MessageTypeDef *message = Message_Queue_GetUsed(&runtime.in_queue);
	if(! message)
	{
		return;
	}

	uint8_t *hash_loc = memchr(message->message, '#', message->length);

	if(hash_loc != 0)
	{
		*hash_loc = 0;

		uint8_t *action_char = message->message+1;

		uint8_t *channel_number_s = hash_loc + 1;
		Wiegand_Channel_NumberTypeDef channel_number = atoi(channel_number_s);

		switch(*action_char)
		{
		case 'A': // accept
			UART_Controller_Action_Accept(channel_number);
			break;
		case 'R': // reject
			UART_Controller_Action_Reject(channel_number);
			break;
		case 'P': // ping
			UART_Controller_Action_Ping();
			break;

		default:
			break;
		}
	}

	Message_Queue_ResetSlot(message);
}

static void UART_Controller_ProcessOut(void)
{
	if(runtime.current_out_message)
	{
		return;
	}

	// find victim
	Message_Queue_MessageTypeDef *message = Message_Queue_GetUsed(&runtime.out_queue);
	if(! message)
	{
		return;
	}

	UART_Controller_SendMessage(message);
}

void UART_Controller_Process(void)
{
	if(! configured)
	{
		return;
	}

	UART_Controller_ProcessOut();
	UART_Controller_ProcessAction();
}

// called from interrupt
void UART_Controller_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart != config.uart)
		return; // not mine

	Message_Queue_ResetSlot(runtime.current_out_message);
	runtime.current_out_message = 0;
	UART_Controller_SendStop();
}

static void UART_Controller_ProcessReceivedData(void)
{
	// in case of overflow wait for * (starting character)
	if(runtime.in_buffer_position >= MESSAGE_QUEUE_MAX_MESSAGE_LENGTH)
	{
		if(runtime.in_char == '*')
		{
			runtime.in_buffer_position = 0;
		}
		else
		{
			return;
		}
	}

	runtime.in_buffer[runtime.in_buffer_position++] = runtime.in_char;

	if(runtime.in_char == '\n')
	{
		Message_Queue_MessageTypeDef *message = Message_Queue_GetFree(&runtime.in_queue);
		assert(message); // queue full!

		// add to queue
		memcpy(message->message, runtime.in_buffer, runtime.in_buffer_position);
		message->length = runtime.in_buffer_position;

		runtime.in_buffer_position = 0;

		return;
	}
}



// called from interrupt
void UART_Controller_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart != config.uart)
		return; // not mine

	UART_Controller_ProcessReceivedData();
}

__weak void UART_Controller_Action_Accept(Wiegand_Channel_NumberTypeDef channel_id)
{
	//
}

__weak void UART_Controller_Action_Reject(Wiegand_Channel_NumberTypeDef channel_id)
{
	//
}

__weak void UART_Controller_Action_Ping()
{

}

__weak void UART_Controller_SendStart(void)
{

}
__weak void UART_Controller_SendStop(void)
{

}

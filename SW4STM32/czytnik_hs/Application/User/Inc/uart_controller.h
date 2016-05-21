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

#ifndef APPLICATION_USER_INC_UART_CONTROLLER_H_
#define APPLICATION_USER_INC_UART_CONTROLLER_H_

#include "zone.h"
#include "wiegand.h"
#include "message_queue.h"

typedef uint8_t UART_Controller_ChannelIdTypeDef;


typedef struct {
	Message_Queue_MessageQueueTypeDef out_queue;
	Message_Queue_MessageQueueTypeDef in_queue;

	Message_Queue_MessageTypeDef *current_out_message;

	uint8_t in_buffer[MESSAGE_QUEUE_MAX_MESSAGE_LENGTH];
	uint8_t in_buffer_position;
	uint8_t in_char;

} UART_Controller_MessageQueueTypeDef;

typedef struct {
	UART_HandleTypeDef *uart;
} UART_Controller_InitTypeDef;

void UART_Controller_Config(UART_Controller_InitTypeDef *config);

void UART_Controller_SendCard(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number);
void UART_Controller_SendKey(Wiegand_Channel_NumberTypeDef channel_id, Zone_Keypress_KeyTypeDef key);
void UART_Controller_SendTamper(Wiegand_Channel_NumberTypeDef channel_id);

void UART_Controller_Process(void);

__weak void UART_Controller_Action_Accept(Wiegand_Channel_NumberTypeDef channel_id);
__weak void UART_Controller_Action_Reject(Wiegand_Channel_NumberTypeDef channel_id);

// called from interrupt
void UART_Controller_TxCpltCallback(UART_HandleTypeDef *huart);
void UART_Controller_RxCpltCallback(UART_HandleTypeDef *huart);

#endif /* APPLICATION_USER_INC_UART_CONTROLLER_H_ */

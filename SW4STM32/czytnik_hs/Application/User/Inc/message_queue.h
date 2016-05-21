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

#ifndef APPLICATION_USER_INC_MESSAGE_QUEUE_H_
#define APPLICATION_USER_INC_MESSAGE_QUEUE_H_

#define MESSAGE_QUEUE_MAX_MESSAGE_LENGTH 20
#define MESSAGE_QUEUE_QUEUE_LENGTH 10

#include <stdint.h>

typedef struct {
	uint8_t message[MESSAGE_QUEUE_MAX_MESSAGE_LENGTH];
	uint8_t length;
} Message_Queue_MessageTypeDef;

typedef struct {
	Message_Queue_MessageTypeDef queue[MESSAGE_QUEUE_QUEUE_LENGTH];
} Message_Queue_MessageQueueTypeDef;

typedef uint8_t Message_Queue_SlotIdTypeDef;


void Message_Queue_Init(Message_Queue_MessageQueueTypeDef *message_queue);

void Message_Queue_ResetSlot(Message_Queue_MessageTypeDef *message);

Message_Queue_MessageTypeDef *Message_Queue_GetFree(Message_Queue_MessageQueueTypeDef *message_queue);
Message_Queue_MessageTypeDef *Message_Queue_GetUsed(Message_Queue_MessageQueueTypeDef *message_queue);


#endif /* APPLICATION_USER_INC_MESSAGE_QUEUE_H_ */

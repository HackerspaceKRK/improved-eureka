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

#include "message_queue.h"

static Message_Queue_MessageTypeDef *Message_Queue_Get(Message_Queue_MessageQueueTypeDef *message_queue, Message_Queue_SlotIdTypeDef id)
{
	assert(id < MESSAGE_QUEUE_QUEUE_LENGTH);

	return &message_queue->queue[id];
}

void Message_Queue_ResetSlot(Message_Queue_MessageTypeDef *message)
{
	message->length = 0;
}

void Message_Queue_Init(Message_Queue_MessageQueueTypeDef *message_queue)
{
	int i;
	for (i = 0; i < MESSAGE_QUEUE_QUEUE_LENGTH; ++i) {
		Message_Queue_MessageTypeDef *message = Message_Queue_Get(message_queue, i);

		Message_Queue_ResetSlot(message);
	}
}

Message_Queue_MessageTypeDef *Message_Queue_GetFree(Message_Queue_MessageQueueTypeDef *message_queue)
{
	int i;
	for (i = 0; i < MESSAGE_QUEUE_QUEUE_LENGTH; ++i) {
		Message_Queue_MessageTypeDef *message = Message_Queue_Get(message_queue, i);

		if(message->length == 0)
		{
			return message;
		}
	}

	return 0;
}

Message_Queue_MessageTypeDef *Message_Queue_GetUsed(Message_Queue_MessageQueueTypeDef *message_queue)
{
	int i;
	for (i = 0; i < MESSAGE_QUEUE_QUEUE_LENGTH; ++i) {
		Message_Queue_MessageTypeDef *message = Message_Queue_Get(message_queue, i);

		if(message->length) // not 0
		{
			return message;
		}
	}

	return 0;
}

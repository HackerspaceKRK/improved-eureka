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

#ifndef APPLICATION_USER_INC_ZONE_H_
#define APPLICATION_USER_INC_ZONE_H_

#include "wiegand.h"

#define ZONE_MAX_CHANNELS 7

#define ZONE_LED_TIMEOUT 500
#define ZONE_BEEP_TIMEOUT 100
#define ZONE_OPEN_TIMEOUT 1000

typedef struct
{
	Wiegand_Channel_NumberTypeDef channels;
} Zone_InitConfigTypeDef;

typedef enum
{
	ZONE_STATE_NORMAL,
	ZONE_STATE_LOCKED
} Zone_StateTypeDef;

typedef struct
{
	Wiegand_CardNumberTypeDef card_number;
	Wiegand_Channel_NumberTypeDef channel;
	uint8_t length;
} Zone_DataInputTypeDef;

typedef struct
{
	Zone_StateTypeDef state;

	uint16_t led_timer;
	uint16_t beep_timer;
	uint16_t open_timer;
} Zone_ChannelTypeDef;

void Zone_Init(Zone_InitConfigTypeDef *config);

Zone_DataInputTypeDef *Zone_HasData();

void Zone_Accept(Wiegand_Channel_NumberTypeDef zone_number);
void Zone_Reject(Wiegand_Channel_NumberTypeDef zone_number);
void Zone_Block(Wiegand_Channel_NumberTypeDef zone_number);

void Zone_Callback(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number);

void Zone_SysTickHandler(); // called from interrupt


#endif /* APPLICATION_USER_INC_ZONE_H_ */

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

#ifndef APPLICATION_USER_WIEGAND_H_
#define APPLICATION_USER_WIEGAND_H_

#include <stdint.h>

#define WIEGAND_MAX_CHANNELS 7

#define WIEGAND_MAX_LENGTH 26
#define WIEGAND_SYSTICKS_TIMEOUT 3

// Wiegand 26 decoder

typedef uint8_t Wiegand_Channel_NumberTypeDef;
typedef uint32_t Wiegand_CardNumberTypeDef;
#define WIEGAND_CARDNUMBER_BITS_LENGTH 32

typedef struct {
	Wiegand_Channel_NumberTypeDef channels_number;
	uint8_t check_parity;
} WiegandInitTypeDef;

void Wiegand_Config(WiegandInitTypeDef *init_config);
void Wiegand_HandleTransmission(Wiegand_Channel_NumberTypeDef channel, uint8_t bit); // called from interrupt
void Wiegand_SysTickHandler(void); // from interrupt

void Wiegand_Process(void);
__weak void Wiegand_Callback(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number);

#endif /* APPLICATION_USER_WIEGAND_H_ */

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

#ifndef APPLICATION_USER_INC_GPIO_MAPPER_H_
#define APPLICATION_USER_INC_GPIO_MAPPER_H_

#include "stm32f0xx_hal.h"

typedef enum {
	GPIO_MAPPER_BUZZER = 0,
	GPIO_MAPPER_LED = 1,
	GPIO_MAPPER_OPEN = 2
} GPIO_Mapper_DeviceTypeDef;

#define GPIO_MAPPER_NUMBER_OF_CHANNELS 7
#define GPIO_MAPPER_DEVICE_NUM 3

uint8_t GPIO_To_Wiegand_Channel(uint16_t GPIO_Pin);
uint8_t GPIO_To_Wiegand_Bit(uint16_t GPIO_Pin);

//GPIO_TypeDef *GPIO_Buzzer_Port_ForChannel(uint8_t channel);
//uint16_t GPIO_Buzzer_Pin_ForChannel(uint8_t channel);
//
//GPIO_TypeDef *GPIO_Led_Port_ForChannel(uint8_t channel);
//uint16_t *GPIO_Led_Pin_ForChannel(uint8_t channel);
//
//GPIO_TypeDef *GPIO_Open_Port_ForChannel(uint8_t channel);
//uint16_t *GPIO_Open_Pin_ForChannel(uint8_t channel);

GPIO_TypeDef *GPIO_Port_ForChannel(uint8_t channel_id, GPIO_Mapper_DeviceTypeDef device);
uint16_t *GPIO_Pin_ForChannel(uint8_t channel_id, GPIO_Mapper_DeviceTypeDef device);

void GPIO_Write_Channel(uint8_t channel_id, GPIO_Mapper_DeviceTypeDef device, GPIO_PinState state);


#endif /* APPLICATION_USER_INC_GPIO_MAPPER_H_ */

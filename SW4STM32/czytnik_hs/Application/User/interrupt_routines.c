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

#include <stdint.h>
#include <assert.h>

#include "project_constants.h"
#include "wiegand.h"
#include "stm32f0xx_hal.h"
#include "gpio_mapper.h"
#include "zone.h"
#include "uart_controller.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	uint8_t channel_id = GPIO_To_Wiegand_Channel(GPIO_Pin);
	uint8_t bit = GPIO_To_Wiegand_Bit(GPIO_Pin);

	Wiegand_HandleTransmission(channel_id, bit);
}

void HAL_SYSTICK_Callback(void)
{
	Wiegand_SysTickHandler();
	Zone_SysTickHandler();
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	UART_Controller_TxCpltCallback(huart);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	UART_Controller_RxCpltCallback(huart);
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	assert(0);
}

void Wiegand_Callback(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number)
{
	Zone_Callback(channel_id, length, card_number);
}

void Zone_Callback_CardRead(Wiegand_Channel_NumberTypeDef channel_id, uint8_t length, Wiegand_CardNumberTypeDef card_number)
{
	UART_Controller_SendCard(channel_id, length, card_number);
}

void Zone_Callback_KeyPress(Wiegand_Channel_NumberTypeDef channel_id, Zone_Keypress_KeyTypeDef key)
{
	UART_Controller_SendKey(channel_id, key);
}

void Zone_Callback_Tamper(Wiegand_Channel_NumberTypeDef channel_id)
{
	UART_Controller_SendTamper(channel_id);
}

// following functions have data from outside - we have to check it!
void UART_Controller_Action_Accept(Wiegand_Channel_NumberTypeDef channel_id)
{
	if(channel_id >= PROJECT_CONSTANT_CHANNELS_NUMBER)
	{
		return;
	}

	Zone_Accept(channel_id);
}

void UART_Controller_Action_Reject(Wiegand_Channel_NumberTypeDef channel_id)
{
	if(channel_id >= PROJECT_CONSTANT_CHANNELS_NUMBER)
	{
		return;
	}

	Zone_Reject(channel_id);
}

void UART_Controller_Action_Ping()
{
	UART_Controller_SendPong();
}


void UART_Controller_SendStart(void)
{
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
}

void UART_Controller_SendStop(void)
{
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
}

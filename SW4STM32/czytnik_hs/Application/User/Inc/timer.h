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

#ifndef APPLICATION_USER_INC_TIMER_H_
#define APPLICATION_USER_INC_TIMER_H_

#include <stdint.h>

#define TIMER_MAX_TIMERS 20

typedef uint16_t Timer_TimerTicksTypeDef;
typedef void (*Timer_TimerCallbackFunctionTicksTypeDef)(void*);
typedef uint8_t Timer_IdTypeDef;

typedef struct Timer_TimerTimer Timer_TimerTimerTypeDef;
struct Timer_TimerTimer {
	Timer_TimerTicksTypeDef tics;

	Timer_TimerCallbackFunctionTicksTypeDef callback;
	void *data;

	Timer_TimerTimerTypeDef *next;
};

typedef struct {
	Timer_IdTypeDef last_id;
	Timer_TimerTimerTypeDef *active_timer;
	uint8_t lock;

	Timer_TimerTimerTypeDef timers_arr[TIMER_MAX_TIMERS];
} Timer_TimerTypeDef;


void Timer_Init(Timer_TimerTypeDef *timers);

void Timer_SysTickHandler(Timer_TimerTypeDef *timers);

void Timer_Start(Timer_TimerTypeDef *timers, Timer_TimerTicksTypeDef ticks, Timer_TimerCallbackFunctionTicksTypeDef callback, void *data);
void Timer_Cancel(Timer_TimerTypeDef *timers, Timer_TimerCallbackFunctionTicksTypeDef callback, void *data);

#endif /* APPLICATION_USER_INC_TIMER_H_ */

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

#include "timer.h"


static void Timer_InitTimerStruct(Timer_TimerTimerTypeDef *timer)
{
	timer->callback = 0;
	timer->next = 0;
}

static Timer_TimerTimerTypeDef *Timer_GetTimer(Timer_TimerTypeDef *timers, Timer_IdTypeDef id)
{
	assert(id < TIMER_MAX_TIMERS);

	return &timers->timers_arr[id];
}

static Timer_TimerTimerTypeDef *Timer_TimerGetFree(Timer_TimerTypeDef *timers)
{
	int i;
	for(i = 0; i < TIMER_MAX_TIMERS; ++i)
	{
		Timer_TimerTimerTypeDef *timer = Timer_GetTimer(timers, i);

		if(! timer->callback)
			return timer;
	}

	return 0;
}

void Timer_Init(Timer_TimerTypeDef *timers)
{
	timers->active_timer = 0;
	timers->lock = 0;

	int i;
	for(i = 0; i < TIMER_MAX_TIMERS; ++i)
	{
		Timer_InitTimerStruct(Timer_GetTimer(timers, i));
	}
}

static void Timer_RemoveTimer(Timer_TimerTypeDef *timers, Timer_TimerTimerTypeDef *timer)
{
	if(timers->active_timer == timer)
	{
		timers->active_timer = timer->next;
	}
	else
	{
		Timer_TimerTimerTypeDef *parent_timer = timers->active_timer;

		while(parent_timer->next != timer)
		{
			if(! parent_timer->next)
				return;

			parent_timer = parent_timer->next;
		}

		parent_timer->next = timer->next;
	}


	Timer_InitTimerStruct(timer);
}

static uint8_t Timer_ProcessTimer(Timer_TimerTimerTypeDef *timer)
{
	if(--timer->tics)
		return 0;

	timer->callback(timer->data);

	return 1;
}

// called from interrupt
void Timer_SysTickHandler(Timer_TimerTypeDef *timers)
{
//	if(timers->active_timer == 0)
//		return;

	if(timers->lock)
		return;

	Timer_TimerTimerTypeDef *timer = timers->active_timer;

	while(timer)
	{
		if(Timer_ProcessTimer(timer))
		{
			// timer has ended
			Timer_RemoveTimer(timers, timer);

			break;
		}

		timer = timer->next;
	}
}

void Timer_Start(Timer_TimerTypeDef *timers, Timer_TimerTicksTypeDef ticks, Timer_TimerCallbackFunctionTicksTypeDef callback, void *data)
{
	timers->lock = 1;

	Timer_TimerTimerTypeDef *timer = Timer_TimerGetFree(timers);

	assert(timer);

	timer->callback = callback;
	timer->data = data;
	timer->tics = ticks;

	if(timers->active_timer == 0)
	{
		timers->active_timer = timer;
	}
	else
	{
		Timer_TimerTimerTypeDef *parent_timer = timers->active_timer;

		while(parent_timer->next)
		{
			parent_timer = parent_timer->next;
		}

		parent_timer->next = timer;
	}

	timers->lock = 0;
}

void Timer_Cancel(Timer_TimerTypeDef *timers, Timer_TimerCallbackFunctionTicksTypeDef callback, void *data)
{
	timers->lock = 1;

	Timer_TimerTimerTypeDef *timer = timers->active_timer;

	while(timer)
	{
		if(timer->callback == callback && timer->data == data)
		{
			Timer_RemoveTimer(timers, timer);

			break;
		}

		timer = timer->next;
	}

	timers->lock = 0;
}

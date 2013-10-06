/*
jk
*/

#include "BrewTask.h"

BrewTask::BrewTask(uint8_t taskID, uint32_t taskValue, uint32_t startTime, uint8_t active)
	:_taskID(taskID), _taskValue(taskValue), _startTime(startTime), _active(active)
{
}


int8_t BrewTask::getTaskID()
{

return _taskID;
}

uint32_t BrewTask::getTaskValue()
{

return _taskValue;
}

uint32_t BrewTask::getStartTimeMinutes()
{

return (uint32_t) _startTime/1000;
}

uint32_t BrewTask::getStartTime()
{

return _startTime;
}

uint8_t BrewTask::getActive()
{

return _active;
}

void BrewTask::setActive(uint8_t active)
{
	_active = active;
}

uint8_t BrewTask::update(uint32_t updateTime)
{

	if (_startTime > updateTime)
	{
		_startTime -= updateTime;
	}
	else
	{
		if (_active > isactive)
		{
			_active = rip;
		}
		else
		{
		 	_active = runbutreadytodelete;
		}
		_startTime = 0;
		
	}

return _active;
}


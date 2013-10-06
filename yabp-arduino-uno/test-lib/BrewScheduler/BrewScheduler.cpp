/*
jk
*/

#include "BrewScheduler.h"

BrewScheduler::BrewScheduler()
{
	sizeOfTasks = 0;
}

uint16_t BrewScheduler::addTask(uint8_t taskID, uint32_t taskValue, uint32_t startTime, uint8_t active)
{
	_theMagicBrewTaskScheduler[sizeOfTasks] = new BrewTask(taskID, taskValue, startTime, active);
	sizeOfTasks++;
	return 4;
}

bool BrewScheduler::removeTaskIndex(uint16_t taskIndex)
{
	bool retrun_value = false;

	if (taskIndex < sizeOfTasks)
	{
		delete _theMagicBrewTaskScheduler[taskIndex-1];
		_theMagicBrewTaskScheduler[taskIndex-1] = _theMagicBrewTaskScheduler[sizeOfTasks-1] ;
		sizeOfTasks --;
		retrun_value = true;
	}

return retrun_value;
}

uint32_t BrewScheduler::listTask()
{
	for (int i=0; i<sizeOfTasks; i++)
	{
		Serial.print("\n\r");
		Serial.print(_theMagicBrewTaskScheduler[i]->getTaskID());	
		Serial.print("\n\r");

	}


return 4;
}

uint16_t BrewScheduler::getSizeOfTasks()
{
return sizeOfTasks; 
}

uint16_t BrewScheduler::findNextTask(uint8_t taskID)
{
return 4;
}

void BrewScheduler::updateBrewScheduler()
{

}

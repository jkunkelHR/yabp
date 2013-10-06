/*
jk
*/

#ifndef BrewScheduler_h
#define BrewScheduler_h

#include "BrewTask.h"
#include <inttypes.h>
#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif



class BrewScheduler
{
public:
  	BrewScheduler();

	uint16_t addTask(uint8_t taskID, uint32_t taskValue, uint32_t startTime, uint8_t active); 		//returns taskIndex
	bool removeTaskIndex(uint16_t taskIndex);
	uint32_t listTask();
	uint16_t findNextTask(uint8_t taskID);
	void updateBrewScheduler();
	uint16_t getSizeOfTasks();
//private:
	BrewTask* _theMagicBrewTaskScheduler[256];
	uint16_t sizeOfTasks;

};
#endif

/*
jk
*/

#ifndef BrewTask_h
#define BrewTask_h


#include <inttypes.h>
#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif

#define COUNT_HOTPLATES 0
#define HOTPLATE_1 0
//  overwrite your defines your Hotplates ... 


#define sleeping  		1  //nothing to do
#define isactive 		2  //do the task next time again
#define runbutreadytodelete	3  //do the task this time and next time the task will be destructed
#define rip			4  //the task ist destructed nothing to do


class BrewTask
{
public:

  	BrewTask(uint8_t taskID, uint32_t taskValue, uint32_t startTime, uint8_t active);
  	int8_t getTaskID();
  	uint32_t getTaskValue();
   	uint32_t getStartTimeMinutes();
	uint32_t getStartTime();
	uint8_t getActive();
	void setActive(uint8_t active);
	uint8_t update(uint32_t updateTime);

private:
  	uint8_t _taskID;
  	uint32_t _taskValue;
	uint32_t _startTime;
	uint8_t _active;


 
};

#endif

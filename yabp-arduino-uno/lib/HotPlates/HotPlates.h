/*
jk
*/

#ifndef HotPlates_h
#define HotPlates_h

#include <inttypes.h>
#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif

//#define COUNT_HOTPLATES 0
//#define HOTPLATE_1 0
//  overwrite your defines your Hotplates ... 

class Hotplates
{
public:
	Hotplates(uint8_t hotplate_1, uint8_t count);
	void offHotplate(uint8_t hotPlate);
	void onHotplate(uint8_t hotPlate);
	void offHotplates();
	void onHotplates(uint8_t delayInSeconds);
	bool getHotplate(uint8_t hotPlate);
	uint8_t getCount() const;
	void setCount(uint8_t count);
	uint8_t getHotplate1() const;
	void setHotplate1(uint8_t hotplate1);

private:
	uint8_t count;
	uint8_t hotplate_1;
};



#endif

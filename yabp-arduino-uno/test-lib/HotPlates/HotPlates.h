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

#define COUNT_HOTPLATES 0
#define HOTPLATE_1 0
//  overwrite your defines your Hotplates ... 


void initHotplates();
void offHotplate(uint8_t hotPlate);
void onHotplate(uint8_t hotPlate);
void offHotplates();
void onHotplates(uint8_t delayInSeconds);


#endif

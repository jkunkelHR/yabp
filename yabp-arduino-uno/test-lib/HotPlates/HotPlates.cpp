/*
jk
*/

#include "HotPlates.h"
void initHotplates()
{
  for (uint8_t i = HOTPLATE_1; i < HOTPLATE_1 + COUNT_HOTPLATES ; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW); // off
  }
}

void offHotplate(uint8_t hotPlate)
{
    digitalWrite(hotPlate, LOW);
}

void onHotplate(uint8_t hotPlate)
{
    digitalWrite(hotPlate, HIGH);
}

void offHotplates()
{
  for (uint8_t i = HOTPLATE_1; i < HOTPLATE_1 + COUNT_HOTPLATES ; i++)
  {
    digitalWrite(i, LOW); // off
  }
}
void onHotplates(uint8_t delayInSeconds)
{
  for (uint8_t i = HOTPLATE_1; i < HOTPLATE_1 + COUNT_HOTPLATES ; i++)
  {
    	digitalWrite(i, LOW); // off
	if ( i != HOTPLATE_1 + COUNT_HOTPLATES - 1)
		delay(delayInSeconds * 1000);
  }
}


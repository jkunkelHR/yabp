/*
jk
*/

#include "HotPlates.h"
Hotplates::Hotplates(uint8_t hotplate_1, uint8_t count)
{
	this->hotplate_1 = hotplate_1;
	this->count = count;

  for (uint8_t i = hotplate_1; i < hotplate_1 + count ; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW); // off
  }
}

void Hotplates::offHotplate(uint8_t hotPlate)
{
    digitalWrite(hotPlate, LOW);
}

void Hotplates::onHotplate(uint8_t hotPlate)
{
    digitalWrite(hotPlate, HIGH);
}

void Hotplates::offHotplates()
{
  for (uint8_t i = hotplate_1; i < hotplate_1 + count ; i++)
  {
    digitalWrite(i, LOW); // off
  }
}
void Hotplates::onHotplates(uint8_t delayInSeconds)
{
  for (uint8_t i = hotplate_1; i < hotplate_1 + count ; i++)
  {
    	digitalWrite(i, HIGH); // off
	if ( i != hotplate_1 + count - 1)
		delay(delayInSeconds * 1000);
  }
}

bool Hotplates::getHotplate(uint8_t hotPlate)
{

	return digitalRead(hotPlate);
}

uint8_t Hotplates::getCount() const {
	return count;
}

void Hotplates::setCount(uint8_t count) {
	this->count = count;
}

uint8_t Hotplates::getHotplate1() const {
	return hotplate_1;
}

void Hotplates::setHotplate1(uint8_t hotplate1) {
	hotplate_1 = hotplate1;
}

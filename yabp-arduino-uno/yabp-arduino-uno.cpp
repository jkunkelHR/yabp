// Do not remove the include below
#include "yabp-arduino-uno.h"



// define FUNKTIONS
#define SET_HOTPLATE_NOx_ON             	1
#define SET_HOTPLATE_NOx_OFF        		2
#define GET_HOTPLATE_NOx_OFF        		3
#define SET_ALL_HOTPLATES_OFF           	4
#define GET_TEMP_NOx         				5

// define IO Ports
#define LED 					13
#define ONE_WIRE_BUS 			3
#define HOTPLATE_1 				4
#define HOTPLATE_2 				5
#define HOTPLATE_3 				6
#define HOTPLATE_4 				7

// OTHER DEFINES
#define COUNT_HOTPLATES 			4

// GLOBAL VARIABLES
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress firstSensor = { 0x28, 0xE6, 0x78, 0xBF, 0x04, 0x00, 0x00, 0x43 };
DeviceAddress secondSensor = { 0x28, 0xD4, 0x45, 0xBF, 0x04, 0x00, 0x00, 0xA8 };
Hotplates hotplates(HOTPLATE_1, COUNT_HOTPLATES);


//The setup function is called once at startup of the sketch
void setup()
{
	 pinMode(LED, OUTPUT);
	  // start serial port
	  Serial.begin(9600);

	  // start OneWire
	  sensors.begin();
	  // set selectivity to 10BIT == 1024
	  sensors.setResolution(firstSensor, 10);
	  sensors.setResolution(secondSensor, 10);
	  // init HotPlate CLass to
	  hotplates.offHotplates();
}

// The loop function is called in an endless loop
void loop()
{
	 digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
	  delay(100);               // wait for a second
	  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
	  delay(1000);               // wait for a second
}




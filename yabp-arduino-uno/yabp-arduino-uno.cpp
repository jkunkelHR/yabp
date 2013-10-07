// Do not remove the include below
#include "yabp-arduino-uno.h"



// define FUNKTIONS
// funktioncall 1-1; or 5-63; ...
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

#define SERIAL_IN_SIZE 	10
char serial_in[SERIAL_IN_SIZE];
size_t read_serial_in_size = 0;
FunctionCall functioncall = {0 , 0};

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
	 //digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
	 //delay(100);               // wait for a second
	 //digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
	 //delay(1000);               // wait for a second
	 if(setFunction())
		 executeFunction();
}


bool setFunction()
{
	functioncall[0] = 0;
	functioncall[1] = 0;
	bool return_value = false;
	Serial.print("---check function\n\r");
	 if (Serial.available())
	 {
		 // Serial.readBytesUntil(character, buffer, length)
		 read_serial_in_size = Serial.readBytesUntil(';', serial_in, SERIAL_IN_SIZE);
		 if(read_serial_in_size)
		 {
			 if(
					 ((uint8_t)serial_in[0] - (uint8_t) '0' >= SET_HOTPLATE_NOx_ON)
					 &&
					 ((uint8_t)serial_in[0] - (uint8_t) '0' <= GET_TEMP_NOx)
				)
			 {
				 functioncall[0] = (uint8_t)serial_in[0] - (uint8_t) '0';
				 for (uint8_t i = 2 ; i < read_serial_in_size; i++)
				 {
					 if (isNum((uint8_t)serial_in[i]))
					 {
						 functioncall[1] =  (functioncall[1] * 10) + ((uint8_t)serial_in[i] - (uint8_t) '0');
					 }
				 }

				/*Serial.print(functioncall[0]);
				Serial.print("\n\r");
				Serial.print(functioncall[1]);
				Serial.print("\n\r");
				*/
				 Serial.print("---function OK \n\r");
				 return_value = true;
			 }
		 }
	 }
	return return_value;
}

bool executeFunction()
{
	bool return_value = true;
	Serial.print("---check execution\n\r");
	switch (functioncall[0])
				    {
				    /*
				     * #define SET_HOTPLATE_NOx_ON             	1
				     * #define SET_HOTPLATE_NOx_OFF        		2
				     * #define GET_HOTPLATE_NOx_OFF        		3
				     * #define SET_ALL_HOTPLATES_OFF           	4
				     * #define GET_TEMP_NOx
				     * */
				    case SET_HOTPLATE_NOx_ON:
				    	Serial.print("CALL SET_HOTPLATE_NOx_ON ");
				    	Serial.print(functioncall[1]);
				    	Serial.print("\n\r");

				      break;
				    case SET_HOTPLATE_NOx_OFF:
				    	Serial.print("CALL SET_HOTPLATE_NOx_OFF ");
				    	Serial.print(functioncall[1]);
				    	Serial.print("\n\r");

				      break;
				    case GET_HOTPLATE_NOx_OFF:
				    	Serial.print("CALL GET_HOTPLATE_NOx_OFF ");
				    	Serial.print(functioncall[1]);
				    	Serial.print("\n\r");

				      break;
				    case SET_ALL_HOTPLATES_OFF:
				    	Serial.print("CALL SET_ALL_HOTPLATES_OFF ");
				    	Serial.print(functioncall[1]);
				    	Serial.print("\n\r");

				      break;
				    case GET_TEMP_NOx:
				    	Serial.print("CALL GET_TEMP_NOx ");
				    	Serial.print(functioncall[1]);
				    	Serial.print("\n\r");

				      break;
				    default:
				    	Serial.print("---execute function FALSE \n\r");
				    	return_value = false;
				    	break;
				    }
	return return_value;
}

bool isNum(uint8_t num)
{
	bool return_value =false;

	if ((num - (uint8_t) '0' >= 0) && (num  - (uint8_t) '0' <= 9))
	{
		return_value = true;
	}

	return return_value;
}

//Serial.write((uint8_t*)serial_in, read_serial_in_size);
//Serial.write("\n\r");

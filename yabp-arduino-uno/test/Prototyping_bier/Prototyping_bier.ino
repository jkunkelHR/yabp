
#include <OneWire.h>
#include <DallasTemperature.h>
#include <HotPlates.h>
#include <BrewTask.h>
#include <BrewScheduler.h>

// Data wire is plugged into pin 3 on the Arduino
#define ONE_WIRE_BUS 3


// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

BrewScheduler bs;
//BrewTask* bt;
int g = 0;

// testdevice of JK
DeviceAddress firstSensor = { 0x28, 0xE6, 0x78, 0xBF, 0x04, 0x00, 0x00, 0x43 };
DeviceAddress secondSensor = { 0x28, 0xD4, 0x45, 0xBF, 0x04, 0x00, 0x00, 0xA8 };

#define HOTPLATE_1 				4
#define HOTPLATE_2 				5
#define HOTPLATE_3 				6
#define HOTPLATE_4 				7
// define your Hotplates ...
#define COUNT_HOTPLATES 			4


//Task ID's 
#define SWITCH_HOTPLATE_NOx_ON             	1
#define SWITCH_HOTPLATE_NOx_OFF        		2  
#define SWITCH_ALL_HOTPLATES_OFF           	3 
#define HEAT_UNTIL_TEMP         		4 
#define REST_TEMP_FOR_X_MINUTES       		5 


#define HYSTERESIS				2 	// hysteresis in C°

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
  // set the resolution to 10 bit 
  sensors.setResolution(firstSensor, 10);
  sensors.setResolution(secondSensor, 10);
  initHotplates();

}


void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  if (tempC == -127.00) {
    Serial.print("Error getting temperature");
  } else {
    Serial.print("C: ");
    Serial.print(tempC);
  }
}


void printAllTemperatures()
{
  //Serial.print("Getting temperatures...\n\r");
  Serial.print("first temperature is: ");
  printTemperature(firstSensor);
  Serial.print("\n\r");
  Serial.print("second temperature is: ");
  printTemperature(secondSensor);
  Serial.print("\n\r");
  Serial.print("\n\r");
  Serial.print("average temperature is: ");
  Serial.print((sensors.getTempC(firstSensor)+ sensors.getTempC(secondSensor))/2);
  Serial.print("\n\r\n\r");

}




void loop(void)
{ 
  delay(200);
  sensors.requestTemperatures();
  printAllTemperatures();
  
    g++;
 /* bt = new BrewTask(g,g,g,g);
  Serial.print(bt->getStartTime());
*/
  bs.addTask(g,g,g,g);
  bs.listTask();
  Serial.print(bs.getSizeOfTasks());
  if (g > 20)
    bs.removeTaskIndex(5);
  

}


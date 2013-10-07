// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef yabparduinouno_H_
#define yabparduinouno_H_
#include "Arduino.h"


#include "lib/HotPlates/HotPlates.h"
#include "lib/OneWire/OneWire.h"
#include "lib/DallasTemperature/DallasTemperature.h"

typedef uint8_t FunctionCall[2];

#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif
bool setFunction();
bool executeFunction();
bool isNum(uint8_t num);



//Do not add code below this line
#endif /* yabp-arduino-uno_H_ */

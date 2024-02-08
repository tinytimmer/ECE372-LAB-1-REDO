// Author:      Carmen Timmer   
// Net ID:      cvtimmer@arizona.edu   
// Date:        Jan. 19, 2024          
// Assignment:     Lab 1
//----------------------------------------------------------------------//
#ifndef LED_H
#define LED_H

/*
note to self: every component must have a '.h' file
    really all this file does is help the correspodning component .cpp file by declring these functions here
    Would edit these if a pin is being configured as an input that the .cpp file will use
*/

// initLED which returns void and takes no parameters
void initLED();

// turnOnLED which returns void and takes in an unsigned int parameter called led
void turnOnLED();

// turnOffLED which returns void and takes in an unsigned int parameter called led
void turnOffLED();

// runLED which returns void and takes in an unsigned int parameter called led
void runLED(unsigned int led);

#endif

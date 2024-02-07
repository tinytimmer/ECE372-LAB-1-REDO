// Author:      Carmen Timmer   
// Net ID:      cvtimmer@arizona.edu   
// Date:        Jan. 19, 2024           
// Assignment:     Lab 1
//----------------------------------------------------------------------//
#include <switch.h>
#include <avr/io.h>

// initSwitch returns void and takes no parameters
void initSwitch(){
    DDRA &= ~(1 << PA0); //sets pin22 as an input for the switch
    PORTA |= (1 << PA0); //this SHOULD enable the pull up resistor at pin22, Ask TA about this
}

bool isSwitchedPressed() {
    return!(PINA & (1 << PA0)); //if switch is pressed it returns true and starts to slow down the blinking lights, otherwise it false and does nothing
}
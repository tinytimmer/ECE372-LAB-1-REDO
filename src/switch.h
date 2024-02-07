// Author:      Carmen Timmer   
// Net ID:      cvtimmer@arizona.edu   
// Date:        Jan. 19, 2024        
// Assignment:     Lab 1
//----------------------------------------------------------------------//
#ifndef SWITCH_H
#define SWITCH_H

/*
note to self: 
    this switch should creete two differnet conditions: 1)Slo-mo LED when pressed and hold OR 2) normal LED speed when released
    test 2
*/

// initSwitch returns void and takes no parameters
void initSwitch();

/*code needs to check if button/switch has been pressed or not, best way to do it is
    to treat it as a boolean
*/
bool isSwitchedPressed(); 

#endif

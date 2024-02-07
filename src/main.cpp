// Author:      Carmen Timmer   
// Net ID:      cvtimmer@arizona.edu   
// Date:        Jan. 19, 2024   
// Assignment:     Lab 1
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"

#define SHORT_DELAY 100
#define LONG_DELAY 1000

int main(){
  //call the functions for LED and switch/button, also will set up the delay and the LED we'll start with
      initLED();
      initSwitch();

      unsigned int led = 2;
      unsigned int delay = SHORT_DELAY;

  while(1){
    /*turnOnLED();
    _delay_ms(LONG_DELAY);
    turnOffLED();
    _delay_ms(SHORT_DELAY);*/
    //runLED(led); // update LED
       /*  if (isSwitchedPressed()) { // if switch is pressed, slow down blinking
            
        } else {
           
        } */
      runLED(led);
      _delay_ms(delay);

      //check for the switch being pressed here
      if (isSwitchedPressed())
        {
          delay = LONG_DELAY;//slows down the rate the sequences turns on the LEDS, pattern should not change
        }
      else {
          delay = SHORT_DELAY; //resumes original rate
        }
      
      //next will make the LED pattern go back to the beginning by going backwards when it reaches the innermost LEDs towards the outermost LED
      if (led == 10)
        {
          for (unsigned int i = 10; i >= 2; i -= 2)
          {
            runLED(i);
              _delay_ms(delay);
            runLED(i - 1);
              _delay_ms(delay);
          }
        }
      //otherwise it should return to the original pattern once it gets to the outermost LEDs and it begins the cycle again
      else if (led == 2) //back to normal blinking speed and sequence
        {
          for (unsigned int i = 2; i <= 10; i += 2)
          {
            runLED(i);
              _delay_ms(delay);
            runLED(i + 1);
              _delay_ms(delay);
          }
        }

    //this section will move to the next pair of LEDS in sequence ( i think but im not sure based on the error Im getting now)
    led += 2;
    if (led > 10)
      {
        led = 2;
      }  
    
    /*   runLED(led);
      if(isSwitchedPressed())
        {
          _delay_ms(LONG_DELAY); //if switch is pressed and held down, slow blinking sequence starts
        }
      else 
        {
          _delay_ms(SHORT_DELAY); //otherwise it should return to the normal speed
        } */

  } 

  return 0;
}



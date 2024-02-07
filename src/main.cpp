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

      unsigned int led = 4;
      unsigned int delay = SHORT_DELAY;

  while(1){
    //turnOnLED( 1 );

   //runs the function that turns on the LEDs
    runLED(led);
    _delay_ms(delay);

    //check for the switch being pressed here
    if (isSwitchedPressed())
      {
        delay = LONG_DELAY; //slows down the rate the sequences turns on the LEDS, pattern should not change
      }
    else {
        delay = SHORT_DELAY;
      }
    
    //next will make the LED pattern go back to the beginning by going backwards when it reaches the innermost LEDs
    if (led == 10)
      {
        for (unsigned int i = 10; i >= 2; i -= 2)
        {
          runLED(i);
            _delay_ms(delay);
          runLED(i + 1);
            _delay_ms(delay);
        }
      }
    //otherwise it should return to the original pattern once it gets to the outermost LEDs
    else if (led == 2)
      {
        for (unsigned int i = 2; i <= 10; i += 2)
        {
          runLED(i);
            _delay_ms(delay);
          runLED(i + 1);
            _delay_ms(delay);
        }
      }

  //this section will move to the next pair of LEDS in sequence
  led += 2;
  if (led >10)
    {
      led = 2;
    }

  }

  return 0;
}

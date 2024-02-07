// Author:      Carmen Timmer   
// Net ID:      cvtimmer@arizona.edu   
// Date:        Jan. 19, 2024           
// Assignment:     Lab 1
//----------------------------------------------------------------------//
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

/*
Note to self: base on lecture will use bit operations to change which LED is on or odd based on
    the pin its connected to. This is specific to the board were using in this class.
    Audrino examples are much different, but will function the same 
*/


// initLED which returns void and takes no parameters
void initLED(){
  DDRG |= (1 << DDG5); //pin 4
  DDRE |= (1 << DDE3); //pin 5
  DDRH |= (1 << DDH3); //(in hexidecimal) this will set all the pins from pin 6-9 as output pins where the LEDs are at. 
  DDRH |= (1 << DDH4);
  DDRH |= (1 << DDH5);
  DDRH |= (1 << DDH6);
  DDRB |= (1 << DDB4);  //PIN 10 & 11
  DDRB |= (1 << DDB5);
  //PORTG = 0x00; //sets all the LED's inital values to low, bascially off for pins 4-11. Recall: Value 0x00 will turn them OFF, 0xFF will turn them ON
  
}

// turnOnLED which returns void and takes in an unsigned int parameter called led
void turnOnLED(unsigned int led){
  PORTG |= (1 << PORTG5); //will let the corressponding LED pin to high aka ON
  PORTE |= (1 << PORTE3); 
  PORTH |= (1 << PORTH3); 
  PORTH |= (1 << PORTH4);
  PORTH |= (1 << PORTH5); 
  PORTH |= (1 << PORTH6);
  PORTB |= (1 << PORTB4);
  PORTB |= (1 << PORTB5);
}

// turnOffLED which returns void and takes in an unsigned int parameter called led
void turnOffLED(unsigned int led){
  PORTG &= ~(1 << PORTG5); //turns OFF the corressponding LED aka sets the pin back down to low
  PORTE &= ~(1 << PORTE3); 
  PORTH &= ~(1 << PORTH3); 
  PORTH &= ~(1 << PORTH4);
  PORTH &= ~(1 << PORTH5);
  PORTH &= ~(1 << PORTH6);
  PORTB &= ~(1 << PORTB4); 
  PORTB &= ~(1 << PORTB5);
}

// runLED which returns void and takes in an unsigned int parameter called led
void runLED(unsigned int led){
  turnOffLED(led - 1); //will turn OFF the last LED using the function above
  turnOnLED(led); //like the function name says it will turn on the current LED

  //to get the sequence to start from the beginning this if-else statement will (hopefully) do so
  if(led == 11){
    _delay_ms(100); //waits for 100ms
    turnOffLED(led);
    turnOnLED(4); //after turning off the last LED, this will turn on the first LED
    led = 4; //time to reset the LED counter
  }
  else { //as long as its not he last LED, it will increase counter and continue to move forward with sequence
    _delay_ms(100);
    led++;
  }
}

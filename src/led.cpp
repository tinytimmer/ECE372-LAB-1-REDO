// Author:      Carmen Timmer   
// Net ID:      cvtimmer@arizona.edu   
// Date:        Jan. 19, 2024           
// Assignment:     Lab 1
//----------------------------------------------------------------------//
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"


/*
Note to self: base on lecture will use bit operations to change which LED is on or odd based on
    the pin its connected to. This is specific to the board were using in this class.
    Audrino examples are much different, but will function the same 
*/


// initLED which returns void and takes no parameters
void initLED(){
  DDRG |= (1 << DDG5); //pin 4 - 11
  DDRE |= (1 << DDE3); //pin 5
  DDRH |= (1 << DDH3); //pin 6 (in hexidecimal) this will set all the pins from pin 6-9 as output pins where the LEDs are at. 
  DDRH |= (1 << DDH4); //pin 7
  DDRH |= (1 << DDH5); //pin 8
  DDRH |= (1 << DDH6); //pin 9
  DDRB |= (1 << DDB4); //pin 10
  DDRB |= (1 << DDB5); //pin 11
  //PORTG = 0x00; //sets all the LED's inital values to low, bascially off for pins 4-11. Recall: Value 0x00 will turn them OFF, 0xFF will turn them ON
  
}


// turnOnLED which returns void and takes in an unsigned int parameter called led
void turnOnLED(unsigned int led){
 //will let the corressponding LED pin to high aka ON 
 /*  PORTG |= (1 << PORTG5); 
  PORTE |= (1 << PORTE3); 
  PORTH |= (1 << PORTH3); 
  PORTH |= (1 << PORTH4);
  PORTH |= (1 << PORTH5);
  PORTH |= (1 << PORTH6);
  PORTB |= (1 << PORTB4); 
  PORTB |= (1 << PORTB5);  */ 
 
 
 if (led == 0) //pin 4 & 11
  {
    //_delay_ms(100);
    PORTG |= (1 << PORTG5);
    PORTB |= (1 << PORTB5);
    //_delay_ms(100); 
  }
  if (led == 1) //pin 5 & 10
  {
    //_delay_ms(100);
    PORTE |= (1 << PORTE3);
    PORTB |= (1 << PORTB4);
    //_delay_ms(100); 
  }
  if (led == 2) //pin 6 & 9
  {
    //_delay_ms(100);
    PORTH |= (1 << PORTH3); 
    PORTH |= (1 << PORTH6);
    //_delay_ms(100); 
  }
  if (led == 3) //pin 7 & 8
  {
    //_delay_ms(100);
    PORTH |= (1 << PORTH4);
    PORTH |= (1 << PORTH5);
    //_delay_ms(100);  
  }    

}

// turnOffLED which returns void and takes in an unsigned int parameter called led
void turnOffLED(){
  //turns OFF the corressponding LED aka sets the pin back down to low
  PORTG &= ~(1 << PORTG5); 
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
    /* turnOnLED();
    _delay_ms(100);
    turnOffLED(); */
if (led == !(PINA & (1 << PA0))) //to stay in the short delay
{
  turnOnLED(0);  //like the function name says it will turn on the current LED
  _delay_ms(100); //wait a bit
   turnOffLED();//will turn OFF the last LED using the function above
   //isSwitchedPressed();
    
  turnOnLED(1); 
  _delay_ms(100); //wait a bit
  turnOffLED();

  turnOnLED(2);  
  _delay_ms(100); //wait a bit
  turnOffLED();

  turnOnLED(3);  
  _delay_ms(100); //wait a bit
  turnOffLED();

  turnOnLED(2);  
  _delay_ms(100); //wait a bit
  turnOffLED();

  turnOnLED(1);  
  _delay_ms(100); //wait a bit
  turnOffLED();

  turnOnLED(0);  
  _delay_ms(100); //wait a bit
  turnOffLED();
}
if (led == (PINA & (1 << PA0))) //to activate the long delay
{
  turnOnLED(0);  //like the function name says it will turn on the current LED
  _delay_ms(1000); //wait a bit
   turnOffLED();//will turn OFF the last LED using the function above
    
  turnOnLED(1); 
  _delay_ms(1000); //wait a bit
  turnOffLED();

  turnOnLED(2);  
  _delay_ms(1000); //wait a bit
  turnOffLED();

  turnOnLED(3);  
  _delay_ms(1000); //wait a bit
  turnOffLED();

  turnOnLED(2);  
  _delay_ms(1000); //wait a bit
  turnOffLED();

  turnOnLED(1);  
  _delay_ms(1000); //wait a bit
  turnOffLED();

  turnOnLED(0);  
  _delay_ms(1000); //wait a bit
  turnOffLED();
}


      
  //to get the sequence to start from the beginning this if-else statement will (hopefully) do so
  //UPDATE: decided to put a similar sectino of code in main.cpp to run the sequence and keep track of it
  /* if(led == 8){ //check why this aint working, this is set for 10 LED not 8 LED
    turnOffLED();
    _delay_ms(100); //waits for 100ms
    turnOnLED(); //after turning off the last LED, this will turn on the first LED
    led = 2; //time to reset the LED counter
  }
  else { //as long as its not he last LED, it will increase counter and continue to move forward with sequence
    turnOffLED();
    _delay_ms(100);
    turnOnLED();
    led++;
  }  */
}

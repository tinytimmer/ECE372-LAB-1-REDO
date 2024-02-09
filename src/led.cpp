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
 if (led == 0) //pin 4 & 11
  {
    PORTG |= (1 << PORTG5);
    PORTB |= (1 << PORTB5);
  }
  if (led == 1) //pin 5 & 10
  {
    PORTE |= (1 << PORTE3);
    PORTB |= (1 << PORTB4);
  }
  if (led == 2) //pin 6 & 9
  {
    PORTH |= (1 << PORTH3); 
    PORTH |= (1 << PORTH6);
  }
  if (led == 3) //pin 7 & 8
  {
    PORTH |= (1 << PORTH4);
    PORTH |= (1 << PORTH5); 
  }  

}

// turnOffLED which returns void and takes in an unsigned int parameter called led
void turnOffLED(unsigned int led){
  //turns OFF the corressponding LED aka sets the pin back down to low
  if (led == 0) //pin 5 - 10 are off
  {
    PORTE &= ~(1 << PORTE3); 
    PORTH &= ~(1 << PORTH3); 
    PORTH &= ~(1 << PORTH4);
    PORTH &= ~(1 << PORTH5);
    PORTH &= ~(1 << PORTH6);
    PORTB &= ~(1 << PORTB4); 
  }
  if (led == 1) //pin 4, 6, 7, 8, 9, 11 off
  {
    PORTG &= ~(1 << PORTG5); 
    PORTH &= ~(1 << PORTH3); 
    PORTH &= ~(1 << PORTH4);
    PORTH &= ~(1 << PORTH5);
    PORTH &= ~(1 << PORTH6);
    PORTB &= ~(1 << PORTB5); 
  }
  if (led == 2) //pin 4, 5, 7, 8, 10 ,11 off
  {
    PORTG &= ~(1 << PORTG5);
    PORTE &= ~(1 << PORTE3); 
    PORTH &= ~(1 << PORTH4);
    PORTH &= ~(1 << PORTH5);
    PORTB &= ~(1 << PORTB4); 
    PORTB &= ~(1 << PORTB5);
  }
  if (led == 3) //pin 4, 5, 6, 9, 10, 11 off
  {
    PORTG &= ~(1 << PORTG5); 
    PORTE &= ~(1 << PORTE3); 
    PORTH &= ~(1 << PORTH3); 
    PORTH &= ~(1 << PORTH6);
    PORTB &= ~(1 << PORTB4); 
    PORTB &= ~(1 << PORTB5); 
  }

  /* PORTG &= ~(1 << PORTG5); 
  PORTE &= ~(1 << PORTE3); 
  PORTH &= ~(1 << PORTH3); 
  PORTH &= ~(1 << PORTH4);
  PORTH &= ~(1 << PORTH5);
  PORTH &= ~(1 << PORTH6);
  PORTB &= ~(1 << PORTB4); 
  PORTB &= ~(1 << PORTB5); */
}

// runLED which returns void and takes in an unsigned int parameter called led
 void runLED(){
      turnOnLED(0);  //like the function name says it will turn on the current LED
      //_delay_ms(100); //wait a bit
      turnOffLED(0);//will turn OFF the last LED using the function above
    
      turnOnLED(1); 
      //_delay_ms(100); //wait a bit
      turnOffLED(1);

      turnOnLED(2);  
      //_delay_ms(100); //wait a bit
      turnOffLED(2);

      turnOnLED(3);  
      //_delay_ms(100); //wait a bit
      turnOffLED(3);

      turnOnLED(2);  
      //_delay_ms(100); //wait a bit
      turnOffLED(2);

      turnOnLED(1);  
      //_delay_ms(100); //wait a bit
      turnOffLED(1);

      turnOnLED(0);  
      //_delay_ms(100); //wait a bit
      turnOffLED(0);
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

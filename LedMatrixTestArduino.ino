//We always have to include the library
#include "LedControlSoylentGraham.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
 #define DATAIN 2
 #define CLOCK 0
 #define LOAD_CS  1
LedControl lc=LedControl(DATAIN,CLOCK,LOAD_CS,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {

  pinMode(1, OUTPUT);
  for ( int i=0;  i<10; i++ )
  {
    digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);                       // wait for a second
    digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
    delay(50);                       // wait for a second
  }

  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}



void Chase() 
{
  for(int row=0;row<8;row++) 
  {
    for(int col=0;col<8;col++) 
    {
      lc.setLed(0,row,col,true);
      delay(20);
      lc.setLed(0,row,col,false);
    }
  }
}

void loop() 
{ 
  Chase();
}

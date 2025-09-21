#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "protos.h"


/*
Name: Matthew Muller
Date: 3/7/23
Lab 09
*/


void main(void) {
  /* put your own code here */
  
   // Initalizing I/O
   DDRC = 0x07;
   DDRP = 0x01;
   
   // Setting PORTC as all 0s
   PORTC = 0x00;
   
   // Caling Init Timer
   InitTimer();

  for(;;) {
  
    TaskScheduler();
  
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

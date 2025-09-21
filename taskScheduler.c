#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "defs.h"

/*
Name: Matthew Muller
Date: 3/7/23
Lab 09
*/

// File for Task Scheduler

// Variable Decleration
static unsigned char intervalCount = 0;
 
volatile unsigned int timer = 0;

unsigned char fastSpeed = 0;

extern unsigned int ledFiveHz = 0;
extern unsigned int ledTwoHz = 0;
extern unsigned int ledQuarterHz = 0;

// Initalize Task Scheduler Body
void InitTimer(void){

   // Enable global interrupts
   asm cli;
   
   // channel 0 set as output
   ECT_TIOS_IOS0 = 1;
 
   // Set TEN bit to enable timer
   ECT_TSCR1 |= 0x80;
 
   // enable channel 0 interrupt
   ECT_TIE_C0I = 1;
 
   // Set all bits to 1 to clear interrupt flags
   ECT_TFLG1 = 0xff;
 
   ECT_TSCR2 = 0x00;  
}

// Task Scheduler
void TaskScheduler(void){
   
   if(ledFiveHz > 0){
      
      // Decrementing task0 count
      ledFiveHz--;
      
      // call LED function
      FLIP_LED(0);   
   }
   
   if(ledTwoHz > 0){
      
      // Decrement task1 count
      ledTwoHz--;
      
      // call LED function
      FLIP_LED(1);
   }
   
   if(ledQuarterHz > 0){
      
      // Decrement task2 count
      ledQuarterHz--;
      
      // call LED function
      FLIP_LED(2);
   }
}

// Motor Task 1
void CheckMotorSpeed(void){

   // checking dip position
   if(PORTB & BIT0){
      
      // Fast speed to true 
      fastSpeed = 1;
         
   }
      
   else{
      // Fast speed to false 
      fastSpeed = 0;  
   }     
}

void CheckMotorPower(void){

   // If statement to check motor power
   if(fastSpeed & (intervalCount < 9)){
      
      // Turn Motor On         
      PTP = 1;
         
   }
   
   // Else If to check motor power
   else if(!fastSpeed & (intervalCount < 3)){
      
      // Turn Motor On 
      PTP = 1;
      
   }
   
   else{
       
      // Turn Motor Off
      PTP = 0;
   }
   
   if(intervalCount == 10){
    
      // Set back to 0
      intervalCount = 0;  
   }
   
}

// Service for timer ch0 interrupt
void interrupt TIM0(){
   
   // Reset the flag
   ECT_TFLG1_C0F = 1;
   
   // Set ECT_Timer compare register to 16000
   ECT_TC0 += 16000;
   
   // If statement to reset counter
   if((timer % 50) == 0){
      ledFiveHz++;         
   }
   
   // If statement to reset counter
   if((timer % 125) == 0){
      ledTwoHz++;
   }
   
   // If statement to reset counter
   if((timer % 1000) == 0){
      ledQuarterHz++;
   }
   
   // If statement to check dip switch position
   if((timer % 2500) == 0){
      // Call Motor Speed
      CheckMotorSpeed();   
   }
   
   if((timer % 1) == 0){
      //increment count var
      intervalCount++;
      
      // Check Motor Power
      CheckMotorPower();
   }
   
   // If statement to check timer var
   if(timer > 16000){
      timer = 0;  
   }
   
   // Increment timer
   timer++; 
   
}
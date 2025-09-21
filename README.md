# Task Scheduler

**Description:**

For this project I was tasked to create an embedded program that will utilize a task scheduler with timers to flash viarous 
LED at different time intervals, or run a motor at different speeds utilizing PWM depending on dip switch value. The goals for the project were to:

1. Blink LED 0 for .1 seconds on and .1 seconds off
2. Blink LED 1 for .25 seconds on and .25 seconds off
3. Blink LED 2 for 2 seconds on and 2 seconds off
4. Check SW0 state every 5 seconds
5. Control Motor with PWM every 2 miliseconds

**Features:**

The features this project utilized the supplied developmenet board, onboard registers/timers, onboard I/Os. Utilizing C, I was able to create a low level program that would utilize 
task scheduler to allow the program to complete different tasks. What makes this program unique is the utilization of the task scheduler to allow our program to complete different task 
at the same time. 

The periphals utilized were:

  * Interrupts
  * Onboard I/O's

**Programming Language:** C

**Libraries/Frameworks:** N/A

**Environment:** CodeWarrior

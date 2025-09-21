# Task Scheduler

**Description:**

For this project I was tasked to create an embedded program that will utilize a task scheduler with timers to flash various 
LED at different time intervals, or run a motor at different speeds utilizing PWM depending on dip switch value. The goals for the project were to:

1. **LED Control**
    * Blink **LED0** 0.1s on / 0.1s off
    * Blink **LED1** 0.25s on / 0.25s off
    * Blink **LED2** 2s on / 2s off
2. **Switch Input**
    * Check the state of **SW0** every 5 seconds
5. **Motor Control**
    * Control motor speed using **PWM updates** every 2 ms, with speed determined by DIP switch value

**Features:**

Developed a bare-metal task scheduler in C using hardware timers and interrupts to concurrently blink LEDs at varying intervals, poll switch inputs, and control motor speed via PWM. Demonstrated reliable real-time task execution without blocking or external frameworks.

The peripherals utilized were:

  * Interrupts
  * Hardware timers
  * Onboard I/O's
  * Motor with PWM 

**Programming Language:** C

**Libraries/Frameworks:** N/A (bare-metal implementation)

**Environment:** CodeWarrior IDE

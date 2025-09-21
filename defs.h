// Defining Bit Field
#define BIT0   0x01
#define BIT1   0x02
#define BIT2   0x04

// Defining Macros
#define FLIP_LED(n)  PORTC ^= BIT##n
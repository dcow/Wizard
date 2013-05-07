
/*
 * WIZARD Glove Input Module
 * Author: David Cowden
 * 
 */

#include <18F8722.h>
#fuses H4,NOWDT,NOPROTECT,NOLVP  //these overwrite the Configuration Bits
#use delay(clock = 40000000)
#use rs232(baud=115200,xmit=PIN_C6,rcv=PIN_C7)	

// Finger definitions
#define INP_OPEN   0x00
#define INP_INDEX  0x01
#define INP_MIDDLE 0x02
#define INP_RING   0x04
#define INP_PINKY  0x08

// Return the value from the input bus.
// Player 1 is the lower order 4 bits,
// Player 2 is the higher order 4 bits.
unsigned int8 get_input(void);

// Return the player1 and player2 inputs in separate fields
unsigned void get_input(unsigned int8 *p1, unsigned int8 *p2)

// Gesture definitions are a combination of fingers
#define GST_PALM   INP_OPEN
#define GST_OKAY   INP_INDEX
#define GST_MIND                            INP_RING | INP_PINKY
#define GST_SPIDY              INP_MIDDLE | INP_RING
#define GST_POINT              INP_MIDDLE | INP_RING | INP_PINKY
#define GST_TEA    INP_INDEX | INP_MIDDLE | INP_RING
#define GST_FIST   INP_INDEX | INP_MIDDLE | INP_RING | INP_PINKY


/*
 * WIZARD Glove Input Module
 * Author: David Cowden
 * 
 */

// This function needs to be called before anything in this module
// will work.
void setup_glove_input();

// Finger definitions
#define INP_OPEN   0x00
#define INP_INDEX  0x01
#define INP_MIDDLE 0x02
#define INP_RING   0x04
#define INP_PINKY  0x08

// Gesture definitions are a combination of fingers
#define GST_PALM   INP_OPEN
#define GST_OKAY   INP_INDEX
#define GST_MIND                            INP_RING | INP_PINKY
#define GST_SPIDY              INP_MIDDLE | INP_RING
#define GST_POINT              INP_MIDDLE | INP_RING | INP_PINKY
#define GST_TEA    INP_INDEX | INP_MIDDLE | INP_RING
#define GST_FIST   INP_INDEX | INP_MIDDLE | INP_RING | INP_PINKY

// A file register read operation is executed each time an
// 'input' function is called.

// Return the value from the input bus.
// Player 1 is the lower order 4 bits,
// Player 2 is the higher order 4 bits.
unsigned int8 get_input(void);

// Return the player1 and player2 inputs in separate fields
void get_input(unsigned int8 *p1, unsigned int8 *p2);

// Return the value of player one or player two's input guesture.
unsigned int8 get_p1_input(void);
unsigned int8 get_p2_input(void);
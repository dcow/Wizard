/*
 * WIZARD Glove Input Module
 * Author: David Cowden
 * 
 */

#include "glove-input.h"
#include <18F8722.h>

// Bits of input for each glove..
#define P_WIDTH 4

// Player masks..
#define P1_MASK 0x0F
#define P2_MASK 0xF0
#define P1_OFFSET 0
#define P2_OFFSET 1

void setup_glove_input() {
	set_inp_tris(0xFF);
}

// Return the value present on the input file
// register at the time of the call..
unsigned int8 get_input() {
	return input_port();
}

// Return separate player1 and player2 inputs
unsigned void get_input(unsigned int8 *p1, unsigned int8 *p2) {
	unsigned int8 inp = get_input();
	*p1 = (inp & P1_MASK) >> (P1_OFFSET * P_WIDTH);
	*p2 = (inp & P2_MASK) >> (P2_OFFSET * P_WIDTH);
}

// return the value of player one's input gesture
unsigned int8 get_p1_input(void) {
	unsigned int8 inp = get_input();
	return (inp & P1_MASK) >> (P1_OFFSET * P_WIDTH);
}

// return the value of player two's input gesture
unsigned int8 get_p2_input(void) {
	unsigned int8 inp = get_input();
	return (inp & P2_MASK) >> (P2_OFFSET * P_WIDTH);
}
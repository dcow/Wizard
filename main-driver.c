/*
 * WIZARD Main Driver
 * Author: David Cowden
 * 
 */

// This file handles setting up the PIC environment and then
// initializing and starting the game.
#fuses H4,NOWDT,NOPROTECT,NOLVP  //these overwrite the Configuration Bits
#use delay(clock = 40000000)
#use rs232(baud=115200,xmit=PIN_C6,rcv=PIN_C7)	
#include <18F8722.h>
#include <stdio.h>
#include <stdlib.h>

// Include the game engine definitions..
#include "wizard-engine.h"
// Include the input controller definitions..
#include "glove-input.h"

#define PULSE_TIME -1000 + 92 // time is in ms (about 92 ms of overhead)

// Function called in order to reset the game either
// for the first run or at any time during a session.

// An inturrupt on RB0 should reset the game..
#int_ext
void RB0_int() {
	clear_inturrupts(int_ext);
	title();
    // disable_interrupts(int_ext);
    // clear_inturrupt(int_ext);
    // reset_system();
	// enable_interrupts(int_ext);	
}

/*
 * Main initial loop.
 * The game should wait for a button to be pressed 
 */
unsigned int8 gesture;
void main() {

	// Setup inturrupts..
	set_tris_b(0x01);	//just RB0 is input
	ext_int_edge(0,H_TO_L);
	enable_interrupts(GLOBAL);
	enable_interrupts(INT_EXT);

	// Setup the input file register..
	setup_glove_input();

	// Setup timer for title screen..
	setup_timer_1(T1_INTERNAL);

	// Show the title screen!
	title();
}

// Setup glove intput first.
// Title 'screen'..
void title() {
	// Setup timer for dots
	clear_inturrupts(int_timer1);
	set_timer1(PULSE_TIME);
	enable_interrupts(int_timer1);

	// Wait for user input..
	while (TRUE) {
		if ((gesture = get_p1_input()) == GST_FIST) {
			disable_interrupts(int_timer1);
			launch_wizard();
		}
	}
}

// Print initial message and wait for user action..
unsigned int8 i = 0;
char[] dots = "...";
#int_timer1
void timer1_isr() {
	disable_interrupts(int_timer1);
  	clear_inturrupt(int_timer1);

	printf("Player ONE make a fist to begin%s  \r", dots + i++);
	i = i % 3;

	set_timer1(PULSE_TIME);
	enable_interrupts(int_timer1);
}






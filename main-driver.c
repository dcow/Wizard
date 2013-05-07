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

// Function called in order to reset the game either
// for the first run or at any time during a session.

// An inturrupt on RB0 should reset the game..
#int_ext
void RB0_int() {
  	disable_interrupts(int_ext);
  	clear_inturrupt(int_ext)
	enable_interrupts(int_ext);

  	// Start the game..
  	launch_wizard();	
}

/*
 * Main game driving loop.
 * We want the game to have a 2-3 second heartbeat.
 * Main will setup a timer and then our 
 */
void main() {

	// Setup inturrupts..
	set_tris_b(0x01);	//just RB0 is input
	ext_int_edge(0,H_TO_L);
	enable_interrupts(GLOBAL);
	enable_interrupts(INT_EXT);

	// Print initial message and wait for user action..
	while (TRUE) {
		printf("Press START to begin.");
		delay(1);
		printf("Press STaRT to begin..");
		delay(1);
		printf("Press StarT to begin...");
		delay(1);
	}
}
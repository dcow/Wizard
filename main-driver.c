/*
 * WIZARD Main Driver
 * Author: David Cowden
 * 
 */

#fuses H4,NOWDT,NOPROTECT,NOLVP  //these overwrite the Configuration Bits
#use delay(clock = 40000000)
#use rs232(baud=115200,xmit=PIN_C6,rcv=PIN_C7)	
#include <18F8722.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Main game driving loop.
 * We want the game to have a 2-3 second heartbeat.
 * Main will setup a timer and then our 
 */
void main() {
	
}
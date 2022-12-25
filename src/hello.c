#include <stdio.h>
#include <peekpoke.h>
#include <string.h>
#include <conio.h>
#include <atari.h>

void __fastcall__ str_to_internal(char *s);  // convert string in memory to internal character format Atasci

extern const char text[]; /* Defined In text.s file.  Benefit is to externalize text strings and optimize memory and file size */   

#pragma static-locals (1)  // Declare local variables as static and add them to the zero-page register of the target system

#define SAVMSC *(unsigned int *) 88 // memory screen address dec 88 or hex 0x58 for the Atari

typedef unsigned char BYTE;

void wait(BYTE);
void graphics2();


BYTE i = 0; 

int main (void) {

	graphics2();
	wait(50);
	cprintf("This was it");
	wait(50);
	return 0;
}

void graphics2() {
	BYTE i = 0;	
	char *screen;			// initalize a pointer labled screen
	char txt[15];			// create a var char labled txt and hold 16 bytes

	_graphics(2);   		// change to gr.2
	screen = (char *) SAVMSC;	// asign the screen address to a var	
	
	memcpy(txt, text, strlen(text)+1);		// Confusing but to convert to internal screen format we need a non-constant copy of our constant string	
	str_to_internal(txt);		// convert content of text.s to internal screen format (Atasci)	
	memcpy(&screen[20], txt, strlen(text));	// Copy the content of text to the pointer to the memory address labled screen (copy into RAM). 
	
	return;
}

/***************************************
*                    
* Converts a string from atascii code to internal character set code.
* Usually we want to do this before writing it to a bitmap 
*/
void __fastcall__ str_to_internal(char *s) {
	// unsigned int i;
	// unsigned int len;
	BYTE i;
	BYTE len;

	len = strlen(s);
	for (i = 0; i < len; i++) {
		if (s[i] < 32)
			s[i] += 64;
		else if (s[i] < 96)
			s[i] -= 32;
	}
	return;
}
/*********************************************************************
 * wait a specified amount of time in msseconds                     **
 */

void wait(BYTE t) {
	OS.rtclok[0]=OS.rtclok[1]=OS.rtclok[2]=0; 
	while (OS.rtclok[2]<t); { 
		// twiddle thumbs 
	}	
}

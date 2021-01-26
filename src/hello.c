#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <peekpoke.h>

extern const char text[]; /* Defined In text.s file.  Benefit is to externalize text strings and optimize memory and file size */   

#pragma static-locals (1)  // Declare local variables as static and add them to the zero-page register of the target system

int i = 0; 

int main (void) {

// setup visuals

bgcolor(COLOR_BLACK);	// set the background color
POKEW(710,192);		// set text color.  710 is memory address for color reg # 2.  
clrscr();		// clear the screen

	for (i = 0; i <= 254; i++) {
		printf("%s\n", text);
		sleep(1);   // x seconds
	}
	return EXIT_SUCCESS;
}

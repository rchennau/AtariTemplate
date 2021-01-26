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
POKEW(709,56);		// set text color.  708 is memory address for color reg # 0.  
clrscr();		// clear the screen

	for (i = 0; i <= 254; i++) {
		printf("%s %i\t", text, i);
		POKEW(710,i);		// set text color.  708 is memory address for color reg # 0.  
		sleep(1);   // x seconds
	}
	POKEW(710,192);		// set text color.  710 is memory address for color reg # 2.  This should be green on black  
	printf("%s 192\n", text);
	sleep(10);   // 10 seconds
	return EXIT_SUCCESS;
}

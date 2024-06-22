#include <conio.h> // Include the conio.h library for screen manipulation
#include <atari.h> // Include the atari.h library for memory manipulation
#include <peekpoke.h> // Include the peekpoke.h library for memory manipulation

// Define the custom display list for the highest resolution on Atari 800
const unsigned char displayList[] = {
  0x01, // Set the display mode to 320x192 pixels (highest resolution)
  0x00, // Set the character set to the default set
  0x00, // Set the screen color to black
  0x00, // Set the border color to black
  0x00, // Set the background color to black
  0x00, // Set the foreground color to white
  0x00, // Set the character height to 8 pixels
  0x00, // Set the character width to 8 pixels
  0x00, // Set the character spacing to 0 pixels
  0x00, // Set the line spacing to 0 pixels
  0x00, // Set the scroll speed to 0
  0x00, // Set the scroll direction to 0
  0x00, // Set the cursor position to 0,0
  0x00, // Set the cursor shape to 0
  0x00, // Set the cursor color to 0
  0x00, // Set the cursor blink rate to 0
  0x00, // Set the cursor visibility to 0
};
// Function to set the display list
void set_display_list(const unsigned char *displayList) {
  // Load the display list into memory
  int i;
  for (i = 0; i < sizeof(displayList); i++) {
    POKE(599 + i, displayList[i]);
  }
  POKE(599, 34); // Enable display list
}

int main() {
  // Set the display list
  set_display_list(displayList);

  // Print "Hello World!" to the screen
  cprintf("Hello World!");

  // Wait for a key press
  cgetc();

  return 0;
}
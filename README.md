# AtariTemplate

This is a sample hello world applicaiton written in cc65 for an Atari target
The Makefile assumes a 'linux' type operating system but has been extensively test on Mac OSX Darwin

Makefile was created by Oliver Schmidt & Patryk "Silver Dream !" Łogiewa

This version has been modified to build on systems where the directory has a sapce.  Make struggles with spaces in the build path.  The best fix I was able to discern was by adding BASENAME  := $(shell basename $(PWD)) to set the PROGRAM name when the linker compiles.  

## Visual Studio Code

I use VS Code for development. I have it setup for code completion and source of the Atari include path


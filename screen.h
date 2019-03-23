#ifndef SCREEN_H
#define SCREEN_H

//INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "ctype.h"

//DEFINES
#define SCREEN_SIZE_X 60
#define SCREEN_SIZE_Y 30

//GLOBAL VARIABLES


//VARIABLES

//FUNCTIONS

void drawDialog(char * text, uint8_t bottom);
void clearScreen();
void msDelay(uint32_t milliseconds);

#endif
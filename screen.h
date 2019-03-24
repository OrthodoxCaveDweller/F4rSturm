#ifndef SCREEN_H
#define SCREEN_H

//INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <ncurses.h>
#include "ctype.h"

//DEFINES
#define SCREEN_SIZE_X 60
#define SCREEN_SIZE_Y 30
#define CLOCKS_PER_MS 1000
#define MAX_SIZE 5000

//GLOBAL VARIABLES

//VARIABLES

//FUNCTIONS

void drawDialog(char * text, uint8_t bottom);
void drawASCIIGraphic(char * fileName);
void clearScreen();
void msDelay(uint32_t milliseconds);

#endif
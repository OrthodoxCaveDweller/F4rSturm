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
#include "lib/cJSON.h"

//DEFINES
#define SCREEN_SIZE_X 60
#define SCREEN_SIZE_Y 30
#define CLOCKS_PER_MS 1000
#define MAX_SIZE 5000
#define NORMAL_DELAY 500
#define FAST_DELAY 100
#define SLOW_DELAY 1000

//GLOBAL VARIABLES
// uint8_t max_y, max_x;
// WINDOW * mainwin;

//VARIABLES

//FUNCTIONS

void drawDialog(char * text, uint8_t bottom, uint16_t delay);
void drawASCIIGraphic(char * fileName);
char * readTextFromFile(char * fileName);
cJSON * readJSONFile(char* fileName);
void clearScreen();
void msDelay(uint32_t milliseconds);
void drawDialogScreen(char * dialogFile);

#endif
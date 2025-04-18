#ifndef MAINMENU_H
#define MAINMENU_H

//INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "screen.h"
#include "ctype.h"

//DEFINES
#define USER_NAME_LENGTH 16
#define FIRST_OPTION 0
#define LAST_OPTION 1

//GLOBAL VARIABLES
//const char * title = "F4rSturm";
char * userName;
int row, col;

//VARIABLES

//FUNCTIONS
void mainMenuInit();
void printTitle();                  //screen.h
void setUserName();
void startGame(uint8_t option);
void endGame();
void drawOptions();                 //screen.h
void moveOption(int8_t direction);  //screen.h
void selectOption();
void exitOption();
void disableTyping();
void eneableTyping(); 
void aboutScreen();

#endif
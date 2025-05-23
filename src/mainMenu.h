#ifndef MAINMENU_H
#define MAINMENU_H

//INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "screen.h"
#include "ctype.h"
#include "global.h"

//DEFINES
#define USER_NAME_LENGTH 16

//GLOBAL VARIABLES
//const char * title = "F4rSturm";

//VARIABLES

//FUNCTIONS
void mainMenuInit();
void setUserName();
void startGame(uint8_t option);
void endGame();
void selectOption();
void exitOption();
void disableTyping();
void eneableTyping(); 
void aboutScreen();

#endif
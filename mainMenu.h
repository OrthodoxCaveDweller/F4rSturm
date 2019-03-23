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

//GLOBAL VARIABLES
//const char * title = "F4rSturm";
char * userName;

//VARIABLES

//FUNCTIONS
void mainMenuInit();
void clearScreen();
void printTitle();
void setUserName();


#endif
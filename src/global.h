#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdint.h>

//GLOBALS
extern int row, col;
extern char * userName;

extern uint8_t continueGame;
extern uint8_t selectedOption;
enum options
{
    START_GAME = 0,
    ABOUT_GAME = 1,
    EXIT_GAME = 2
};

//DEFINES
#define NUMBER_OF_OPTIONS 4
#endif
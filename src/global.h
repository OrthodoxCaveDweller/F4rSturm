#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdint.h>

//ENUMS
extern enum selectedOption2d
{
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT
};

enum options
{
    START_GAME = 0,
    ABOUT_GAME = 1,
    EXIT_GAME = 2
};

//STRUCTS
extern struct moveDirection
{
    int8_t x;
    int8_t y;
} moveDirection;

//GLOBALS
extern int row, col;
extern char * userName;

extern uint8_t continueGame;
extern uint8_t selectedOption1d;
extern enum selectedOption2d selectedOption2d;

//DEFINES
#define NUMBER_OF_OPTIONS 4
#endif
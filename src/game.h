#ifndef GAME_H
#define GAME_H

//INCLUDES
#include <ncurses.h>
#include "mainMenu.h"
#include "screen.h"
#include "global.h"

//ENUMS
enum gameState
{
    GAME_ERROR = -1,
    GAME_OVER = 0,
    GAME_INIT = 1,
    GAME_LOADING_LEVEL = 2,
    GAME_WAITING_FOR_INPUT = 3,
    GAME_PROCESSING_INPUT = 4
};

//VARIABLES
extern enum gameState currentGameState;

void gameLoop();
void waitForAndSelectOption();

#endif
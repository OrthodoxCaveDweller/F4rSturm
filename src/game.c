#include "game.h"
enum gameState currentGameState = GAME_INIT;

void gameLoop()
{
	while (currentGameState != GAME_OVER && currentGameState != GAME_ERROR)
	{
		switch (currentGameState)
		{
			case GAME_INIT:
				// Initialize game state
				drawDialogScreen("./resources/Dialogs/1_intro.json");
				currentGameState = GAME_WAITING_FOR_INPUT;
				break;
			case GAME_LOADING_LEVEL:
				// Load level data
				currentGameState = GAME_WAITING_FOR_INPUT;
				break;
			case GAME_WAITING_FOR_INPUT:
				waitForAndSelectOption();
				break;
			case GAME_PROCESSING_INPUT:
				// Process input (currently transition to end or next stage)
				drawDialog("\nOption selected! Thanks for playing.\n", FALSE, NORMAL_DELAY);
				msDelay(1500);
				currentGameState = GAME_OVER;
				break;
			case GAME_OVER:
			case GAME_ERROR:
				break;
			default:
				currentGameState = GAME_OVER;
				break;
		}
	}
}

void waitForAndSelectOption()
{
	int input;
	struct moveDirection moveDir;
	while (currentGameState == GAME_WAITING_FOR_INPUT)
	{
		input = wgetch(stdscr);
		switch(input){
			case KEY_UP:
				moveDir.x = 0;
				moveDir.y = 1;
				moveOption(moveDir);
				break;
			case KEY_DOWN:
				moveDir.x = 0;
				moveDir.y = -1;
				moveOption(moveDir);
				break;
			case KEY_LEFT:
				moveDir.x = -1;
				moveDir.y = 0;
				moveOption(moveDir);
				break;
			case KEY_RIGHT:
				moveDir.x = 1;
				moveDir.y = 0;
				moveOption(moveDir);
				break;
			case 10:
			//case '\n':
			case '\r':
			case KEY_ENTER:
				currentGameState = GAME_PROCESSING_INPUT;
				break;
			case 'q':
			case 'Q':
				currentGameState = GAME_OVER;
				break;
			default: 
				break;
		}
	}
}

#include "game.h"
enum gameState currentGameState = GAME_INIT;

void gameLoop()
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
			// waitForAndSelectOption();

			if(continueGame)
			{
				currentGameState = GAME_PROCESSING_INPUT;
			}
			break;
		case GAME_PROCESSING_INPUT:
			// Process input

			currentGameState = GAME_LOADING_LEVEL;
			break;
		case GAME_OVER:
			endGame();
			break;
		default:
			break;
	}

	
}

// void waitForAndSelectOption()
// {
// 	while(!continueGame)
//     {
// 		int input;
// 		struct moveDirection moveDirection;
// 		input = wgetch(stdscr);
// 		printf("Input: %d", input);
// 		switch(input){
// 			case KEY_UP:
// 				moveDirection.x = 0;
// 				moveDirection.y = 1;
// 				moveOption(moveDirection);
// 				break;
// 			case KEY_DOWN:
// 				moveDirection.x = 0;
// 				moveDirection.y = -1;
// 				moveOption(moveDirection);
// 				break;
// 			case KEY_LEFT:
// 				moveDirection.x = -1;
// 				moveDirection.y = 0;
// 				moveOption(moveDirection);
// 				break;
// 			case KEY_RIGHT:
// 				moveDirection.x = 1;
// 				moveDirection.y = 0;
// 				moveOption(moveDirection);
// 				break;
// 			case 10:
// 				selectOption();
// 			default: 
// 				break;
// 		}
// 	}
// }

#include "game.h"

void waitForAndSelectOption()
{
	while(!continueGame)
    {
		int input;
		input = wgetch(stdscr);
		switch(input){
			case KEY_UP:
				moveOption(1);  //this moveoption function is specific to main menu, need new one
				break;
			case KEY_DOWN:
				moveOption(-1);
				break;
			case 10:
				selectOption();
			default: 
				break;
		}
	}
}

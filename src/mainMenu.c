#include "mainMenu.h"

const char * title = "F4rSturm";

//makes the main menu
void mainMenuInit(){
	initscr();
	start_color();
	noecho();
	cbreak();

	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);

	getmaxyx(stdscr, row, col);

	move(0, col > 50 ? col - 50 : 0);
	printTitle();

	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);

	drawOptions();
	while(!continueGame){
		int input = wgetch(stdscr);
		switch(input){
			case KEY_UP:
				selectedOption1d = moveOptionMainMenu(1);
				break;
			case KEY_DOWN:
				selectedOption1d = moveOptionMainMenu(-1);
				break;
			//case 10:
			case '\n':
			case '\r':
			case KEY_ENTER:
				selectOption();
				break;
			default: 
				break;
		}
	}

	move(row > 6 ? row - 6 : 0, 0);
	setUserName();

	drawDialog("Welcome to F4rSturm, ", 0, NORMAL_DELAY);
	drawDialog(userName ? userName : "Adventurer", 0, NORMAL_DELAY);
	printw("\n");
	startGame(TRUE);
	clearScreen();
}

//user can set a user name with bound checking
void setUserName(){
	if (userName != NULL) {
		free(userName);
		userName = NULL;
	}
	userName = (char *)malloc(USER_NAME_LENGTH + 1);
	if (!userName) return;

	drawDialog("Enter your username: ", FALSE, NORMAL_DELAY);
	echo();
	if (scanw("%16s", userName) != 1) {
		strcpy(userName, "Adventurer");
	}
	noecho();
	printw("\n");
}

//asks user to start the game iteratively without recursion or stdin collision
void startGame(uint8_t option){
	if(option){
		drawDialog("Do you want to start the game? (y/n): ", FALSE, NORMAL_DELAY);
	}
	while(1){
		int ch = wgetch(stdscr);
		if(ch == 'y' || ch == 'Y'){
			drawDialog("Starting game...\n", FALSE, NORMAL_DELAY);
			break;
		} else if (ch == 'n' || ch == 'N'){
			drawDialog("Exiting game...\n", FALSE, NORMAL_DELAY);
			endGame();
		} else if (ch != ERR && ch != '\n' && ch != '\r') {
			drawDialog("\nInvalid answer, try again (y/n): ", FALSE, NORMAL_DELAY);
		}
	}
}

void endGame(){
	endwin();
	if (userName != NULL) {
		free(userName);
		userName = NULL;
	}
	exit(0);
}

void selectOption(){
	switch(selectedOption1d){
		case START_GAME:
			continueGame = 1;
			break;
		case ABOUT_GAME:
			aboutScreen();
			break;
		default:
			break;
	}
}

void exitOption(){
	endGame();
}

void enableTyping(){
	echo();
}

void disableTyping(){
	noecho();
}

void aboutScreen(){
	uint8_t returnToMenu = 0;
	selectedOption1d = START_GAME;

	clear();
	move(row / 2, (col > 40) ? (col / 2) - 20 : 0);
	drawDialog("Game made in C by Balint Harmse. Enjoy!", FALSE, SLOW_DELAY);
	move((row / 2 + 1), (col > 40) ? (col / 2) - 20 : 0);
	drawDialog("Press 'q' to return to the main menu.", FALSE, SLOW_DELAY);
	while(!returnToMenu){
		int input = wgetch(stdscr);
		switch(input){
			case 'q':
			case 'Q':
				clear();
				move(0, 0);
				printTitle();
				drawOptions();
				returnToMenu = 1;
				break;
			default: 
				break;
		}
	}
}
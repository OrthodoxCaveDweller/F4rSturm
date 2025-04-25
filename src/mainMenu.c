#include "mainMenu.h"

const char * title = "F4rSturm";

//makes the main menu
void mainMenuInit(){
	initscr();
	start_color();

	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);

	getmaxyx(stdscr, row, col);

	move(0, col - 50);
	printTitle();

	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);

	//TODO: Disable typing unless required
	drawOptions();
	while(!continueGame){
		int input;
		input = wgetch(stdscr);
		switch(input){
			case KEY_UP:
				selectedOption1d = moveOptionMainMenu(1);
				break;
			case KEY_DOWN:
				selectedOption1d = moveOptionMainMenu(-1);
				break;
			case 10:
				selectOption();
			default: 
				break;
		}
	}

	move(row - 6, 0);
	setUserName();

	drawDialog("Welcome to F4rSturm, ", 1, NORMAL_DELAY);
	drawDialog(userName, 0, NORMAL_DELAY);
	printw("\n");
	//printw(readTextFromFile("./resources/Dialogs/1_intro.txt"));
	//drawDialog(readTextFromFile("./resources/Dialogs/1_intro.txt"), FALSE, NORMAL_DELAY);
	printw("\n");
	startGame(TRUE);
	clearScreen();
}

//user can set a user name (USER_NAME_LENGTH long, but isn't being checked for yet)
void setUserName(){
	userName = malloc(USER_NAME_LENGTH + 1);
	drawDialog("Enter your username:\n", TRUE, NORMAL_DELAY);
	scanw("%s", userName);
}

//asks user to start the game, uint8_t option is used to decide printing the question
//WINDOWS VERSION LOOPS ON THE RECURSION, TO BE FIXED
void startGame(uint8_t option){
	if(option){
		drawDialog("Do you want to start the game? y/n \n", FALSE, NORMAL_DELAY);
	}
	char startGameChar;
	scanf(" %c", &startGameChar);

	if(startGameChar == 'y' || startGameChar ==  'Y'){
		//start the game
		drawDialog("Starting game", TRUE, NORMAL_DELAY);
		printw("\n");
	} else if (startGameChar == 'n' || startGameChar == 'N'){
		drawDialog("Exiting game", TRUE, NORMAL_DELAY);
		endGame();
	} else {
		drawDialog("Invalid answer, try again.\n", FALSE, NORMAL_DELAY);
		startGame(0);
	}
}

void endGame(){
	endwin();
	free(userName);
	exit(0);
}

void selectOption(){
	switch(selectedOption1d){
		case START_GAME:
			continueGame = 1;
			break;
		case ABOUT_GAME:
			//todo
			aboutScreen();
			break;
	}
}

void exitOption(){

}

void enableTyping(){

}

void disableTyping(){

}

void aboutScreen(){
	uint8_t returnToMenu = 0;
	selectedOption1d = START_GAME;

	clear();
	move(row/2, (col/2) - 20);
	drawDialog("Game made in C by Balint Harmse. Enjoy!", FALSE, SLOW_DELAY);
	move((row/2 + 1), (col/2) - 20);
	drawDialog("Press 'q' to return to the main menu.", FALSE, SLOW_DELAY);
	while(!returnToMenu){
		int input;
		input = wgetch(stdscr);
		switch(input){
			case 'q':
				clear();
				move(0,0);
				printTitle();
				drawOptions();
				returnToMenu = 1;
				break;
			default: 
				break;
		}
	}
}
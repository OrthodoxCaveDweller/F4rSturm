#include "mainMenu.h"

const char * title = "F4rSturm";

//makes the main menu
void mainMenuInit(){
	int row, col;
	initscr();


	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);

	getmaxyx(stdscr, row, col);

	move(0, col - 50);
	printTitle();
	move(row - 6, 0);
	setUserName();

	drawDialog("Welcome to F4rSturm, ", 1, NORMAL_DELAY);
	drawDialog(userName, 0, NORMAL_DELAY);
	printw("\n");
	drawDialog(readTextFromFile("./resources/Dialogs/Test.txt"), FALSE, FAST_DELAY);
	printw("\n");
	startGame(TRUE);
}

//prints the games title
void printTitle(){
	char * fileName = "./resources/Title_3.txt";
	drawASCIIGraphic(fileName);
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
		printf("Starting game");
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
	exit(0);
}

void drawOptions(){

}

void optionDown(){

}

void optionUp(){

}

void selectOption(){

}

void exitOption(){

}
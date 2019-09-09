#include "mainMenu.h"

const char * title = "F4rSturm";
uint8_t continueGame = 0;
uint8_t selectedOption = 0;

//makes the main menu
void mainMenuInit(){
	//int row, col;
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
				moveOption(1);
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

	move(row - 6, 0);
	setUserName();

	drawDialog("Welcome to F4rSturm, ", 1, NORMAL_DELAY);
	drawDialog(userName, 0, NORMAL_DELAY);
	printw("\n");
	//drawDialog(readTextFromFile("./resources/Dialogs/Test.txt"), FALSE, FAST_DELAY);
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
	exit(0);
}

void drawOptions(){
	move(row - 19, 10);
	attron(COLOR_PAIR(2));
	drawDialog("About game", FALSE, NORMAL_DELAY);
	move(row - 20, 10);
	attron(COLOR_PAIR(1));
	drawDialog("Start game\n", FALSE, NORMAL_DELAY);
	attron(COLOR_PAIR(2)); 

}

void moveOption(int8_t direction){
	if(direction < 0 && selectedOption == 0){
		selectedOption = LAST_OPTION;
	} else if(direction > 0 && selectedOption == LAST_OPTION){
		selectedOption = FIRST_OPTION;
	} else {
		selectedOption = selectedOption + direction;
	}

	switch(selectedOption){
		case 0:
			move(row - 19, 10);
			attron(COLOR_PAIR(2));
			printw("About game\n");
			move(row - 20, 10);
			attron(COLOR_PAIR(1));
			printw("Start game\n");
			break;
		case 1:
			move(row - 19, 10);
			attron(COLOR_PAIR(1));
			printw("About game\n");
			move(row - 20, 10);
			attron(COLOR_PAIR(2));
			printw("Start game\n");
			break;
		default:
			break;
	}
	attron(COLOR_PAIR(2));
}

void selectOption(){
	switch(selectedOption){
		case 0:
			continueGame = 1;
			break;
		case 1:
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

	clear();
	move(row/2, (col/2) - 20);
	drawDialog("Game made in C by Balint Harmse. Enjoy!", FALSE, NORMAL_DELAY);
	move((row/2 + 1), (col/2) - 20);
	drawDialog("Press 'q' to return to the main menu.", FALSE, NORMAL_DELAY);
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
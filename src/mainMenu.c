#include "mainMenu.h"

const char * title = "F4rSturm";

//makes the main menu
void mainMenuInit(){
    int row, col;
    initscr();
    getmaxyx(stdscr, row, col);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
    printTitle();
    move(row - 6, 0);
    setUserName();
    
    drawDialog("Welcome to F4rSturm, ", 1, NORMAL_DELAY);
    drawDialog(userName, 0, NORMAL_DELAY);
    printw("\n");
    drawDialog(readTextFromFile("./resources/Dialogs/Test.txt"), FALSE, FAST_DELAY);
    startGame(1);
}

//prints the games title
void printTitle(){
    char * fileName = "./resources/Title.txt"; 
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
        drawDialog("Do you want to start the game? y/n ", FALSE, NORMAL_DELAY);
    }
    char startGameChar;
    scanf(" %c", &startGameChar);

    if(startGameChar == 'y' || startGameChar ==  'Y'){
        //start the game
        printw("\n");
    } else if (startGameChar == 'n' || startGameChar == 'N'){
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
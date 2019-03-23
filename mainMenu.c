#include "mainMenu.h"

const char * title = "F4rSturm";

//makes the main menu
void mainMenuInit(){
    clearScreen();
    printTitle();
    setUserName();
    drawDialog("Welcome to F4rSturm, ", 1);
    drawDialog(userName, 0);
    printf("%c", '\n');
    startGame();
}

//prints the games title, to be replaced with ACII art
void printTitle(){
    drawDialog((char *) title, 0);
    printf("%c", '\n');
}

//user can set a user name (USER_NAME_LENGTH long, but isn't being checked for yet)
void setUserName(){
    userName = malloc(USER_NAME_LENGTH + 1);
    drawDialog("Enter your username:\n", 0);
    scanf("%s", userName);
}

void startGame(){
    drawDialog("Do you want to start the game? y/n ", 0);
    char startGame;
    scanf(" %c", &startGame);

    if(startGame == 'y' || startGame ==  'Y'){
        //start the game
    } else if (startGame == 'n' || startGame == 'N'){
        exit(0);
    } else {
        drawDialog("Invalid answer, try again.\n", 0);
    }
}
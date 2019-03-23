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
    startGame(1);
}

//prints the games title, to be replaced with ACII art
void printTitle(){
    char * fileName = "./resources/Title.txt";
    drawASCIIGraphic(fileName);
}

//user can set a user name (USER_NAME_LENGTH long, but isn't being checked for yet)
void setUserName(){
    userName = malloc(USER_NAME_LENGTH + 1);
    drawDialog("Enter your username:\n", 0);
    scanf("%s", userName);
}

//asks user to start the game, uint8_t option is used to decide printing the question
void startGame(uint8_t option){
    if(option){
        drawDialog("Do you want to start the game? y/n ", 0);
    }
    char startGameChar;
    scanf(" %c", &startGameChar);

    if(startGameChar == 'y' || startGameChar ==  'Y'){
        //start the game
    } else if (startGameChar == 'n' || startGameChar == 'N'){
        exit(0);
    } else {
        drawDialog("Invalid answer, try again.\n", 0);
        startGame(0);
    }
}
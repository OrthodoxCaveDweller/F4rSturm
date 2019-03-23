#include "mainMenu.h"

const char * title = "F4rSturm";

//makes the main menu
void mainMenuInit(){
    clearScreen();
    printTitle();
    setUserName();
    drawDialog("Welcome to F4rSturm, ");
    drawDialog(userName);
    printf("%c", '\n');
}

//prints the games title, to be replaced with ACII art
void printTitle(){
    printf("%s\n", title);
}

//user can set a user name (USER_NAME_LENGTH long, but isn't being checked for yet)
void setUserName(){
    userName = malloc(USER_NAME_LENGTH + 1);
    printf("Enter your username:\n");
    scanf("%s", userName);
}

//clears screen, works on Linux, Mac and Windows
void clearScreen(){
    system("@cls||clear");
}
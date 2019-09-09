#include "screen.h"

//slowly draws dialog in terminal 
//TODO add speed option to drawDialog
void drawDialog(char * text, uint8_t bottom, uint16_t delay){
	int row, col;
	char *temp = (char *)malloc(5000);

	strcpy(temp, text);
	uint16_t pos = strlen(temp);
	temp[pos + 1] = '\0';

	if(strlen(temp) == 0){
		printf("ERROR: no text");
	}
	getmaxyx(stdscr, row, col);
	if(bottom){
		move(60, col/2);
	}

	uint8_t i = 0;
	while(temp[i] != '\0'){
		addch(temp[i] /*| A_BOLD*/); //BOLD disabled because of color incompatibility
		refresh();
		msDelay(delay);
		fflush(stdout);
		i++;
	}

}

//Now broken on Windows!
void drawASCIIGraphic(char * fileName){
	FILE *fp;
	char textFileStr[MAX_SIZE];

	fp = fopen(fileName, "r");
	if(fp == NULL){
		drawDialog("ERROR, could not open file", FALSE, NORMAL_DELAY);
	}
	while(fgets(textFileStr, MAX_SIZE, fp) != NULL) {
		printw("%s", textFileStr);
		refresh();
	}
	printf("\n\n");
	fclose(fp);
}

char * readTextFromFile(char * fileName){
	FILE *fp;
	char textFileStr[MAX_SIZE];
	char * returnString;

	fp = fopen(fileName, "r");
	if(fp == NULL){
		drawDialog("ERROR, could not open file", FALSE, NORMAL_DELAY);
	}
	while(fgets(textFileStr, MAX_SIZE, fp) != NULL)
		returnString = (char*) textFileStr;
	fclose(fp);
	return returnString;
}

//clears screen
void clearScreen(){
	system("clear");
}

//delay in milliseconds
#ifdef __linux__
void msDelay(uint32_t milliseconds){
    clock_t startTime;
    startTime = clock() / 1000000;
    while ((clock()/ CLOCKS_PER_MS) < (startTime + milliseconds))
    	;
}
#else
//clock() implementation is different on Windows
void msDelay(uint32_t milliseconds){
	clock_t startTime;
	startTime = clock();
	while (clock() < (startTime + milliseconds))
		;
}
#endif
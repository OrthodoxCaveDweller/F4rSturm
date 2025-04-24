#include "screen.h"

//slowly draws dialog in terminal
void drawDialog(char *text, uint8_t bottom, uint16_t delay)
{
	// TODO: uint8?
	char *temp = (char *)malloc(5000);

	strcpy(temp, text);
	uint16_t pos = strlen(temp);
	temp[pos + 1] = '\0';

	if (strlen(temp) == 0)
	{
		printf("ERROR: no text");
	}
	getmaxyx(stdscr, row, col);
	if (bottom)
	{
		move(60, col / 2);
	}

	uint8_t i = 0;
	while (temp[i] != '\0')
	{
		addch(temp[i] /*| A_BOLD*/); //BOLD disabled because of color incompatibility
		refresh();
		msDelay(delay);
		fflush(stdout);
		i++;
	}
	free(temp);
}

void drawASCIIGraphic(char *fileName) //TODO add argument to draw or return?? Then no need for two seperate function, drawASCIIGraphic() & readTextFromFile()
{
	FILE *fp;
	char textFileStr[MAX_SIZE];

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		drawDialog("ERROR, could not open file", FALSE, NORMAL_DELAY);
		exit(-1);
	}
	while (fgets(textFileStr, MAX_SIZE, fp) != NULL)
	{
		printw("%s", textFileStr);
		refresh();
	}
	printf("\n\n");
	fclose(fp);
}

char *readTextFromFile(char *fileName)
{
	FILE *fp;
	char textFileStr[MAX_SIZE];
	char *returnString;

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		drawDialog("ERROR, could not open file", FALSE, NORMAL_DELAY);
	}
	while (fgets(textFileStr, MAX_SIZE, fp) != NULL)
		returnString = (char *)textFileStr;
	fclose(fp);
	return returnString;
}

//clears screen
void clearScreen()
{
	system("clear");
}

void drawDialogScreen(char * dialogFile)
{
	char * dialogText = getDialogText(dialogFile);
	char ** options = getOptions(dialogFile);
    {
		getmaxyx(stdscr, row, col);
		move((row * 0.80)-2, col * 0.1);
        drawDialog(dialogText, FALSE, NORMAL_DELAY);
		drawDialog("\n", FALSE, NORMAL_DELAY);
    }

	for(uint8_t i=0; i<NUMBER_OF_OPTIONS;i++)
	{
		{
			getmaxyx(stdscr, row, col);
			switch(i)
			{
				case 0:
					move(row * 0.80, col * 0.1);
					break;
				case 1:
					move(row * 0.80, col * 0.6);
					break;
				case 2:
					move(row * 0.90, col * 0.1);
					break;
				case 3:
					move(row * 0.90, col * 0.6);
					break;
			}
			drawDialog(options[i], FALSE, FAST_DELAY);
			drawDialog("\n", FALSE, NORMAL_DELAY);
		}
	}
	for(uint16_t i=0; i<col;i++)
	{
		move((row * 0.80)-1, i);
		drawDialog("-", FALSE, FAST_DELAY);
	}
	for(uint16_t i=0; i < row * 0.20; i++)
	{
		move((row * 0.80)+i, col*0.5);
		drawDialog("|", FALSE, FAST_DELAY);
	}
	for(uint16_t i=0; i<col;i++)
	{
		move((row * 0.90)-1, i);
		drawDialog("-", FALSE, FAST_DELAY);
	}
	getmaxyx(stdscr, row, col);
	move(row*0.1,col*0.5);

	drawASCIIGraphic(getASCIIImage(dialogFile));
}

uint8_t moveOptionMainMenu(int8_t direction){
	if(direction < 0 && selectedOption1d == 0){
		selectedOption1d = LAST_OPTION;
	} else if(direction > 0 && selectedOption1d == LAST_OPTION){
		selectedOption1d = FIRST_OPTION;
	} else {
		selectedOption1d = selectedOption1d + direction;
	}

	getmaxyx(stdscr, row, col);
	switch(selectedOption1d){
		case 0:
			move(row - 19, 10);
			attron(COLOR_PAIR(2));
			printw("About game\n");
			move(row - 20, 10);
			attron(COLOR_PAIR(1));
			printw("Start game\n");
			return selectedOption1d;
		case 1:
			move(row - 19, 10);
			attron(COLOR_PAIR(1));
			printw("About game\n");
			move(row - 20, 10);
			attron(COLOR_PAIR(2));
			printw("Start game\n");
			return selectedOption1d;
		default:
			break;
	}
	attron(COLOR_PAIR(2));
}

uint8_t moveOption(struct moveDirection moveDirection)
{
	getmaxyx(stdscr, row, col);
	if (moveDirection.x){
		switch (selectedOption2d){
			case TOP_LEFT:
				selectedOption2d = TOP_RIGHT;
				break;
			case TOP_RIGHT:
				selectedOption2d = TOP_LEFT;
				break;
			case BOTTOM_LEFT:
				selectedOption2d = BOTTOM_RIGHT;
				break;
			case BOTTOM_RIGHT:
				selectedOption2d = BOTTOM_LEFT ;
				break;
		}
	}

	if (moveDirection.y){
		switch (selectedOption2d){
			case TOP_LEFT:
				selectedOption2d = BOTTOM_LEFT;
				break;
			case TOP_RIGHT:
				selectedOption2d = BOTTOM_RIGHT;
				break;
			case BOTTOM_LEFT:
				selectedOption2d = TOP_LEFT;
				break;
			case BOTTOM_RIGHT:
				selectedOption2d = TOP_RIGHT ;
				break;
		}
	}
}

//delay in milliseconds
#ifdef __linux__
void msDelay(uint32_t milliseconds)
{

	//Stopped working?
	// clock_t startTime;
	// startTime = clock() / 1000000;
	// while ((clock()/ CLOCKS_PER_MS) < (startTime + milliseconds))
	// 	;
	for (uint64_t i = 0; i < milliseconds * 10000; i++)
		;
}
#else
//clock() implementation is different on Windows
void msDelay(uint32_t milliseconds)
{
	// clock_t startTime;
	// startTime = clock();
	// while (clock() < (startTime + milliseconds))
	// 	;
	for (uint64_t i = 0; i < milliseconds * 10000; i++)
		;
}
#endif
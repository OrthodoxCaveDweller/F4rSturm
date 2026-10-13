#include "screen.h"

#if defined(_WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#endif

//slowly draws dialog in terminal
void drawDialog(const char *text, uint8_t bottom, uint16_t delay)
{
	if (text == NULL)
	{
		return;
	}

	getmaxyx(stdscr, row, col);
	if (bottom)
	{
		move(row > 2 ? row - 2 : 0, col / 2);
	}

	size_t i = 0;
	while (text[i] != '\0')
	{
		addch(text[i]);
		if (delay > 0)
		{
			refresh();
			msDelay(delay);
		}
		i++;
	}
	refresh();
}

void drawASCIIGraphic(char *fileName)
{
	if (!fileName) return;

	FILE *fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		drawDialog("ERROR, could not open file", FALSE, NORMAL_DELAY);
		return;
	}

	char textFileStr[MAX_SIZE];
	while (fgets(textFileStr, MAX_SIZE, fp) != NULL)
	{
		printw("%s", textFileStr);
		refresh();
	}
	printw("\n\n");
	refresh();
	fclose(fp);
}

char *readTextFromFile(char *fileName)
{
	if (!fileName) return NULL;

	FILE *fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		drawDialog("ERROR, could not open file", FALSE, NORMAL_DELAY);
		return NULL;
	}

	if (fseek(fp, 0, SEEK_END) != 0)
	{
		fclose(fp);
		return NULL;
	}
	long size = ftell(fp);
	rewind(fp);

	if (size < 0)
	{
		fclose(fp);
		return NULL;
	}

	char *returnString = (char *)malloc((size_t)size + 1);
	if (!returnString)
	{
		fclose(fp);
		return NULL;
	}

	size_t readBytes = fread(returnString, 1, (size_t)size, fp);
	returnString[readBytes] = '\0';
	fclose(fp);
	return returnString;
}

//clears screen
void clearScreen()
{
	clear();
	refresh();
}

void drawDialogScreen(char * dialogFile)
{
	char * dialogText = getDialogText(dialogFile);
	char ** options = getOptions(dialogFile);
	char * imageFile = getASCIIImage(dialogFile);

	getmaxyx(stdscr, row, col);

	if (dialogText)
	{
		move((row * 0.80) - 2, col * 0.1);
		drawDialog(dialogText, FALSE, NORMAL_DELAY);
		printw("\n");
	}

	if (options)
	{
		for(uint8_t i = 0; i < NUMBER_OF_OPTIONS; i++)
		{
			if (!options[i]) continue;
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
			printw("\n");
		}
	}

	// Draw borders efficiently using ncurses primitives
	for(uint16_t i = 0; i < col; i++)
	{
		mvaddch((int)(row * 0.80) - 1, i, '-');
	}
	for(uint16_t i = 0; i < (int)(row * 0.20); i++)
	{
		mvaddch((int)(row * 0.80) + i, (int)(col * 0.5), '|');
	}
	for(uint16_t i = 0; i < col; i++)
	{
		mvaddch((int)(row * 0.90) - 1, i, '-');
	}
	refresh();

	if (imageFile)
	{
		move(row * 0.1, col * 0.5);
		drawASCIIGraphic(imageFile);
	}

	// Free all dynamically allocated memory
	if (dialogText) free(dialogText);
	if (options) freeOptions(options);
	if (imageFile) free(imageFile);
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
	refresh();
	return selectedOption1d;
}

uint8_t moveOption(struct moveDirection moveDir)
{
	getmaxyx(stdscr, row, col);
	if (moveDir.x){
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
				selectedOption2d = BOTTOM_LEFT;
				break;
		}
	}

	if (moveDir.y){
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
				selectedOption2d = TOP_RIGHT;
				break;
		}
	}
	return (uint8_t)selectedOption2d;
}

//screen.h
void drawOptions(){
	move(row - 19, 10);
	attron(COLOR_PAIR(2));
	drawDialog("About game", FALSE, INSTANT_DELAY);
	move(row - 20, 10);
	attron(COLOR_PAIR(1));
	drawDialog("Start game\n", FALSE, INSTANT_DELAY);
	attron(COLOR_PAIR(2)); 
}

void printTitle(){
	char * fileName = "./resources/Title_3.txt";
	drawASCIIGraphic(fileName);
}

//delay in milliseconds
#if defined(_WIN32) && !defined(__CYGWIN__)
void msDelay(uint32_t milliseconds)
{
	Sleep(milliseconds);
}
#else
void msDelay(uint32_t milliseconds)
{
	usleep((useconds_t)milliseconds * 1000);
}
#endif
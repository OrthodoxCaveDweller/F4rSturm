#include "screen.h"

//slowly draws dialog in terminal
void drawDialog(char *text, uint8_t bottom, uint16_t delay)
{
	int row, col;
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
}

//Now broken on Windows!
void drawASCIIGraphic(char *fileName) //TODO add argument to draw or return?? Then no need for two seperate function, drawASCIIGraphic() & readTextFromFile()
{
	FILE *fp;
	char textFileStr[MAX_SIZE];

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		drawDialog("ERROR, could not open file", FALSE, NORMAL_DELAY);
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

cJSON * readJSONFile(char* fileName){
	char *ConfigurationConfigContent;
	cJSON *ConfigurationJsonData;


	//Check if file exist
	if (access(fileName, 1) == -1)
	{
		fprintf(stderr, "CONFIG: Unable to open file, name faulty!\n");
		return 1;
	}

	//Open file in Read Binary mode
	FILE *FileContent = fopen(fileName, "rb");
	int _StringSize, _ReadSize;

	if (!FileContent)
	{
		fprintf(stderr, "CONFIG: Unable to open file content!\n");
		exit;
	}

	//Get file size and put content in correct order
	fseek(FileContent, 0, SEEK_END);
	_StringSize = ftell(FileContent);
	rewind(FileContent);

	//Copy file content to memmory
	ConfigurationConfigContent = (char *)malloc(sizeof(char) * (_StringSize + 1));
	_ReadSize = fread(ConfigurationConfigContent, sizeof(char), _StringSize, FileContent);
	ConfigurationConfigContent[_StringSize] = '\0';
	fclose(FileContent);
	if (_StringSize != _ReadSize)
	{
		fprintf(stderr, "CONFIG: Not able to read complete JSON file!\n");
		free(ConfigurationConfigContent);
		ConfigurationConfigContent = NULL;
		exit;
	}

	//Parse filecontent to cJSON datatype
	ConfigurationJsonData = cJSON_Parse(ConfigurationConfigContent);
	return ConfigurationJsonData;
}

void drawDialogScreen(char * dialogFile)
{
	// FILE *fp;
	char *textFileStr = malloc(MAX_SIZE);
	cJSON *json = cJSON_CreateObject();

	json = readJSONFile(dialogFile);

	char *string = cJSON_Print(json);

	// if (string == NULL)
    // {
    //     fprintf(stderr, "Failed to print monitor.\n");
    // }

	drawDialog(string, FALSE, NORMAL_DELAY);

	//drawASCIIGraphic("./resources/Images/test");
	// free(string);
	// cJSON_Delete(json);
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
//TODO: Move json file actions from screen to this file
#include "resources.h"


char * getDialogText(char * dialogFile)
{
    const cJSON *DialogText = NULL;

	cJSON *json = readJSONFile(dialogFile);
	DialogText = cJSON_GetObjectItem(json, "DialogText");
    if (cJSON_IsString(DialogText) && (DialogText->valuestring != NULL))
    {
        char * returnText = malloc (sizeof(char) * strlen(DialogText->valuestring));
        strcpy(returnText, DialogText->valuestring);
        cJSON_Delete(json);
        return returnText;
    } else {
        //fprintf(stderr, "CONFIG: Unable to get dialog text!\n");
        
        char * errorstring = malloc (sizeof(char) * 6);
        strcpy(errorstring, "Error");

        cJSON_Delete(json);
        return errorstring;
    }
    
}

char ** getOptions(char * dialogFile)
{
    char ** returnstring = malloc (sizeof(char*) * NUMBER_OF_OPTIONS);
    cJSON *json = readJSONFile(dialogFile);

    for(uint8_t i=0; i<NUMBER_OF_OPTIONS;i++)
	{
		cJSON *optionsArray = cJSON_GetObjectItem(json, "options");
		cJSON *option = cJSON_GetArrayItem(optionsArray, i);
		cJSON *optiontext = cJSON_GetObjectItem(option, "Text");
		
		if (cJSON_IsString(optiontext) && (optiontext->valuestring != NULL))
		{
            returnstring[i] = malloc (sizeof(char) * strlen(optiontext->valuestring));
            strcpy(returnstring[i], optiontext->valuestring);
        } else {
            //fprintf(stderr, "CONFIG: Unable to get option!\n");

            char * errorstring = malloc (sizeof(char) * 6);
            strcpy(errorstring, "Error");
        }

	    // printf(returnstring[i]);
	}

    cJSON_Delete(json);
    return returnstring;
}

char * getASCIIImage(char * dialogFile)
{
    const cJSON *DialogImage = NULL;
    cJSON *json = readJSONFile(dialogFile);
    DialogImage = cJSON_GetObjectItem(json, "Image");
    char * returnText = malloc (sizeof(char) * 1);

    if (cJSON_IsString(DialogImage) && (DialogImage->valuestring != NULL))
    {
        returnText = malloc (sizeof(char) * strlen(DialogImage->valuestring));  
        strcpy(returnText, DialogImage->valuestring);
        cJSON_Delete(json);
        return returnText;
    } else
    {
        fprintf(stderr, "CONFIG: Unable to get ASCII image!\n");
        cJSON_Delete(json);

        char * errorstring = malloc (sizeof(char) * 6);
        strcpy(errorstring, "Error");
        return errorstring;
    }
    
}

cJSON * readJSONFile(char* fileName){
	char *ConfigurationConfigContent;
	cJSON *ConfigurationJsonData;


	//Check if file exist
	if (access(fileName, 1) == -1)
	{
		fprintf(stderr, "CONFIG: Unable to open file, name faulty!\n");
		exit;
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
	free(ConfigurationConfigContent);
	return ConfigurationJsonData;
}

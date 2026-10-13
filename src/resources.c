//TODO: Move json file actions from screen to this file
#include "resources.h"

static char *duplicateString(const char *src)
{
    if (!src) return NULL;
    size_t len = strlen(src);
    char *dest = (char *)malloc(len + 1);
    if (dest)
    {
        memcpy(dest, src, len + 1);
    }
    return dest;
}

char * getDialogText(char * dialogFile)
{
    cJSON *json = readJSONFile(dialogFile);
    if (!json)
    {
        return duplicateString("Error");
    }

    const cJSON *DialogText = cJSON_GetObjectItem(json, "DialogText");
    char * returnText = NULL;

    if (cJSON_IsString(DialogText) && (DialogText->valuestring != NULL))
    {
        returnText = duplicateString(DialogText->valuestring);
    } else {
        returnText = duplicateString("Error");
    }
    cJSON_Delete(json);
    return returnText;
}

char ** getOptions(char * dialogFile)
{
    char ** returnstring = (char **)malloc(sizeof(char *) * NUMBER_OF_OPTIONS);
    if (!returnstring) return NULL;

    cJSON *json = readJSONFile(dialogFile);
    cJSON *optionsArray = json ? cJSON_GetObjectItem(json, "options") : NULL;

    for (uint8_t i = 0; i < NUMBER_OF_OPTIONS; i++)
    {
        cJSON *option = (optionsArray && cJSON_IsArray(optionsArray)) ? cJSON_GetArrayItem(optionsArray, i) : NULL;
        cJSON *optiontext = option ? cJSON_GetObjectItem(option, "Text") : NULL;

        if (cJSON_IsString(optiontext) && (optiontext->valuestring != NULL))
        {
            returnstring[i] = duplicateString(optiontext->valuestring);
        } else {
            returnstring[i] = duplicateString("Error");
        }
    }

    if (json)
    {
        cJSON_Delete(json);
    }
    return returnstring;
}

void freeOptions(char ** options)
{
    if (!options) return;
    for (uint8_t i = 0; i < NUMBER_OF_OPTIONS; i++)
    {
        if (options[i])
        {
            free(options[i]);
        }
    }
    free(options);
}

char * getASCIIImage(char * dialogFile)
{
    cJSON *json = readJSONFile(dialogFile);
    if (!json)
    {
        fprintf(stderr, "CONFIG: Unable to read JSON for ASCII image!\n");
        return duplicateString("Error");
    }

    const cJSON *DialogImage = cJSON_GetObjectItem(json, "Image");
    char * returnText = NULL;

    if (cJSON_IsString(DialogImage) && (DialogImage->valuestring != NULL))
    {
        returnText = duplicateString(DialogImage->valuestring);
    } else {
        fprintf(stderr, "CONFIG: Unable to get ASCII image!\n");
        returnText = duplicateString("Error");
    }
    cJSON_Delete(json);
    return returnText;
}

cJSON * readJSONFile(char* fileName){
	if (!fileName) return NULL;

	//Check if file exists and is readable
	if (access(fileName, R_OK) == -1)
	{
		fprintf(stderr, "CONFIG: Unable to access file '%s' for reading!\n", fileName);
		return NULL;
	}

	//Open file in Read Binary mode
	FILE *FileContent = fopen(fileName, "rb");
	if (!FileContent)
	{
		fprintf(stderr, "CONFIG: Unable to open file content for '%s'!\n", fileName);
		return NULL;
	}

	//Get file size
	if (fseek(FileContent, 0, SEEK_END) != 0)
	{
		fclose(FileContent);
		return NULL;
	}
	long _StringSize = ftell(FileContent);
	rewind(FileContent);

	if (_StringSize < 0)
	{
		fclose(FileContent);
		return NULL;
	}

	//Copy file content to memory
	char *ConfigurationConfigContent = (char *)malloc((size_t)_StringSize + 1);
	if (!ConfigurationConfigContent)
	{
		fclose(FileContent);
		return NULL;
	}

	size_t _ReadSize = fread(ConfigurationConfigContent, sizeof(char), (size_t)_StringSize, FileContent);
	ConfigurationConfigContent[_ReadSize] = '\0';
	fclose(FileContent);

	if ((long)_ReadSize != _StringSize)
	{
		fprintf(stderr, "CONFIG: Not able to read complete JSON file!\n");
		free(ConfigurationConfigContent);
		return NULL;
	}

	//Parse file content to cJSON datatype
	cJSON *ConfigurationJsonData = cJSON_Parse(ConfigurationConfigContent);
	free(ConfigurationConfigContent);
	return ConfigurationJsonData;
}

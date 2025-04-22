//TODO: Move json file actions from screen to this file
#ifndef RESOURCES_H
#define RESOURCES_H 

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "global.h"
#include "ctype.h"
#include "lib/cJSON.h"
#include <unistd.h>

char * getDialogText(char * dialogFile);
char ** getOptions(char * dialogFile);
char * getASCIIImage(char * fileName);
cJSON * readJSONFile(char* fileName);

#endif
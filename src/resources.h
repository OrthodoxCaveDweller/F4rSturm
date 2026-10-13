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

#ifndef R_OK
#define R_OK 4
#endif

char * getDialogText(char * dialogFile);
char ** getOptions(char * dialogFile);
void freeOptions(char ** options);
char * getASCIIImage(char * fileName);
cJSON * readJSONFile(char* fileName);

#endif
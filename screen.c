#include "screen.h"

//slowly draws dialog in terminal 
void drawDialog(char * text, uint8_t bottom){
    if(strlen(text) == 0){
        printf("ERROR: no text");
    }

    if(bottom){
        for(int i = 0; i < SCREEN_SIZE_Y - 7; i++){
            printf("%c", '\n');
        }
    }

    uint8_t i = 0;
    while(text[i] != '\0'){
        if(i == SCREEN_SIZE_X){
            printf("%c", '\n');
        }
        printf("%c", text[i]);
        msDelay(50);
        fflush(stdout);
        i++;
    }

}

void drawASCIIGraphic(char * fileName){
    FILE *fp;
    char textFileStr[MAX_SIZE];
    fp = fopen(fileName, "r");
    if(fp == NULL){
        drawDialog("ERROR, could not open file", 0);
    }
    while(fgets(textFileStr, MAX_SIZE, fp) != NULL)
    printf("%s", textFileStr);
    printf("\n\n");
    fclose(fp);
}

//clears screen
void clearScreen(){
    system("clear");
}

//delay in milliseconds
#ifdef __linux__
void msDelay(uint32_t milliseconds){
    clock_t startTime;
    startTime = clock() / CLOCKS_PER_MS;
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
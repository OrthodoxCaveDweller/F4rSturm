#include "screen.h"

//slowly draws dialog in terminal 
//DOES NOT WORK IN WINDOWS YET, TO BE FIXED
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

//delay in milliseconds
//culprit for failure on Windows??
#ifndef OS_WINDOWS
void msDelay(uint32_t milliseconds){
    printf("test");
    clock_t startTime;
    startTime = clock() / 1000;
    while ((clock()/ 1000) < (startTime + milliseconds))
    ;
}
#elif defined(OS_WINDOWS)
void msDelay(uint32_t milliseconds){
    printf("TEST");
}
#endif
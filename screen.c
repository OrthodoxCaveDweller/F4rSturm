#include "screen.h"

//slowly draws dialog in terminal
void drawDialog(char * text){
    if(strlen(text) == 0){
        printf("ERROR: no text");
    }
    uint8_t i = 0;
    while(text[i] != '\0'){
        printf("%c", text[i]);
        msDelay(50);
        fflush(stdout);
        i++;
    }
}

//delay im  milliseconds
void msDelay(uint32_t milliseconds){
    clock_t startTime;
    startTime = clock() / 1000;
    while ((clock()/ 1000) < (startTime + milliseconds))
    ;
}

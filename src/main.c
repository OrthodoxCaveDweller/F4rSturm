/**
 * @Author: Bálint Harmse
 * @Date:   2019-03-21T17:36:52+02:00
 * @Email:  balintharmse24@gmail.com
 * @Project: F4rSturm
 * @Last modified by:   Bálint Harmse
 * @Last modified time: 2019-03-21T17:36:52+02:00
 * @Copyright: GNU GENERAL PUBLIC LICENSE Version 3
 */

#include "main.h"

int main(){
#if defined(_WIN32) || defined(WIN32)
	#undef __unix__
        #define OS_WINDOWS
        #if DEBUG
            printf("Windows OS detected\n");
        #endif
#elif defined  __unix__
	#if DEBUG
            printf("Unix OS detected\n");
        #endif
#else
	printf("OS not detected or supported!\n");
	return -1;
#endif
	mainMenuInit();
#if DEBUG
	drawDialog("Entering loop", FALSE, NORMAL_DELAY);
#endif
	while(1){

		//endGame();
	}
	endwin();
	return 0;
}
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
    #ifdef __unix__
        #if DEBUG
            drawDialog("Unix OS detected", 0);
        #endif
    #elif defined(_WIN32) || defined(WIN32)
        #define OS_Windows
        #if DEBUG
            drawDialog("Windows OS detected", 0);
        #endif
    #endif
    mainMenuInit();
}
#include "global.h"
#include <stddef.h>

char * userName = NULL;
int row = 0;
int col = 0;
uint8_t continueGame = 0;
uint8_t selectedOption1d = 0;
enum selectedOption2d selectedOption2d = TOP_LEFT;
struct moveDirection moveDirection = {0, 0};

printf "Starting compilation\n"
gcc main.c \
    screen.c screen.h \
	mainMenu.c mainMenu.h \
    -lncurses \
    -o F4rSturm

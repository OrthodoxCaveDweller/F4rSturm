# F4rSturm

Text-based terminal adventure game written in C.

——————————————————————————————————————————————————

 Linux
 
——————————————————————————————————————————————————

ncurses is required, install with "[apt-get] install libncurses5-dev libncursesw5-dev".

Compilation:
1. Open a terminal
2. Navigate to this repository (cd ~/F4rSturm)
3. Make sure you have gcc installed (gcc --version)
4. gcc main.c mainMenu.c mainMenu.h screen.c screen.h -lncurses -o F4rSturm (./compile.sh can also be used)
5. Run the game with "./F4rSturm"

—————————————————————————————————————————————————— 

 Windows
 
—————————————————————————————————————————————————— 

Tested with Cygwin, other Linux terminal emulators with gcc compilers for Windows may work, but not guarenteed. 
Usage with Windows Subsystem for Linux is also an option.

ncurses is required, install via Cygwin package manager. More info at https://youtu.be/bZw-18gy_YE.

Compilation:
Download Cygwin (more info on Cygwin  install at https://youtu.be/bZw-18gy_YE).
Make sure you have gcc installed (gcc --version).
1. Open Cygwin terminal
2. Navigate to this repository (cd ~/F4rSturm)
3. gcc main.c mainMenu.c mainMenu.h screen.c screen.h -D _WIN32 -lncurses -o F4rSturm (-D _WIN32 should be omitted when using Windows Subsystem for Linux)
4. Run the game with "./F4rSturm.exe"



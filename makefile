#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= bin/main.o bin/mainMenu.o bin/screen.o
SOURCE	= main.c mainMenu.c screen.c
HEADER	= main.h mainMenu.h screen.h
OUT	= F4rSturm
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: $(OBJS)
	$(CC) -g $(OBJS) -lncurses -o $(OUT) $(LFLAGS)


# create/compile the individual files >>separately<<
bin/main.o: main.c
	$(CC) $(FLAGS) main.c -o bin/main.o

bin/mainMenu.o: mainMenu.c
	$(CC) $(FLAGS) mainMenu.c -o bin/mainMenu.o

bin/screen.o: screen.c
	$(CC) $(FLAGS) screen.c -o bin/screen.o


# clean house
clean:
	rm -f $(OBJS) $(OUT)
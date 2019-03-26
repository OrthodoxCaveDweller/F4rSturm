#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= main.o mainMenu.o screen.o
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
main.o: main.c
	$(CC) $(FLAGS) main.c 

mainMenu.o: mainMenu.c
	$(CC) $(FLAGS) mainMenu.c 

screen.o: screen.c
	$(CC) $(FLAGS) screen.c 


# clean house
clean:
	rm -f $(OBJS) $(OUT)
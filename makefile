#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= bin/main.o bin/mainMenu.o bin/screen.o bin/cJSON.o
SOURCE	= src/main.c src/mainMenu.c src/screen.c src/lib/cJSON.c
HEADER	= src/main.h src/mainMenu.h src/screen.h src/lib/cJSON.h
OUT	= F4rSturm
CC	 = gcc
FLAGS	 = -g -c -Wall 
LFLAGS	 = -lncurses
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


# create/compile the individual files >>separately<<
bin/main.o: src/main.c
	$(CC) $(FLAGS) src/main.c -o bin/main.o 

bin/mainMenu.o: src/mainMenu.c
	$(CC) $(FLAGS) src/mainMenu.c -o bin/mainMenu.o

bin/screen.o: src/screen.c
	$(CC) $(FLAGS) src/screen.c -o bin/screen.o

bin/cJSON.o: src/lib/cJSON.c
	$(CC) $(FLAGS) src/lib/cJSON.c -o bin/cJSON.o

# clean house
clean:
	rm -f $(OBJS) $(OUT)
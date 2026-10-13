#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= bin/main.o bin/mainMenu.o bin/screen.o bin/cJSON.o bin/global.o bin/resources.o bin/game.o
SOURCE	= src/main.c src/mainMenu.c src/screen.c src/lib/cJSON.c src/global.c src/resources.c src/game.c
HEADER	= src/main.h src/mainMenu.h src/screen.h src/lib/cJSON.h src/global.h src/resources.h src/game.h
OUT	= F4rSturm
CC	 = gcc
FLAGS	 = -g -c -Wall 
LFLAGS	 = -lncurses
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: bin $(OUT)

bin:
	mkdir -p bin

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

bin/cJSON.o: src/lib/cJSON.c src/lib/cJSON.h | bin
	$(CC) $(FLAGS) src/lib/cJSON.c -o bin/cJSON.o

bin/%.o: src/%.c $(HEADER) | bin
	$(CC) $(FLAGS) $< -o $@

# clean house
clean:
	rm -f $(OBJS) $(OUT) $(OUT).exe
OBJ=game.o grid.o main.o GUI.o snake.o highscores.o
HEADERS=game.h grid.h GUI.h main.h snake.h highscores.h
CC=gcc
TARGET=main

# MAKEFILE #

all: $(OBJ)
	@echo “Linking all object files”
	$(CC) $(OBJ) -lSDL -lSDL_ttf -o $(TARGET)

game.o: game.c $(HEADERS)
	@echo “Compiling game.c”
	$(CC) game.c -c -o game.o

grid.o: grid.c $(HEADERS)
	@echo “Compiling grid.c”
	$(CC) grid.c -c -o grid.o

main.o: main.c $(HEADERS)
	@echo “Compiling main.c”
	$(CC) main.c -c -o main.o

GUI.o: GUI.c $(HEADERS)
	@echo “Compiling GUI.c”
	$(CC) GUI.c -c -o GUI.o

snake.o: snake.c $(HEADERS)
	@echo “Compiling snake.c”
	$(CC) snake.c -c -o snake.o

highscores.o: highscores.c $(HEADERS)
	@echo “Compiling highscores.c”
	$(CC) highscores.c -c -o highscores.o

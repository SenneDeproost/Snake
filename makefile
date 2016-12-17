OBJ=game.o grid.o main.o printer.o GUI.o
HEADERS=game.h grid.h printer.h GUI.h main.h
CC=gcc
TARGET=minesweeper

# MAKEFILE #s

all: $(OBJ)
	@echo “Linking all object files”
	$(CC) $(OBJ) -lSDL -o $(TARGET)

game.o: game.c $(HEADERS)
	@echo “Compiling game.c”
	$(CC) game.c -c -o game.o

grid.o: grid.c $(HEADERS)
	@echo “Compiling grid.c”
	$(CC) grid.c -c -o grid.o

main.o: main.c $(HEADERS)
	@echo “Compiling main.c”
	$(CC) main.c -c -o main.o

printer.o: printer.c $(HEADERS)
	@echo “Compiling printer.c”
	$(CC) printer.c -c -o printer.o

GUI.o: GUI.c $(HEADERS)
	@echo “Compiling GUI.c”
	$(CC) GUI.c -c -o GUI.o

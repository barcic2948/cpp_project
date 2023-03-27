CC = g++
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: main clean

main: main.o game.o game_entity.o player.o
	$(CC) main.o game.o -o main $(SFML)

main.o : main.cpp
	$(CC) -c main.cpp

game.o : src/game.cpp
	$(CC) -c src/game.cpp

game_entity.o : src/game_entity.cpp
	$(CC) -c src/game_entity.cpp

player.o : src/player.cpp
	$(CC) -c src/player.cpp


clean:
	rm -rf *.o
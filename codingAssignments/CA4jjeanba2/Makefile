# Makefile for Coding Assignment 3

all: main

main: main.o Game.o Player.o PlayingCard.o
	g++ -Wall main.o Game.o Player.o PlayingCard.o -o main

main.o: main.cpp
	g++ -Wall -c main.cpp

Node.o: Node.cpp
	g++ -Wall -c Node.h

LLC.o: LLC.cpp
	g++ -Wall -c LLC.cpp

PlayingCard.o: PlayingCard.cpp
	g++ -Wall -c PlayingCard.cpp

Player.o: Player.cpp
	g++ -Wall -c Player.cpp

Game.o: Game.cpp
	g++ -Wall -c Game.cpp

clean:
	rm -f *.o main

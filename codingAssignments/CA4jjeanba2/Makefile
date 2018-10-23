# Makefile for Coding Assignment 3

all: main

main: Node.o LLC.o PlayingCard.o main.o
	g++ main.o Node.o LLC.o PlayingCard.o -o main

main.o: main.cpp
	g++ -c main.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

LLC.o: LLC.cpp
	g++ -c LLC.cpp

PlayingCard.o: PlayingCard.cpp
	g++ -c PlayingCard.cpp

clean:
	rm -f *.o main

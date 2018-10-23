# Makefile for Coding Assignment 3

all: main

pc_main: Node.o LLC.o PlayingCard.o pc_main.o
	g++ pc_main.o Node.o LLC.o PlayingCard.o

node_main: Node.o LLC.o PlayingCard.o node_main.o
	g++ node_main.o Node.o LLC.o PlayingCard.o -o node_main

node_main.o: node_main.cpp
	g++ -c node_main.cpp

pc_main.o: pc_main.cpp
	g++ -c pc_main.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

LLC.o: LLC.cpp
	g++ -c LLC.cpp

PlayingCard.o: PlayingCard.cpp
	g++ -c PlayingCard.cpp

clean:
	rm -f *.o main

# Makefile for Coding Assignment 3

all: main

main: Node.o LLC.o main.o
	g++ main.o Node.o LLC.o -o main

main.o: main.cpp
	g++ -c main.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

LLC.o: LLC.cpp
	g++ -c LLC.cpp

clean:
	rm -f *.o main

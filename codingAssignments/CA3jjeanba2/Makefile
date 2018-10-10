# Makefile for Coding Assignment 3

all: main

main: main.o Node.o LLC.o
	g++ main.o Node.o LLC.o -o main

main.o: main.cpp
	g++ main.cpp

Node.o: Node.cpp
	g++ Node.cpp

LLC.o: LLC.cpp
	g++ LLC.cpp

clean:
	rm -f *.o main

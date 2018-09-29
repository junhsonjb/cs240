# Makefile for Coding Assignment 2

all: Voter

Voter: Voter.o VoterDB.o main.o
	g++ Voter.o VoterDB.o main.o -o Voter

Voter.o: Voter.cpp
	g++ -c Voter.cpp

VoterDB.o: VoterDB.cpp
	g++ -c VoterDB.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o Voter

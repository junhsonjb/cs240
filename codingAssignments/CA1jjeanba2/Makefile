# Makefile for Coding Assignment 1

all: Voter

Voter: Voter.o VoterDB.o
	g++ Voter.o VoterDB.o -o Voter

Voter.o: Voter.cpp
	g++ -c Voter.cpp

VoterDB.o: VoterDB.cpp
	g++ -c VoterDB.cpp

clean:
	rm -f *.o Voter

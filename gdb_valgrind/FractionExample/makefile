
# Here's the flag for C++11 support and a flag asking to be warned about
# everything. 
FLAGS = -Wall -std=c++11

all: Fraction

Fraction: Fraction.o FractionUser.o
	g++ $(FLAGS) Fraction.o FractionUser.o -o Fraction

Fraction.o: Fraction.cpp Fraction.h
	g++ $(FLAGS) -c Fraction.cpp -o Fraction.o

FractionUser.o: FractionUser.cpp Fraction.h
	g++ $(FLAGS) -c FractionUser.cpp -o FractionUser.o

clean:
	rm -f *.o Fraction


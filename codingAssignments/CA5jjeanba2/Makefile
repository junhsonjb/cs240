

all: main

main: Graph.o Time.o Node.o Edge.o main.o
	g++ Graph.o Time.o Node.o Edge.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

Edge.o: Edge.cpp
	g++ -c Edge.cpp

Graph.o: Graph.cpp
	g++ -c Graph.cpp

Time.o: Time.cpp
	g++ -c Time.cpp

clean:
	rm -f *.o main

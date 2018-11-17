#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Node.h"

using namespace std;

int main() {

	// declare input file information
	ifstream ddfs("ddfs1.txt");

	// if the input file is not found
	if ( ddfs.fail() ) {
		cout << "file not found" << endl;
		exit(1);
	}

	string buffer;
	int buffersize;
	string city1, city2, time1, time2, price;
	set<string> cityNames;
	list<Node> flightGraph;

	// go thru each line and process the information
	while ( getline(ddfs, buffer) ) {

		// split the info from the line into correct vars
		istringstream iss(buffer);
		iss >> city1 >> city2 >> time1 >> time2 >> price;

		// start processing the text
		if (cityNames.count(city1)  == 0) {
		
			cityNames.insert(city1);
			Node newnode1(city1);
			flightGraph.insert(newnode1);

		}

		if (cityNames.count(city2) == 0) {

			cityNames.insert(city2);
			Node newnode2(city2);
			flightGraph.insert(newnode2);

		}

		Edge newedge(time1, time2, price, getNode(city2, flightGraph));

		// Now, compare newedge to see if it is already in Node(city1)'s
		// adjacency list. If not, then add it there.
		// Once you do everything in this loop for every line in the ddfs,
		// then you should have a complete graph structure stored in memory

	}

}

// function to return pointer to a Node with a given city Name
Node * getNode(string city, list<Node> listOfNodes) {

	Node * ret;

	list<Node>::iterator it;
	for (it = listOfNodes.begin(); it != listOfNodes.end(); it++) {

		if ( it->cityName == city ) {
			ret = *it;
		}

	}

	return ret;

}

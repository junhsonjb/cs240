#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include "Node.h"
#include "Time.h"

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
	string city1, city2, time1, time2;
	float price;
	int dest; // destination city will be stored as a number (may not need this variable)
	map<string, int> cities; // map city names to numbers
	int cityCount = 0; // count for numbers in cities map
	vector<Node> flightGraph; // should be a vector

	// go thru each line and process the information
	while ( getline(ddfs, buffer) ) {

		// split the info from the line into correct vars
		istringstream iss(buffer);
		//	   origin   dest     depart   arrive   price
		iss >> city1 >> city2 >> time1 >> time2 >> price;

		// create Time objects based off of the time strings (time1 and time2)
		Time timeObj1(time1);
		Time timeObj2(time2);

		// start processing the text
		if (cities.count(city1) == 0) {
		
			cities[city1] = cityCount;
			cityCount += 1;
			Node newnode1(city1);
			flightGraph.push_back(newnode1);

		}

		if (cities.count(city2) == 0) {

			cities[city2] = cityCount;
			cityCount += 1;
			Node newnode2(city2);
			flightGraph.push_back(newnode2);

		}

		/* 
			REMEMBER: the reason we only make one edge here (one for the origin city)
			is because the graph is directed. There CANNOT be an edge for city based 
			off of the information in this line. This line ONLY gives information
			about an edge for a flight from city1 to city2 
		*/

		// Add an edge
		Edge newEdge(timeObj1, timeObj2, price, cities[city2]);

		Node currentCity;
		for (Node current : flightGraph) {
			if (current.cityName == city1) {
				currentCity = current;
			}
		}

		// Now, compare newedge to see if it is already in Node(city1)'s
		// adjacency list. If not, then add it there.

		// Add newEdge to newnode1's adjacency list IF it's not already in there
		bool found = ( find( currentCity.adjacents.begin(), currentCity.adjacents.end(), newEdge ) != currentCity.adjacents.end() );
		if ( !found ) { // if newEdge IS NOT found in newnode1's adjacency list
			currentCity.adjacents.push_back(newEdge);
		}

		// if it IS found, then just do nothing -- we don't want to add it


		// once you do everything in this loop for every line in the ddfs,
		// then you should have a complete graph structure stored in memory

		/* END OF GRAPH CREATION */

	}

}

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
	string city1, city2, time1, time2, priceString;
	float price;
	//int dest; // destination city will be stored as a number (may not need this variable)
	map<string, int> cities; // map city names to numbers
	int cityCount = 0; // count for numbers in cities map
	vector<Node> flightGraph; // should be a vector

	// go thru each line and process the information
	while ( getline(ddfs, buffer) ) {

		// split the info from the line into correct vars
		istringstream iss(buffer);
		//	   origin   dest     depart   arrive   price
		iss >> city1 >> city2 >> time1 >> time2 >> priceString;

		//cout << "The price is: $" << priceString << endl;

		// store the value in priceString in a float (price)
		price = stof(priceString.substr(1));

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

		/* Add an edge */

		//create the edge to add
		Edge newEdge(timeObj1, timeObj2, price, cities[city2]);
		//cout << newEdge.departureTime.hours << ":" << newEdge.departureTime.minutes << endl;
		//cout << "$" << newEdge.price << endl;
		//cout << newEdge.destination << endl;

		// Travesrse the graph to find the city (Node) that we will have to add newEdge to
		for (int i = 0; i <flightGraph.size(); i++) {
			if (flightGraph[i].cityName == city1) {

				// Now, compare newedge to see if it is already in Node(city1)'s
				// adjacency list. If not, then add it there.

				// Add newEdge to newnode1's adjacency list IF it's not already in there
				vector<Edge>::iterator front = flightGraph[i].adjacents.begin();
				vector<Edge>::iterator back = flightGraph[i].adjacents.end();
				bool found = (find(front, back, newEdge) != back);
				if ( !found ) { // if newEdge IS NOT found in newnode1's adjacency list
					flightGraph[i].adjacents.push_back(newEdge);
					//cout << city1 << " node size is " << flightGraph[i].adjacents.size() << endl;
				}

				// if it IS found, then just do nothing -- we don't want to add it


			}
		}


		// once you do everything in this loop for every line in the ddfs,
		// then you should have a complete graph structure stored in memory

		/* END OF GRAPH CREATION */

	}

	/* Now, to test the graph structure a little bit */

	//vector<Node>:: const_iterator it;
	//for (it = flightGraph.begin(); it != flightGraph.end(); it++) {

	//	cout << it->cityName << endl;

	//	// find out how to print each cityName (the string version from the number)

	//	for (Edge edge : it->adjacents) {

	//		cout << "\t" << "ayyy" << endl;

	//	}

	//}
	

	// printing out the mapped city to number values
	map<string, int>::iterator front = cities.begin();
	map<string, int>::iterator back = cities.end();

	cout << "City to City Number Mappings" << endl;
	for (map<string, int>::iterator it = front; it != back; it++) {

		cout << it->first << " - " << it->second << endl;

	}

	cout << endl << endl;

	cout << "Cities and Destinations from Cities" << endl;
	for (Node node : flightGraph) {

		cout << node.cityName << " - " << node.adjacents.size() << " edges" << endl;

		for (Edge edge : node.adjacents) {

			cout << "\t" << edge.destination << endl;

		}

	}

}

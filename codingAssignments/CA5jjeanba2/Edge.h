#ifndef H_Edge_H
#define H_Edge_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
//#include "Node.h" // no need b/c of forward declaration
#include "Time.h"

using namespace std;

class Node; // forward declaration

class Edge {

	public:

		Edge();
		Edge(Time dep, Time arr, float cost, int destinationNum);
		Time departureTime;
		Time arrivalTime;
		float price;
		int destination;

		bool operator==(const Edge & other);
		bool operator!=(const Edge & other);

};

#endif

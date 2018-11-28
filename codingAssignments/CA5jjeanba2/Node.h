//class Edge;
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
//#include "Node.h"
//#include "Time.h"

#include "Edge.h"

class Node{

	public:

		Node(string city);

		string cityName;
		vector<Edge> adjacents;

		void addEdge(Edge * edgeToAdd);
		bool hasEdge(Edge * edge);

};

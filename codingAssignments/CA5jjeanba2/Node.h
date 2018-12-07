#ifndef H_Node_H
#define H_Node_H

//class Edge;
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Edge.h"

using namespace std;

class Node {

	public:

		Node();
		Node(string city);

		string cityName;
		vector<Edge> adjacents;
		/* data members for traversal/shortest path */
		string color;
		double distance;
		Time dTime;
		int predecessor;

		void addEdge(const Edge & edgeToAdd);
		bool hasEdge(const Edge & edge);

		bool operator>(Node other);
		bool operator<(Node other);
		bool operator==(Node other);
		bool operator!=(Node other);

};
#endif

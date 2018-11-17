#ifndef H_Node_H
#define H_Node_H

#include "Edge.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#endif

using namespace std;

class Node {

	public:

		Node(string city);

		string cityName;
		vector<Edge> adjacents;

		void addEdge(Edge edgeToAdd);
		bool hasEdge(Edge edge);

};

#include "Node.h"
#include "Edge.h"
#include <algorithm>

Node::Node() {

	cityName = "[NOT DECLARED]";

}

Node::Node(string city) {

	cityName = city;

}

void Node::addEdge(const Edge & edgeToAdd) {

	adjacents.push_back(edgeToAdd);

}

bool Node::hasEdge(const Edge & edge) {

	// if find() returns the edge we're looking for, return true
	if ( find(adjacents.begin(), adjacents.end(), edge) != adjacents.end() ) {
		return true;
	}

	// otherwise return false
	return false;

}

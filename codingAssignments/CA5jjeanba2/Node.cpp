#include "Node.h"
#include <algorithm>

Node::Node(string city) {

	cityName = city;

}

void Node::addEdge(Edge edgeToAdd) {

	adjacents.insert(edge);

}

bool Node::hasEdge(Edge edge) {

	// if find() returns the edge we're looking for, return true
	if ( find(adjacents.begin(), adjacents.end(), edge) != adjacents.end() ) {
		return true;
	}

	// otherwise return false
	return false;

}

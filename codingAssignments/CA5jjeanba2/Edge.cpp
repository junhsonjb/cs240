#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "Time.h"
#include "Edge.h"
//#include "Node.h"

using namespace std;

Edge::Edge() {

	// set these so that we know that nothing has been defined
	price = -1.0;
	destination = -1;

}

Edge::Edge(Time dep, Time arr, float cost, int destinationNum) {

	departureTime = dep;
	arrivalTime = arr;
	price = cost;
	destination = destinationNum;

}

bool Edge::operator==(const Edge & other) {

	// if the contents of this Edge match another, return true
	if (departureTime == other.departureTime &&
		arrivalTime == other.arrivalTime &&
		price == other.price &&
		destination == other.destination) {

		return true;

	}

	// otherwise return false
	return false;

}

bool Edge::operator!=(const Edge & other) {

	return !(operator==(other));

}

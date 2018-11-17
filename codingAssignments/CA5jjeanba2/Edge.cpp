#include "Edge.h"

Edge::Edge(Time dep, Time arr, float cost, Node * to) {

	departureTime = dep;
	arrivalTime = arr;
	price = cost;
	destination = to;

}

bool Edge::operator==(const Edge & other) {

	// if the contents of this Edge match another, return true
	if (departureTime == other.departureTime &&
		arrivalTime == other.arrivalTime &&
		price == other.price &&
		destination->cityName == other.destination->cityName ) {

		return true;

	}

	// otherwise return false
	return false;

}

bool Edge::operator!=(const Edge & other) {

	return !(operator==(other));

}

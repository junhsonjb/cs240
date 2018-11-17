#ifndef H_Node_H
#define H_Node_H

#include "Edge.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Node.h"
#include "Time.h"

#endif


class Edge {

	public:

		Edge(Time dep, Time arr, float cost, Node * to);

		Time departureTime;
		Time arrivalTime;
		float price;
		Node * destination;

		bool operator==(const Edge & other);
		bool operator!=(const Edge & other);

};

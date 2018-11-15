#include "Edge.h"

class Node {

	public:

		Node(string city);

		string cityName;
		vector<Edge> adjacents;

		void addEdge(Edge edgeToAdd);

};

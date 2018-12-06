#include <algorithm>
#include <queue>
#include "Graph.h"
#include "Edge.h"

Graph::Graph(vector<Node> listOfNodes, map<string, int> cities) {

	// These collections were gathered in main()
	// so we're just going to copy them the Graph object
	allNodes = listOfNodes;
	cityMap = cities;

}

/* Given int which maps to a city C, return Node of that city */
Node * Graph::mapNode(int citynum) {

	map<string, int>::iterator first = cityMap.begin();
	map<string, int>::iterator last = cityMap.end();
	map<string, int>::iterator it;

	string retstring; // the name of the city we need to return
	Node * retval;

	// find the string (cityName) that the number corresponds to
	for (it = first; it != last; it++) {

		if (it->second == citynum) {
			retstring = it->first;
		}

	}

	// find the Node that has retstring as its cityName
	for (int i = 0; i < allNodes.size(); i++) {

		if (allNodes[i].cityName == retstring) {
			retval = &(allNodes[i]);
		}

	}

	// return the result
	return retval;

}

string Graph::mapstring(int citynum) {

	map<string, int>::iterator first = cityMap.begin();
	map<string, int>::iterator last = cityMap.end();
	map<string, int>::iterator it;

	string retstring; // the name of the city we need to return

	// find the string (cityName) that the number corresponds to
	for (it = first; it != last; it++) {

		if (it->second == citynum) {
			retstring = it->first;
		}

	}

	// return the result
	return retstring;

}

vector<string> Graph::anyFlightPlan(string start, string end) {

	if (cityMap.count(start) == 0) {
		cout << "starting city not found" << endl;
		exit(1);
	}

	if (cityMap.count(end) == 0) {
		cout << "ending city not found" << endl;
		exit(1);
	}

	vector<string> orderOfCities;

	int startnum = cityMap[start];
	int endnum = cityMap[end];

	/* find node corresponding to start city, store it in startnode */
	Node * startnode;
	Node * endnode;
	vector<Node>::iterator it;
	for (it = allNodes.begin(); it != allNodes.end(); it++) {

		if (start == end) {
			cout << "origin and destination cities are the same." << endl;
			exit(1);
		}

		if (it->cityName == start) {
			startnode = &(*it);
		}

		if (it->cityName == end) {
			endnode = &(*it);
		}

	}

	cout << "starting city: " << startnode->cityName << endl;
	cout << "ending city: " << endnode->cityName << endl;

	/*
	Every time a Node is created, it is initialized,
	with no predecessor, a distance of 0, and the color
	white. So there is no need to initialize all the 
	Nodes here. We can move straight into the traversal!
	*/

	//cout << "don't seg fault" << endl;

	startnode->color = "white";
	startnode->distance = 0;
	startnode->predecessor = -1;

	//cout << "okay I won't." << endl;

	queue<Node> fifo;
	fifo.push(*startnode); // YOU HAVE TO ADD THE SOURCE TO THE QUEUE (I forgot to do this, lol)
	//cout << "wait...I think I might have to..." << endl;
	Node * current;
	//cout << "Nah forget it, no seg faults here" << endl;
	//cout << "current city: " << current->cityName << endl;
	
	//cout << "just to check, how big is the queue we're working with? " << fifo.size() << endl;

	while (!fifo.empty() && current->cityName != end) {

		//cout << "running in while loop" << endl;
		current = &(fifo.front());
		fifo.pop();

		//cout << "okay made it here" << endl;

		/* Now to go thru the Nodes adjacent to current ... */
		//cout << "made it here" << endl;
		//cout << "why didn't it get here?" << endl;
		//cout << "because of a seg fault." << endl;
		vector<Edge>::iterator first = current->adjacents.begin();
		vector<Edge>::iterator last = current->adjacents.end();
		vector<Edge>::iterator eit;
		Node * vertex;

		//cout << "just created Node * vertex; Have not assigned any value yet" << endl;

		// for every Node adjacent to current do this...
		for (eit = first; eit != last; eit++) {

			//cout << "running in for loop (for each node adjacent to current)" << endl;

			// set vertex to point to a Node that is adjacent to current
			vertex = mapNode(eit->destination);
			//cout << "color of the vertex is: " << vertex->color << " lol" << endl;

			// fixing some weird bug
			if (vertex->color == "") {
				vertex->color = "white";
			}

			if (vertex->color == "white") {

				// the Node adjacent to current
				vertex = mapNode(eit->destination);

				vertex->color = "gray";
				vertex->distance = current->distance + 1;
				//cout << "WE ARE DOING THIS" << endl;
				//cout << "setting vertex->predecessor to " << cityMap[current->cityName] << endl;
				vertex->predecessor = cityMap[current->cityName];

				fifo.push(*vertex);

			}

		}

		//cout << "about to change current->color to 'black'" << endl;
		current->color = "black";

	}

	//cout << "done with the while loop (outside of it)" << endl;

	/*
	Here is the different part:
	If current is the destination city, then we're
	going to stop where we are because we already
	have the path that we need. From here we need to 
	print all the cities in the path until the
	predecessor is NULL
	*/

	// print the each city in the path
	// need to change this to full flight information
	//cout << "hello world" << endl;
	
	/*
	ENSURE THAT THE predecessor VALUE FOR THE SOURCE NODE (startnode)
	NEVER GETS CHANGED!
	*/
	startnode->predecessor = -1;
	//cout << "current->predecessor = " << current->predecessor << endl;
	while (current->predecessor != -1) {

		//cout << "What's an infinite loop?" << endl;
		//cout << "This is." << endl;
		//cout << "AYY" << endl;
		//cout << current->cityName << endl;
		orderOfCities.push_back(current->cityName);
		current = mapNode(current->predecessor);

	}

	// printing the last city (the one that has the
	// destination value of -1).
	//cout << current->cityName << endl;
	orderOfCities.push_back(current->cityName);

	// reverse the vector to put it in the right order
	reverse(orderOfCities.begin(), orderOfCities.end());
	return orderOfCities;

}

// comparison struct for priority queue
struct compare {

	bool operator() (float left, float right) {
		return left > right;
	}

};

void Graph::earliestFlightPlan(string start, string end) {

	int startnum = cityMap[start];
	int endnum = cityMap[end];

	Node * startnode = mapNode(startnum);
	Node * endnode = mapNode(endnum);

	// MUST WRITE THIS FUNCTION
	// AND DETERMINE IF IT SHOULD TAKE 
	// A NODE OR A POINTER TO A NODE (should take pointer)
	initSingleSource(startnode);

	vector<Node> finalWeights; // might be returning this vector
	priority_queue< Node, vector<Node>, greater<vector<Node>::value_type> > nodepq;
	vector<Node> pq; // use this vector as a priority queue

	/* Add all Nodes into nodepq */
	vector<Node>::iterator it;
	vector<Node>::iterator front = allNodes.begin();
	vector<Node>::iterator back = allNodes.end();

	for (it = front; it != back; it++) {
		pq.push(*it);
	}

	// make sure pq is a priority queue
	make_heap(pq.begin(), pq.end());
	reverse(pq.begin(), pq.end());

	Node * current;

	while (!nodepq.empty()) {

		current = (Node *) &(nodepq.top());
		nodepq.pop(); // get rid of the Node that we just stored

		finalWeights.push_back(*current);

		/* for each vertex, called vertex that is adjacent to current ... */
		vector<Edge>::iterator first = current->adjacents.begin();
		vector<Edge>::iterator last = current->adjacents.end();
		vector<Edge>::iterator eit;
		Node * vertex;

		for (eit = first; eit != last; eit++) {

			vertex = mapNode(eit->destination);
			// MUST WRITE THIS FUNCTION
			// AND ENSURE YOU ARE USING THE RIGHT WEIGHT VALUE!!!
			// (should take pointer)
			relax(current, vertex, eit->arrivalTime);

		}

	}

	// If you end up returning finalWeights, do it here
	// print the contents of finalWeights here just to check, then do above if it's right
	// Which it will be.
	for (int i = 0; i < finalWeights.size(); i++) {

		cout << finalWeights[i].cityName << endl;

	}

}

void Graph::initSingleSource(Node * source) {

	vector<Node>::iterator it;
	
	for (it = allNodes.begin(); it != allNodes.end(); it++) {

		// set all Nodes in allNodes to have distance = infinity
		// and to have predecessor = -1

		it->distance = numeric_limits<double>::infinity();
		it->predecessor = -1;
		// it->color is not used in this algorithm

	}

	// Then set distance of source to 0
	source->distance = 0;

}

void Graph::relax(Node * start, Node * end, Time weight) {

	if (end->distance > ( (float) weight.hours + (float) (weight.minutes / 60.0) )) {

		end->distance = start->distance + ( (float) weight.hours + (float) (weight.minutes / 60.0) );
		end->predecessor = cityMap[start->cityName];

	}

}













































// Extra whitespace because I like having extra whitespace while I code
// delete when done

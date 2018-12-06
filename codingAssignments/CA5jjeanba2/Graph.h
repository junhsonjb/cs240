#ifndef H_Graph_H
#define H_Graph_H

#include <vector>
#include <map>
#include "Node.h"
#include "Time.h"

using namespace std;

class Graph {

	public:

		Graph(vector<Node> allNodes, map<string, int> cities);

		vector<Node> allNodes;
		map<string, int> cityMap;

		/* Member functions */
		Node * mapNode(int cityNum); // return Node based off of #
		string mapstring(int cityNum); // return cityName from #
		vector<string> anyFlightPlan(string start, string end);
		void earliestFlightPlan(string start, string end);
		void initSingleSource(Node * source);
		void relax(Node * start, Node * end, Time weight);
};

#endif

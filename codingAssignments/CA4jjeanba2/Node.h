#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

class Node {

	public:
		// Data members
		string data = "[EMPTY STRING]";
		Node * next = nullptr; // initially a null pointer

		// Member functions
		Node(string newdata);

};

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

template<typename type>
class Node {

	public:
		// Data members
		type data; // since this is a template, should I initialize as null?
		Node<type> * next = nullptr; // initially a null pointer

		// Member functions
		Node();
		Node(type newdata);

};

// have to include this here since
// separation is not allowed
#include "Node.cpp"

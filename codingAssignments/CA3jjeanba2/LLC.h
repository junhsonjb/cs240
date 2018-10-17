#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Node.h"

using namespace std;

class LLC {

	public:

		// Data members
		Node * first; // pointer to first Node
		Node * last; // pointer to last Node

		// Member functions (and one friend!)
		LLC(); // constructor - creates an empty list
		LLC(const LLC & source); // copy constructor
		LLC & operator=(const LLC & source); // assignment operator
		~LLC(); // destructor
		bool contains(const string & value);
		bool insert(const string & value);
		bool remove(const string & value); // check return value with teacher
		bool shuffle(); // check return value with teacher
		friend LLC operator+(const LLC & aList, const LLC & bList);
		void head(int n);
		string tail();
		friend ostream & operator<<(ostream & out, const LLC & source);
		void operator+=(int n);
		int len();
		void join(LLC other);

};

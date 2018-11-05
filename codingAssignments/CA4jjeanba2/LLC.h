//#include <stdio.h>
//#include <iostream>
//#include <stdlib.h>
#include <vector>
#include "Node.h"

using namespace std;

template <typename type>
class LLC {

	public:

		// Node Class
		// template <typename ntype>
		// class Node {

		// 	Node();
		// 	Node(); // make this a value constructor

		// 	ntype = NULL;
		// 	Node

		// };

		// Data members
		Node<type> * first; // pointer to first Node
		Node<type> * last; // pointer to last Node

		// Member functions (and one friend!)
		LLC(); // constructor - creates an empty list
		LLC(const LLC & source); // copy constructor
		LLC & operator=(const LLC & source); // assignment operator
		~LLC(); // destructor
		bool contains(const type & value);
		bool insert(const type & value);
		bool remove(const type & value); // check return value with teacher
		bool shuffle(); // check return value with teacher
		void head(int n);
		type tail();
		void operator+=(int n);
		int len();
		void join(LLC other);
		type back();
		type removeBack();

		template <typename theType>
		friend LLC<theType> operator+(const LLC<theType> & aList, const LLC<theType> & bList);
		template <typename theType>
		friend ostream & operator<< (ostream & out, const LLC<theType> & source);
};

// have to include this here because templates
// don't allow separate compilation

#include "LLC.cpp"


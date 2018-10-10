#include "LLC.h"

// Constructor creates an empty list
LLC::LLC() {

	// an empty list is one that has
	// a null first pointer
	// of course, since there is no first,
	// there is also no lastl
	first = nullptr;
	last = nullptr;

}

// Copy Constructor stores a deep copy
// of param in the new LLC being created
LLC::LLC(const LLC & source) {

	Node * temp;
	for (temp = source->first; temp != nullptr; temp = temp->next)
	{

		// insert a new node with the data from the
		// current source node
		insert(temp->data);	

	}

}


LLC & LLC::operator=(const string & value) {

	// similar to copy constructor,
	// except you make a new LLC,
	// do all the storing into that and then
	// return the new LLC object that you just made!
	// use insert() !

}

LLC::~LLC() {

	// Need to delete each node from the heap
	
	//Node * current, * upcoming, * pos;

	//for (pos = first; pos != nullptr; pos = pos->next) {

	//	

	//}

}

bool LLC::contains(const string & value) {

	// check if this LLC contains a given string, value
	
	// travese LLC and check if value is present in
	// each node

	Node * temp;
	for (temp = first; temp != nullptr; temp = temp->next) {

		if (temp->data == value)
			return true;

	}

	// if we get thru the whole
	// list without returning true, then our value
	// isn't present in LLC, return false!
	return false;

}


bool LLC::insert(const string & value) {

	// set the next property of the last
	// Node to a new node containing value
	// as its data
	// then change the next property to be
	// the newly created node

	Node * newNode(value);

	// if there is no first, make newNode the new first (and last)
	if (first == nullptr) {
		first = newNode;
		last = newNode;
	} else {
		last->next = newNode;
		last = newNode;
	}

	return true;

}

bool LLC::remove(const string & value) {

	// Don't forget to use the delete
	// keyword to free the allocated space
	// of ALL of the Nodes you delete
	// (delete all node with data that 
	// matches value)

	// must traverse the LLC
	Node * curr;
	Node * prev;

	for (curr = first; curr != nullptr; curr = curr->next) {

		if (curr->data == value) {

			// if not first or last node
			if (curr != first && curr != last) {
				prev->next = curr->next;
			}

			// if first node
			if (curr == first) {
				first = curr->next;
			}

			// if last node
			if (curr == last) {
				prev->next = nullptr;
				
				//since this is the last iteration
				// we can (and have to) delete the
				// last node right here!
				delete(last);
				last = curr;
			}

		}

		prev = curr;
		// We have not yet deleted the removed nodes
		// from memory. WE NEED TO FIGURE OUT HOW TO DO THIS!!!

	}

}



















// extra whitespace because I like
// having space under my last line
// please delete when no longer needed

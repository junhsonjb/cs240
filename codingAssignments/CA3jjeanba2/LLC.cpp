#include <time.h>
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
	for (temp = source.first; temp != nullptr; temp = temp->next)
	{

		// insert a new node with the data from the
		// current source node
		insert(temp->data);	// insert function handles setting first and last

	}

}


LLC LLC::operator=(const LLC & source) { // return LLC or & LLC (referece)?

	// similar to copy constructor,
	// except you make a new LLC,
	// do all the storing into that and then
	// return the new LLC object that you just made!
	// use insert() !

	LLC newlist;
	Node * temp;

	for (temp = first; temp != nullptr; temp = temp->next) {
		newlist.insert(temp->data);
	}

	return newlist;

}

//LLC::~LLC() {
//
//	// Need to delete each node from the heap
//	
//	//Node * current, * upcoming, * pos;
//
//	//for (pos = first; pos != nullptr; pos = pos->next) {
//
//	//	
//
//	//}
//
//}

// Destructor
LLC::~LLC() {

	Node * temp;
	for (temp = first; temp != nullptr; temp = temp->next) {
		remove(temp->data);
	}

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

	// cout << value << endl; // this line needs to go (testing)

	// Node * newNode;
	// newNode->data = value;
	Node * newNode = new Node(value);
	
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
	Node * nodeToDelete;

	// HOW TO DELETE THE REMOVED ("UNLINKED") NODE
	// create a node pointer to point to the link
	// that you want to delete, then once you
	// "unlink" it, you can use the delete() keyword
	// to delete it

	for (curr = first; curr != nullptr; curr = curr->next) {

		if (curr->data == value) {

			// if not first or last node (middle)
			if (curr != first && curr != last) {
				nodeToDelete = curr;
				prev->next = curr->next;
				delete(nodeToDelete);
			}

			// if first node
			if (curr == first) {
				nodeToDelete = curr;
				first = curr->next;
				delete(nodeToDelete);
			}

			// if last node
			if (curr == last) {
				nodeToDelete = curr;
				prev->next = nullptr;
				
				last = curr;
				delete(nodeToDelete);
			}

		}

		// Set prev to curr for when curr
		// becomes curr->next
		prev = curr;

	}

}

bool LLC::shuffle() {

	// Need a seed to create random numbers
	srand(time(nullptr));

	vector<string> dstrings;

	Node * temp;
	string sTemp;
	for (temp = first; temp != nullptr; temp = temp->next) {
		dstrings.push_back(temp->data);
	}

	int numChanges = rand() % 10, indexA, indexB;

	for (int i = 0; i < numChanges; i++) {

		indexA = rand() % dstrings.size();
		indexB = rand() % dstrings.size();

		// swap the strings at indexA and indexB
		sTemp = dstrings[indexA];
		dstrings[indexA] = dstrings[indexB];
		dstrings[indexB] = dstrings[indexA];

	}

	// now replace the current order of strings 
	// in the linked list, with the order that
	// is in dstrings
	for (temp = first; temp != nullptr; temp = temp->next) {
		temp->data = dstrings[dstrings.size() - 1];
		dstrings.pop_back(); // remove the last string to avoid repeating unnecessarily
	}

}

LLC operator+(const LLC & aList, const LLC & bList) {

	// start newlist off as a copy of the aList
	LLC newlist(aList);

	// Now we only have to add the contents of bList to newlist
	Node * temp;
	for (temp = aList.first; temp != nullptr; temp = temp->next) {
		newlist.insert(temp->data);
	}

	return newlist;

}

void LLC::head(int n) {

	string result = "";
	Node * temp = first;
	
	// check that n is not more than the amt of nodes in the list
	if (n > len()) n = len(); // set it to len() if it is (avoid going out of bounds)

	for (int i = 0; i < (n - 1); i++) {
		result += temp->data + ", ";
		temp = temp->next;
	}

	result += temp->next->next->data;

	cout << "[" << result << "]" << endl;

}

string LLC::tail() {

	if (last != nullptr) {
		cout << last->data << endl;
		return last->data;
	}

	cout << "last pointer does not exist (nullptr)" << endl;

}

ostream & operator<<(ostream & out, const LLC & source) {

	string result = ""; // string to send to the stream, out

	Node * temp;
	for (temp = source.first; temp->next != nullptr; temp = temp->next) {
		result += temp->data + ", ";
	}

	result += temp->data;

	out << "[" << result << "]";

	return out;

}

void LLC::operator+=(int n) {

	Node * temp;

	// We need to shift the first node into the last spot
	// and we need to do this shift n time.
	for (int i = 0; i < n; i++) {

		// change first from what it is to the next node
		// also store the original first in temp
		temp = first;
		first = first->next;

		// set the original first (temp) to be the actual last node
		// also make LLC's last pointer point to the new last node
		// then make sure that the last pointer's next points to nullptr
		last->next = temp;
		last = temp;
		temp->next = nullptr;

	}

}

int LLC::len() {

	int count = 0;
	Node * temp;

	for (temp = first; temp != nullptr; temp = temp->next) {
		count += 1;
	}

	return count;

}

void LLC::join(LLC other) {

	last->next = other.first;
	last = other.last;

}

















// extra whitespace because I like
// having space under my last line
// please delete when no longer needed

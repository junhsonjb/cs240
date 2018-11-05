#include <time.h>
//#include "LLC.h"

// Constructor creates an empty list
template <typename type>
LLC<type>::LLC() {

	// an empty list is one that has
	// a null first pointer
	// of course, since there is no first,
	// there is also no lastl
	first = nullptr;
	last = nullptr;

}

// Copy Constructor stores a deep copy
// of param in the new LLC being created
template <typename type>
LLC<type>::LLC(const LLC & source) {

	first = nullptr;
	last = nullptr;

    // cout << "Copy constructor" << endl << std::flush;
    // cout << source << endl; 

	Node<type> * temp;
	for (temp = source.first; temp != nullptr; temp = temp->next)
	{
        // cout << "CC inserting " << temp->data << endl << std::flush;
		// insert a new node with the data from the
		// current source node
		insert(temp->data);	// insert function handles setting first and last
        // cout << "CC done inserting " << temp->data << endl << std::flush;
	}

	// cout << "Hello from copy constructor!" << endl << std::flush;

}

template <typename type>
LLC<type> & LLC<type>::operator=(const LLC & source) { // return LLC or & LLC (referece)?

	first = nullptr;
	last = nullptr;

	if (this != & source) {

		// must first delete all data currently in this LLC

		Node<type> * curr, * prev;
		
		curr = first;
		prev = nullptr;

		while (curr != nullptr) {

			if (prev)
				delete(prev);

			// shift curr and prev pointers
			prev = curr;
			curr = curr->next;

		}

		delete(last);

		// now we can copy source to this LLC

		if (source.first == nullptr)
			return * this;

		Node<type> * newNode, * temp;
		temp = source.first;

		newNode = new Node<type>(temp->data);
		first = newNode;
		last = newNode;
		
		if (temp->next == nullptr)
			return * this;

		for (temp = temp->next; temp != nullptr; temp = temp->next) {

			newNode = new Node<type>(temp->data);
			last->next = newNode;
			last = last->next;

		}

		return * this;

	}

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
template <typename type>
LLC<type>::~LLC() {

	Node<type> * temp;
	Node<type> * prev = nullptr;
	Node<type> * del;

	temp = first;
	while (temp != nullptr) {

		if (prev) {
			del = prev;
			// cout << "deleting " << del-> data << endl; // for testing
			delete(del);
		}

		// shift pointers for the next iteration
		prev = temp;
		temp = temp->next;

	}


	// now, the only remaining node is the last node,
	// which we have a pointer to already
	del = prev;
	// cout << "finally deleting " << del->data << endl; // for testing
	delete(del);


}

template <typename type>
bool LLC<type>::contains(const type & value) {

	// check if this LLC contains a given string, value
	
	// travese LLC and check if value is present in
	// each node

	Node<type> * temp;
	for (temp = first; temp != nullptr; temp = temp->next) {

		if (temp->data == value)
			return true;

	}

	// if we get thru the whole
	// list without returning true, then our value
	// isn't present in LLC, return false!
	return false;

}

template <typename type>
bool LLC<type>::insert(const type & value) {

	// set the next property of the last
	// Node to a new node containing value
	// as its data
	// then change the next property to be
	// the newly created node

	// cout << value << endl; // this line needs to go (testing)

	// Node * newNode;
	// newNode->data = value;
    // cout << "A Inside insert "  << value << endl;

	Node<type> * newNode = new (std::nothrow) Node<type>(value);
    if (newNode == nullptr) {
       cout << "WHY?" << endl;
       exit(1);
    }

    // cout << "B Inside insert "  << value << endl;
	
	// if there is no first, make newNode the new first (and last)
	if (first == nullptr) {
		first = newNode;
		last = newNode;
	} else {
		last->next = newNode;
		last = newNode;
	}
    // cout << "C Inside insert "  << value << endl;

	return true;

}

template<typename type>
bool LLC<type>::remove(const type & value) {

	// Don't forget to use the delete
	// keyword to free the allocated space
	// of ALL of the Nodes you delete
	// (delete all node with data that 
	// matches value)

	// must traverse the LLC
	Node<type> * curr;
	Node<type> * prev;
	Node<type> * nodeToDelete;

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
    return true;
}

template <typename type>
bool LLC<type>::shuffle() {

	// Need a seed to create random numbers
	srand(time(nullptr));

	vector<type> dstrings;

	Node<type> * temp;
	for (temp = first; temp != nullptr; temp = temp->next) {
		dstrings.push_back(temp->data);
	}

	// for testing, see contents of dstrings
	// for (string x : dstrings) cout << x << endl;

	int numChanges = rand() % 10, indexA, indexB;
	type sTemp;

	for (int i = 0; i < numChanges; i++) {

		// set random indexes at which to swap strings
		indexA = rand() % dstrings.size();
		indexB = rand() % dstrings.size();

		// swap the strings at indexA and indexB
		sTemp = dstrings[indexA];
		dstrings[indexA] = dstrings[indexB];
		dstrings[indexB] = sTemp;

	}

	// now replace the current order of strings 
	// in the linked list, with the order that
	// is in dstrings
	for (temp = first; temp != nullptr; temp = temp->next) {
		temp->data = dstrings[dstrings.size() - 1];
		dstrings.pop_back(); // remove the last string to avoid repeating unnecessarily
	}
    return true;
}

template <typename type>
LLC<type> operator+(const LLC<type> & aList, const LLC<type> & bList) {

	// start newlist off as a copy of the aList
	LLC<type> newlist;
	Node<type> * temp, * newNode;

	temp = aList.first;
	newNode = new Node<type>(temp->data);
	newlist.first = newNode;
	newlist.last = newNode;

	for (temp = aList.first->next; temp != nullptr; temp = temp->next) {

		newNode = new Node<type>(temp->data);
		newlist.last->next = newNode;
		newlist.last = newlist.last->next;

	}	

	for (temp = bList.first; temp != nullptr; temp = temp->next) {

		newNode = new Node<type>(temp->data);
		newlist.last->next = newNode;
		newlist.last = newlist.last->next;

	}	

	return newlist;

}

template <typename type>
void LLC<type>::head(int n) {

	string result = "";
	Node<type> * temp = first;
	
	// check that n is not more than the amt of nodes in the list
	if (n > len()) n = len(); // set it to len() if it is (avoid going out of bounds)

	for (int i = 0; i < (n - 1); i++) {
		result += temp->data + ", ";
		temp = temp->next;
	}

	result += temp->data;

	cout << "[" << result << "]" << endl;

}

template <typename type>
type LLC<type>::tail() {

	if (last != nullptr) {
		cout << last->data << endl;
		return last->data;
	}

	cout << "[NO <type> RETURNED]" << endl;

	type nullret;
	return nullret;

}

template <typename type>
type LLC<type>::back() {

	// assume that the rest of the code
	// ensures that the last pointer
	// will never be nullptr
	return last->data;

}

template <typename type>
type LLC<type>::removeBack() {

	if (len() == 1 || len() == 0) {

		first = nullptr;
		last = nullptr;

		type nullret;
		return nullret;

	}

	Node<type> * curr;
	Node<type> * prev;
	Node<type> * nodeToDelete;
	type returnVal;
	for (curr = first; curr->next != nullptr; curr = curr->next) {

		prev = curr;

	}

	nodeToDelete = curr;
	last = prev;
	last->next = nullptr;
	returnVal = nodeToDelete->data;
	delete(nodeToDelete);
	return returnVal;

}

template <typename type> // do I need the template signature here?
ostream & operator<< (ostream & out, const LLC<type> & source) {

	if (source.first == nullptr) {
		out << "[ (no content) ]";
		return out;
	}

	//string result = ""; // string to send to the stream, out

	out << "[";

	Node<type> * temp;
	for (temp = source.first; temp->next != nullptr; temp = temp->next) {
		// result += temp->data + ", ";

		out << temp->data << ", ";

	}

	// result += temp->data;
	out << temp->data;
	out << "]";

	// out << "[" << result << "]";

	return out;

}

template <typename type>
void LLC<type>::operator+=(int n) {

	Node<type> * temp;

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

template <typename type>
int LLC<type>::len() {

	int count = 0;
	Node<type> * temp;

	for (temp = first; temp != nullptr; temp = temp->next) {
		count += 1;
	}

	return count;

}

template <typename type>
void LLC<type>::join(LLC other) {
	// cout << "DID THE BEAT DROP? LOL" << endl; // for testing

	Node<type> * temp, * newNode;
	temp = other.first;
	
	for (temp = other.first; temp != nullptr; temp = temp->next) {

		newNode = new Node<type>(temp->data);
		last->next = newNode;
		last = last->next;

	}

	// last->next = other.first;
	// last = other.last;

}














// extra whitespace because I like
// having space under my last line
// please delete when no longer needed

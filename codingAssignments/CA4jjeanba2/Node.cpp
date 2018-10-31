//template <typename type>
//class Node{};

// Default Constructor
template <typename type>
Node<type>::Node() {
	// data = NULL;
	next = nullptr;
}

// Constructor
template <typename type>
Node<type>::Node(type newdata) {

	// initialize this node from the data given
	data = newdata;
	next = nullptr;

}

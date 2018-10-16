#include "LLC.h"

int main() {

	LLC test;
	test.insert("Michael");
	test.insert("Holly");
	test.insert("Angela");
	test.insert("Dwigt");
	
	cout << test << endl;

	cout << "Seg Fault, anyone?" << endl;

	return 1;

}

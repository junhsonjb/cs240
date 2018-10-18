#include "LLC.h"

int main() {

	LLC test1;
	test1.insert("Michael");
	test1.insert("Holly");
	test1.insert("Angela");
	test1.insert("Dwigt");
	
	cout << "test1: " << test1 << endl;

	LLC test2(test1);
	cout << "test2: " << test2 << endl;

	 LLC test3;
	 test3 = test2;
	 cout << "test3: " << test3 << endl;

	// test the destructor later
	// make an LLC obj in another function and 
	// see how it destructs.

	if (test1.contains("Michael")) cout << "Michael Scott in the house!" << endl;
	if (!test1.contains("Jim")) cout << "Jimothy has not yet arrived" << endl;

	test3.insert("Packer");
	cout << "test3: " << test3 << endl;

	test3.remove("Packer");
	cout << "test3: " << test3 << endl;

	test3.shuffle();
	cout << "test3: " << test3 << " (shuffled) " << endl;

	LLC test4, test5;
	test4.insert("Andy");
	test4.insert("Erin");
	cout << "test4: " << test4 << endl;
	
	test5.insert("Kelly");
	test5.insert("Ryan");
	cout << "test5: " << test5 << endl;

	LLC test6;
	test6 = test4 + test5; 
	cout << "test6: " << test6 << " = test4 + test5 " << endl;

	test1.head(2);

	test1.tail();
	test4.tail();
	test6.tail();
	cout << "did the beat drop?" << endl;

	LLC test7;
	test7.insert("one");
	test7.insert("two");
	test7.insert("three");
	test7.insert("four");

	test7 += 2;
	cout << "test7: " << test7 << endl;

	cout << "test7 is length " << test7.len() << endl;

	// LLC test8;
	// test8.insert("Jim"); test8.insert("Pam");
	// LLC test9;
	// test9.insert("Nelly"); test9.insert("Toby");

	// cout << "Okay, I guess you can just stop here" << endl; // for testing

	// cout << "test8: " << test8 << endl;
	// cout << "test9: " << test9 << endl;

	// test8.join(test9);
	// cout << "test8: " << test8 << " test8.join(test9)" << endl;

	return 0;

}  

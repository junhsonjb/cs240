#include "Voter.h"

Voter::Voter(string lname, string fname, string username, string pass, string street, string theTown, string zip, int howOld, int num) {

	// implement the constructor!
	last = lname; first = fname; 
	userid = username; password = pass;
	street_name = street; town = theTown;
	zip_code = zip; age = howOld; street_num = num;
	amount_donated = 0.00;

}

void Voter::login() {

	// basically this function needs to be a 
	// while loop, it should be very comparable
	// to the while loop from CA1.
	// It needs to answer to all of the second
	// level (user-level) menu and any "wrong" input

	bool inProgram = true;
	string input;

	// This is just for testing, we'll have
	// to actually implement this function soon
	cout << "Welcome to the 2nd Level!" << endl;

//	while (inProgram) {
//
//		cout << "Enter a command: " << endl;
//		cin >> input;
//
//	}

}

string Voter::getUserid() { return userid; }
string Voter::getPassword() { return password; }

float Voter::getAmountDonated() { return amount_donated; }

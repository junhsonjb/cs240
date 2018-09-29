#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Voter {

	private:
		string first, last; // first and last names
		string userid; // has between 5 and 10 chars only letters and digits
		string password; // has 6 or more chars, at least one digit and non letter char
		string street_name, town; // street and town names
		string zip_code; // MUST have exactly 5 characters

		int age, street_num;
		float amount_donated;

	public:
		Voter(string last, string first, string userid, string pass, string street, string town, string zip, int age, int num);
		void update();
		void changePassword();
		void view();
		void donate();
		void report();
		void login();
		// Need a function for writing object data to a .csv file
		string getUserid();
		string getPassword();
		float getAmountDonated();

};

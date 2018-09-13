#include "VoterDB.h"

void new_info(string &last, string &first, int &age, int &street_num, string &street_name, string &town, string &zip_code, float &amount_donated) {

 	cout << "Last Name: ";
 	// getline(cin, last);
	cin >> last;

	cout << "First Name: ";
	// getline(cin, first);
	cin >> first;

	cout << "Age: ";
	cin >> age;
	// cin.ignore();

	cout << "House Number: ";
	cin >> street_num;
	// cin.ignore();

	cout << "Street Name: ";
	// getline(cin, street_name);
	cin >> street_name;
	
	cout << "Town: ";
	// getline(cin, town);
	cin >> town;

	cout << "Zip Code: ";
	cin >> zip_code;

	// zero out the amount donated
	amount_donated = 0;

	// print a new line
	cout << endl;

} 

void update_info(string &last, string &first, int &age, int &street_num, string &street_name, string &town, string &zip_code) {

	// cout << "Enter input as such: " << endl;
	// cout << "last first age street_num street_name town zip_code" << endl;

	// cin >> last >> first >> age >> street_num >> street_name >> town >> zip_code;

	
 	cout << "Last Name: ";
 	// getline(cin, last);
	cin >> last;

	cout << "First Name: ";
	// getline(cin, first);
	cin >> first;

	cout << "Age: ";
	cin >> age;
	// cin.ignore();

	cout << "House Number: ";
	cin >> street_num;
	// cin.ignore();

	cout << "Street Name: ";
	// getline(cin, street_name);
	cin >> street_name;
	
	cout << "Town: ";
	// getline(cin, town);
	cin >> town;

	cout << "Zip Code: ";
	cin >> zip_code;

	// print a new line
	cout << endl;

} 

void view_info(string last, string first, int age, int street_num, string street_name, string town, string zip_code, float amount_donated) {

	cout << endl << "Donor Info:" << endl;
	cout << first << " " << last << ": age " << age << endl;
	cout << street_num << " " << street_name << endl;
	cout << town << " " << zip_code << endl;
	cout << "Current Amount Donated: "; printf("$%.2f", amount_donated);

	// print a new line
	cout << endl;

}

void donate(float &amount_donated) {

	float amount_to_add;

	cout << "Enter Amount to Donate: ";
	cin >> amount_to_add;

	amount_donated += amount_to_add;

}

void report_info(string last, float amount_donated) {

	cout << last << " ";
	printf("$%.2f\n", last, amount_donated);

	// print a new line
	cout << endl;

}

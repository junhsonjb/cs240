#include "VoterDB.h"

void new_info(string &last, string &first, int &age, int &street_num, string &street_name, string &town, string &zip_code, float &amount_donated) {

 	cout << "What is your last name? ";
 	getline(cin, last);

	cout << "What is your first name? ";
	getline(cin, first);

	cout << "How old are you (in years)? ";
	cin >> age;
	cin.ignore();

	cout << "What is your street number? ";
	cin >> street_num;
	cin.ignore();

	cout << "What is your street name? ";
	getline(cin, street_name);

	cout << "What's the name of your town? ";
	getline(cin, town);

	cout << "What's the zip code? ";
	cin >> zip_code;

	cout << "How much are you donating? ";
	cin >> amount_donated;

} 

void update_info(string &last, string &first, int &age, int &street_num, string &street_name, string &town, string &zip_code) {

	// cout << "Enter input as such: " << endl;
	// cout << "last first age street_num street_name town zip_code" << endl;

	// cin >> last >> first >> age >> street_num >> street_name >> town >> zip_code;

	
 	cout << "What is your last name? ";
 	getline(cin, last);

	cout << "What is your first name? ";
	getline(cin, first);

	cout << "How old are you (in years)? ";
	cin >> age;
	cin.ignore();

	cout << "What is your street number? ";
	cin >> street_num;
	cin.ignore();

	cout << "What is your street name? ";
	getline(cin, street_name);

	cout << "What's the name of your town? ";
	getline(cin, town);

	cout << "What's the zip code? ";
	cin >> zip_code;

} 

void view_info(string last, string first, int age, int street_num, string street_name, string town, string zip_code, float amount_donated) {

	cout << "Last name: " << last << endl;
	cout << "First name: " << first << endl;
	cout << "Age: " << age << endl;
	cout << "Street number: " << street_num << endl;
	cout << "Street name: " << street_name << endl;
	cout << "Town: " << town << endl;
	cout << "Zip code: " << zip_code << endl;
	// cout << "Amount donated: " << amount_donated << endl;
	printf("Amount donated: $%.2f\n", amount_donated);

}

void donate(float &amount_donated) {

	cout << "Enter the amount of money you would like to add: " << endl;

	int amount_to_add;
	cin >> amount_to_add;

	amount_donated += amount_to_add;

}

void report_info(string last, float amount_donated) {

	cout << last << " ";
	printf("$%.2f\n", last, amount_donated);

}

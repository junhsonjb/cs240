#include "VoterDB.h"

using namespace std;

int main() {

	// store user inputText
	string inputText = "";

	// store voter data
	string last, first, street_name, town, zip_code;
	int age, street_num;
	float amount_donated;	
	bool quitProgram = false;

	while (!quitProgram) {
		
		cout << "Enter the command you would like to execute: " << endl;
		getline(cin, inputText);
		// cin >> inputText;
		// cin.ignore();
	
		if (inputText == "New") new_info(last, first, age, street_num, street_name, town, zip_code, amount_donated);
		else if (inputText == "Update") update_info(last, first, age, street_num, street_name, town, zip_code);
		else if (inputText == "View") view_info(last, first, age, street_num, street_name, town, zip_code, amount_donated);
		else if (inputText == "Donate") donate(amount_donated);
		else if (inputText == "Report") report_info(last, amount_donated);
		else if (inputText == "Quit") quitProgram = true;
		else
			cout << "That's not one of the commands we expected." << endl;
	
	}

	return 0;

}

#include "VoterDB.h"

int main(int argc, char ** argv) {

	// ensure the user enters at least two command line args
	if (argc < 2) {
		cout << "please run as ./" << argv[0] << " <max_number> <optional_file>" << endl;	
		return 1;
	}

	// ensure that the max number of voters is a valid number
	if (stoi(argv[1]) < 1 || stoi(argv[1]) > 100) {
		cout << "maximum number of voters must be between 1 and 100" << endl;
		return 1;
	}

	// store the cmd line arg that specifies the maximum amt of voters 
	// that are allowed in the database
	int max_voters = stoi(argv[1]);

	// if the user gave us a filename in the cmd line
	// then store it as a string (for now)
	if (argc >= 3)
		string filename = argv[2];	

	bool inProgram = true; // bool to continue/leave while loop for db menu
	string inputString; // string to store the user's input

	VoterDB database(max_voters); // declare our VoterDB object

	// this while loop is the top-level menu,
	// where the user can type in commands that control the database
	while (inProgram) {

		cout << "Enter command: " << endl; // prompt for input
		cin >> inputString; // store the input

		if (inputString == "Login") {
			// run Login function if user is found
			// this function should have a while loop
			// that makes it go to the "second level" menu

			// take the input and compare to all present Voters to log in
			string userid = "", password = "";
			cout << "Username: ";
			cin >> userid;

			cout << "Password: ";
			cin >> password;

			// VoterDB has a function to check if a user is
			// present based on a given userid and password
			// we use it here

			// if the id/pass combo is a match,
			// have that Voter call its login function!
			Voter * user = database.findUser(userid, password);
			if (user)
				user->login();

			// if the user isn't found then just keep going on
			// with the loop. We don't have to write any code
			// to specify this!
			
		}	

		else if (inputString == "New") {

			// make a new user and add it to the database
			// ensure that there are no more voters in database than the max
			// ensure that new userid is not already in use

			// take in input parameters one by one and
			// pass each one into Voter's constructor

			// DO NOT FORGET about the constraints on
			// the inputs (see CA2 pdf) you can handle
			// them here!

			string last, first;
			string userid; // constraints
			string pass; // constraints
			string street_name; // constraints
			string town; // constraints
			string zip; // constraints
			int age, street_num;

			bool invalidInfo = true;

			while(invalidInfo) {

				// take input
	
				cout << "first name: ";
				getline(cin, first); cin.ignore(); //cin >> first;
	
				cout << "last name: ";
				getline(cin, last); cin.ignore();//cin >> last;
	
				cout << "userid: ";
				getline(cin, userid); cin.ignore(); //cin >> userid;
	
				cout << "password: ";
				getline(cin, pass); cin.ignore(); //cin >> pass;
	
				cout << "street name: ";
				getline(cin, street_name); cin.ignore();
	
				cout << "town: ";
				getline(cin, town); cin.ignore();
	
				cout << "zip code: ";
				getline(cin, zip); cin.ignore();
	
				cout << "age: ";
				string temp; getline(cin, temp); age = stoi(temp); cin.ignore();
	
				cout << "street_num: ";
				getline(cin, temp); street_num = stoi(temp);  cin.ignore();

				// check that the new input is valid
				// before using it (based off instructions in pdf)

				if ( (userid.size() > 4) &&
					 (userid.size() < 11) &&
					 (userid.find_first_of("~`!@#$%^&*()_+=[{]}|\\;:'\"<,>.?/") == string::npos) &&
					 (pass.size() >= 6) &&
					 (pass.find_first_of("0123456789") != string::npos) &&
					 (pass.find_first_of("~`!@#$%^&*()_+=[{]}|\\;:'\"<,>.?/") != string::npos) &&	
					 (zip.size() == 5) &&
					 ( (int)( stoi(zip) / (10000) ) >= 1 && (int)( stoi(zip) / (10000)) <= 9 )
					) {

					invalidInfo = false;

				} else {

					cout << "Please follow the guidelines for Voter fields. Try again " << endl << endl;

				}
				
			}


			// Once we've determined that the input is good,
			// We can use that info to make a new Voter
			// and add it to the database

			Voter newVoter(last, first, userid, pass, street_name, town, zip, age, street_num);

			if (database.addVoter(newVoter))
				cout << "Voter successfully added!" << endl;
			else
				cout << "Database already full, voter not added. " << endl;

			//Voter * newVoter(
			// (for above) find out about declaring 
			// objects when they are pointers

		}

		else if (inputString == "Report") {
			// database report function

			cout << "Voters in database: " << database.sumVoters() << endl;
			cout << "Total donated: " << database.sumDonated() << endl;

		}

		else if (inputString == "Save") {
			// database save function
		}

		else if (inputString == "Load") {
			// database load function
		}


		else if (inputString == "Quit") {

			inProgram = false;

		}

		else {
			// handle any wrong input

			cout << "Input Not Expected, please try again. " << endl;

		}


	}

}

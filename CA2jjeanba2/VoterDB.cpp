#include "VoterDB.h"

VoterDB::VoterDB(int max_voter_amount) {

	// initialize the dynamic array with the specified amt of Voters
	allVoters = new Voter [max_voter_amount];
	max_voters = max_voter_amount;
	numVoters = 0; // start off with zero

}

//implement this function!
bool VoterDB::addVoter(Voter voterToAdd) {

	// the voter should have been constructed
	// inside of the main.cpp file, so that 
	// Voter should be simply passed in and added
	// to allVoters.

	// also increment the number of Voters variable
	// and be sure that we're not adding more than
	// maximum amount of voters.

	// max_voters and numVoters

	if (numVoters < max_voters) {

		// add voterToAdd and update numVoters
		numVoters += 1;
		allVoters[numVoters] = voterToAdd;
		return true;

	}

	return false;

}

int VoterDB::sumVoters() {
	
	return numVoters; 

}

float VoterDB::sumDonated() {

	float sum = 0;

	for (int i = 0; i < max_voters; i++) {

		sum += allVoters[i].getAmountDonated();

	}

	return sum;	

}

Voter* VoterDB::findUser(string userid, string password) {

	for (int i = 0; i < max_voters; i++) {

		if (allVoters[i].getUserid() == userid && allVoters[i].getPassword() == password)
			return &allVoters[i];

	}

	return nullptr;

}

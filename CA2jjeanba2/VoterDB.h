#include <iostream>
#include <stdlib.h>
#include "Voter.h"

using namespace std;

class VoterDB {

	public:
		VoterDB(int max_voter_amount);
		bool addVoter(Voter voterToAdd);
		Voter* findUser(string userid, string password);
		void addUser(Voter newVoter);
		int sumVoters();
		float sumDonated();


	private:
		Voter * allVoters;
		int max_voters;
		int numVoters; // needs to be updated with each new voter

};

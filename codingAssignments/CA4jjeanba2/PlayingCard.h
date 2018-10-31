//#include "LLC.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class PlayingCard {

	public: //private: // should these be public? Ask!
		string value;
		string suit;

	public:
		PlayingCard();
		PlayingCard(string pc_value, string pc_suit);
		friend ostream & operator<<(ostream & out, const PlayingCard & pc);
		bool operator<(const PlayingCard & other);
		bool operator>(const PlayingCard & other);
		bool operator==(const PlayingCard & other);
		bool operator!=(const PlayingCard & other) {
           // define this list that will hold each possible
           // value, and it's index will serve as the rank

           // map<string, int> rankings;
           // for (int i = 0; i < 9; i++) {
           //  rankings[ to_string(i + 2) ] = i;
           // }
           // rankings["J"] = 9;
           // rankings["Q"] = 10;
           // rankings["K"] = 11;
           // rankings["A"] = 12;

           // return !(rankings[value] == rankings[other.value]);

           return !(this->operator==(other));
        }
};

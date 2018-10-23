#include "PlayingCard.h"
#include <map>

PlayingCard::PlayingCard() {
	value = "[NO VALUE]";
	suit = "[NO SUIT]";
}

PlayingCard::PlayingCard(string pc_value, string pc_suit) {

	value = pc_value;
	suit = pc_suit;

}

ostream & operator<<(ostream & out, const PlayingCard & pc) {

	out << pc.value << pc.suit;
	return out;

}

bool PlayingCard::operator<(const PlayingCard & other) {

	// define this list that will hold each possible
	// value, and it's index will serve as the rank

	map<string, int> rankings;
	for (int i = 0; i < 9; i++) {
		rankings[ to_string(i + 2) ] = i;
	}
	rankings["J"] = 9;
	rankings["Q"] = 10;
	rankings["K"] = 11;
	rankings["A"] = 12;

	// for testing
	// cout << "Value - Ranking";
	// for (map<string, int>::iterator it = rankings.begin(); it != rankings.end(); it++) {
	// 	
	// 	cout << it->first << " - " << it->second << endl;

	// }

	// return whether or not the ranking of this card
	// value is less than the card value of other
	return rankings[value] < rankings[other.value];

}

bool PlayingCard::operator>(const PlayingCard & other) {

	// define this list that will hold each possible
	// value, and it's index will serve as the rank

	map<string, int> rankings;
	for (int i = 0; i < 9; i++) {
		rankings[ to_string(i + 2) ] = i;
	}
	rankings["J"] = 9;
	rankings["Q"] = 10;
	rankings["K"] = 11;
	rankings["A"] = 12;

	return rankings[value] > rankings[other.value];

}

bool PlayingCard::operator==(const PlayingCard & other) {

	// define this list that will hold each possible
	// value, and it's index will serve as the rank

	map<string, int> rankings;
	for (int i = 0; i < 9; i++) {
		rankings[ to_string(i + 2) ] = i;
	}
	rankings["J"] = 9;
	rankings["Q"] = 10;
	rankings["K"] = 11;
	rankings["A"] = 12;

	return rankings[value] == rankings[other.value];

}

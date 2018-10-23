#include "PlayingCard.h"

PlayingCard::PlayingCard() {
	value = "[NO VALUE]";
	suit = "[NO SUIT]";
}

PlayingCard::PlayingCard(char pc_value, char pc_suit) {

	value = pc_value;
	suit = pc_suit;

}

ostream & operator<<(ostream & out, const PlayingCard & pc) {

	out << pc.value << pc.suit;
	return out;

}

bool PlayingCard::operator<(const PlayingCard & other) {

	// let's start by defining a map that will
	// hold the ranks of each card value
	// check if this isn't allowed 
	// (we haven't covered maps yet!)


}

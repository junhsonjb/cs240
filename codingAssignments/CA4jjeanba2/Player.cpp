#include "Player.h"

Player::Player() {

	// should I even do this?
	name = "[NO NAME ASSIGNED]";

}

Player::Player(string pName) {

	name = pName;

}

bool Player::addCard(PlayingCard card) {

	// not sure if I should ever return false or just not return (void function)
	hand.insert(card);
	return true;

}

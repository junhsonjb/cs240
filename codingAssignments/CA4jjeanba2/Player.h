#include "PlayingCard.h"
#include "LLC.h"

class Player {

	public:

		/* Data Members */
		string name; // player's name, just first name should be ok
		LLC<PlayingCard> hand; // the players hand of cards	
		int warScore = 0; // number of wars won (per game)
		int battleScore = 0; // number of battles won (per game)
		int gameScore = 0; // number of games won

		/* Member functions */
		Player(); // default contstructor
		Player(string pName); // value constructor takes name
		bool addCard(PlayingCard card); // add a card to player's hand

};

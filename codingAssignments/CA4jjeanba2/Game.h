#include "Player.h"

class Game {

	public:

		/* Data Members */
		Player player1, player2; // our 2 players for this game
		LLC<PlayingCard> cardDeck; // the main deck of cards

		/* Member functions */
		Game(); // default constructor, populate the entire deck of cards
		Player play(); // play an entire game of war between the 2 players
		void battle(); // one REGULAR round (unequal cards b/t players)
		void war(); // both players put same card value (10 cards used -- maybe use battle() in this function!)
		void shuffleDeck(); // shuffle the deck
		void dealCards(); // deal all the cards!

};

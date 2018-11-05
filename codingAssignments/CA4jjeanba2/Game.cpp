#include "Game.h"

Game::Game() {

	// populate the deck of cards with 52 playing cards here
	vector<string> vals = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	vector<string> suits = {"H", "D", "S", "C"};

	// add a card with every val/suit combo (52 total)
	for (string x : suits) {

		for (string y : vals) {

			PlayingCard pc(y, x);
			cardDeck.insert(pc);

		}

	}

	// now we can shuffle the deck a few times for good housekeeping
	shuffleDeck();
	shuffleDeck();
	shuffleDeck();
	shuffleDeck();

}

void Game::addPlayers(Player p1, Player p2) {

	player1 = p1;
	player2 = p2;

}

void Game::shuffleDeck() {

	// literally all we have to do is
	// call the shuffle method on cardDeck
	// because cardDeck is of type LLC<PlayingCard>
	// which has a shuffle() function already
	cardDeck.shuffle();

}

void Game::dealCards() {

	// disperse all of the PlayingCards between the players
	PlayingCard temp;
	// cout << "Card Deck Length: " << cardDeck.len() << endl;

	int count = 0;
	while (cardDeck.len() != 0) {

		temp = cardDeck.back();

		if (count % 2 == 0) {

			player1.addCard(temp);

		} else {

			player2.addCard(temp);

		}

		cardDeck.removeBack();
		count += 1;

	}


}

Player Game::play() {

	if (player1.hand.len() + player2.hand.len() != 52) {
		cout << "Card Number error" << endl;
		exit(1);
	}	

	// reset battleScore and warScore for p1 and p2
	// gotta put those variables into the Player Class

	// while neither player has won (gained all 52 cards)
	while (player1.hand.len() != 52 && player2.hand.len() != 52) {

		// make sure there's still 52 cards total
		cout << "current total cards: " << player1.hand.len() + player2.hand.len() << endl;

		// make sure we're not moving "cards" from any empty decks
		if (player1.hand.len() != 0 && player2.hand.len() != 0) {

			// compare cards ONLY TO SEE IF EQUAL OR NOT
			if (player1.hand.back() == player2.hand.back()) {
				cout << "calling war()" << endl;
				war(); // call war() if they are equal
			} else {
				cout << "actually calling battle()" << endl;
				battle(); // call battle if they're not equal
			}

		}

		cout << "Player1 has " << player1.hand.len() << " cards" << endl;
		cout << "Player2 has " << player2.hand.len() << " cards" << endl;
		cout << "Card Deck has " << cardDeck.len() << " cards" << endl;
		cout << endl;

	}

	// after the loop is over, one player has won
	// find that player and update their gameScore
	// then return them

	cout << "AYYYYYYYYYYYYYY" << endl;

	if (player1.hand.len() == 52) {
		player1.gameScore += 1;
		return player1;
	}

	player2.gameScore += 1;
	return player2;

}

void Game::battle() {

	PlayingCard temp1, temp2;
	temp1 = player1.hand.removeBack();
	temp2 = player2.hand.removeBack();

	cardDeck.insert(temp1);
	cardDeck.insert(temp2);

	// player1 wins the battle
	if (temp1 > temp2) {
		while (cardDeck.len() != 0) {
			player1.addCard( cardDeck.removeBack() );
		}
		player1.battleScore += 1;
	}

	// player2 wins the battle
	if (temp1 < temp2) {
		while (cardDeck.len() != 0) {
			player2.addCard( cardDeck.removeBack() );
		}
		player2.battleScore += 1;
	}

}

void Game::war() {

	cout << "WILL YOU SEGFAULT?" << endl;

	// before anything, make sure players have enough cards
	if (player1.hand.len() < 5) {
		// empty all cards into player2's hand
		while (player1.hand.len() != 0) {
			player2.addCard( player1.hand.removeBack() );
		}
		exit(0);
	}

	cout << "I WILL NOT SEGFAULT!" << endl;

	if (player2.hand.len() < 5) {
		// empty all cards into player1's hand
		while (player2.hand.len() != 0) {
			player1.addCard( player2.hand.removeBack() );
		}
		exit(0);
	}

	// move one card each from p1 and p2 (these are equal) to cardDeck
	cardDeck.insert( player1.hand.removeBack() );
	cardDeck.insert( player2.hand.removeBack() );

	// move three more cards from p1 and p2 to cardDeck
	for (int i = 0; i < 3; i++) {
		cardDeck.insert( player1.hand.removeBack() );
		cardDeck.insert( player2.hand.removeBack() );
	}

	// get the final cards (comparison cards) from each player
	PlayingCard temp1, temp2;
	temp1 = player1.hand.removeBack();
	temp2 = player2.hand.removeBack();

	if (temp1 == temp2) {
		/* come up with a way to handle this */
		/* this way should end with this if clause */

		// at least for now, just make player1 win in this case
		while (cardDeck.len() != 0) {
			player1.addCard( cardDeck.removeBack() );
		}

	}

	else if (temp1 > temp2) {

		player1.warScore += 1;

		/* move all cards from cardDeck back into p1'a hand */
		while (cardDeck.len() != 0) {
			player1.addCard( cardDeck.removeBack() );
		}

	} else {
		
		player2.warScore += 1;

		while (cardDeck.len() != 0) {
			player2.addCard( cardDeck.removeBack() );
		}

	}

}














// bottom whitespace
// delete when done

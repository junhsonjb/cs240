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
	for (int i = 0; i < cardDeck.len(); i++) {

		// store the card
		temp = cardDeck.tail();

		// if i is even give temp to p1 otherwise give it to p2
		// this way each player has half the deck
		if (i % 2 == 0) {
			
			player1.addCard(temp); // add the card to player1's hand
			cardDeck.remove(temp); // remove the card from cardDeck

		} else {

			player2.addCard(temp); // add the card to player2's hand
			cardDeck.remove(temp); // remove the card from cardDeck

		}


	}

}

Player Game::play() {

	PlayingCard temp1, temp2;

	// do this while neither player has won (has all 52 cards)
	while (player1.hand.len() != 52 && player2.hand.len() != 52) {

		temp1 = player1.hand.tail();
		player1.hand.remove(temp1);

		temp2 = player2.hand.tail();
		player2.hand.remove(temp2);

		cardDeck.insert(temp1);
		cardDeck.insert(temp2);

		if (temp1 != temp2)
			battle(); // changes # of cards in deck and player hands
		else
			war(); // changes # of cards in deck and player hands

	}

	// Once we've left this loop,
	// then one of the Players has all of the cards.
	// This player is the winner, return them

	if (player1.hand.len() == 52)
		return player1;

	return player2;

}

void Game::battle() {

	PlayingCard p2, p1;

	p2 = cardDeck.tail();
	cardDeck.remove(p2);

	p1 = cardDeck.tail();
	cardDeck.remove(p1);

	// if p2 wins this round
	if (p2 > p1) {
		// move all cards into player2's hand
		player2.hand.insert(p1);
		player2.hand.insert(p2);
	} else {
		// move all cards into player1's hand
		player1.hand.insert(p1);
		player1.hand.insert(p2);
	}

	/*
	   war() will take care of the case when p2 == p1
	   and the play() function will make sure that 
	   if p2 does equal p1, then this function won't
	   be called, war() will be called
	*/

}

void Game::war() {

	PlayingCard p1, p2, temp1, temp2;

	for (int i = 0; i < 3; i++) {
		p1 = player1.hand.tail();
		cardDeck.insert(p1);
		player1.hand.remove(p1);
	}

	temp1 = player1.hand.tail();
	cardDeck.insert(temp1);
	player1.hand.remove(temp1);

	for (int i = 0; i < 3; i++) {
		p2 = player1.hand.tail();
		cardDeck.insert(p2);
		player2.hand.remove(p2);
	}

	temp2 = player2.hand.tail();
	cardDeck.insert(temp2);
	player2.hand.remove(temp2);


	// Now to compare the temp cards and pick a round winner

	if (temp1 > temp2) {

		// player1 gets all the cards in the deck
		while (cardDeck.len() != 0) {
			p1 = cardDeck.tail();
			player1.hand.insert(p1);
			cardDeck.remove(p1);
		}
		
	} else if (temp2 > temp1) {

		// player2 gets all the cards in the deck
		while (cardDeck.len() != 0) {
			p2 = cardDeck.tail();
			player2.hand.insert(p2);
			cardDeck.remove(p2);
		}

	}

}














// bottom whitespace
// delete when done

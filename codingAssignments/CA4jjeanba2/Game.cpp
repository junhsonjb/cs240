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
	cout << "Card Deck Length: " << cardDeck.len() << endl;

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

	PlayingCard temp1, temp2;
	int battleCount = 0;
	int warCount = 0;
	Player roundWinner;

	// do this while neither player has won (has all 52 cards)
	while (player1.hand.len() != 52 && player2.hand.len() != 52) {

		// if someone wins during the game, take care of it
		if (player1.hand.len() == 52) {
			return player1;
		}

		if (player2.hand.len() == 52) {
			return player2;
		}
	
		temp1 = player1.hand.back();
		player1.hand.removeBack();

		temp2 = player2.hand.back();
		player2.hand.removeBack();

		cardDeck.insert(temp1);
		cardDeck.insert(temp2);

		if (temp1 != temp2) {
			battle(); // changes # of cards in deck and player hands
		}
		else {
			war(); // changes # of cards in deck and player hands
		}

	}

	// Once we've left this loop,
	// then one of the Players has all of the cards.
	// This player is the winner, return them

	if (player1.hand.len() == 52) {
		return player1;
	}
	return player2;

}

void Game::battle() {

	PlayingCard p2, p1;

	p2 = cardDeck.back();
	cardDeck.removeBack();

	p1 = cardDeck.back();
	cardDeck.removeBack();

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

	// check if any player has less than 4 cards,
	// if one of them does, then the other one wins

	if (player1.hand.len() < 4) {
		//player1 loses, player2 wins
		player2.hand = player2.hand + player1.hand;

		while (player1.hand.len() != 0) {
			player1.hand.removeBack();
		}

		return;

	}

	if (player2.hand.len() < 4) {
		//player2 loses, player1 wins
		player1.hand = player1.hand + player2.hand;

		while (player2.hand.len() != 0) {
			player2.hand.removeBack();
		}

		return;

	}

	PlayingCard p1, p2, temp1, temp2;

	for (int i = 0; i < 3; i++) {
		p1 = player1.hand.back();
		cardDeck.insert(p1);
		player1.hand.removeBack();
	}


	temp1 = player1.hand.back();
	cardDeck.insert(temp1);
	player1.hand.removeBack();

	for (int i = 0; i < 3; i++) {
		p2 = player2.hand.back();
		cardDeck.insert(p2);
		player2.hand.removeBack();
	}

	temp2 = player2.hand.back();
	cardDeck.insert(temp2);
	player2.hand.removeBack();

	// Now to compare the temp cards and pick a round winner

	if (temp1 > temp2) {

		// player1 gets all the cards in the deck
		while (cardDeck.len() != 0) {
			p1 = cardDeck.back();
			player1.hand.insert(p1);
			cardDeck.removeBack();
		}
		
	} else if (temp2 > temp1) {

		// player2 gets all the cards in the deck
		while (cardDeck.len() != 0) {
			p2 = cardDeck.back();
			player2.hand.insert(p2);
			cardDeck.removeBack();
		}

	}

}














// bottom whitespace
// delete when done

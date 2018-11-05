#include "Game.h"

Player recursiveMatch(vector<Player> opps) {

	if (opps.size() == 2) {
		Game game;
		game.shuffleDeck();
		game.addPlayers(opps[0], opps[1]);
		game.dealCards();
		Player winner = game.play();
		return winner;
	}

	vector<Player> others;
	for (int i = 0; i < opps.size() / 2; i++) {

		others.push_back(opps[opps.size() - 1]);
		opps.pop_back();

	}

	Player w1, w2;
	w1 = recursiveMatch(opps);
	w2 = recursiveMatch(others);

	Game game;
	game.shuffleDeck();
	game.addPlayers(w1, w2);
	game.dealCards();
	Player winner = game.play();
	return winner;

}

int main() {

	vector<Player> allPlayers;
	Player p1("June");
	Player p2("April");
	Player p3("May");
	Player p4("July");

	allPlayers.push_back(p1);
	allPlayers.push_back(p2);
	allPlayers.push_back(p3);
	allPlayers.push_back(p4);

	Player winner = recursiveMatch(allPlayers);

}

#include <iostream>
#include "Game.h"
//#include "LLC.h"

using namespace std;

int main() {

	vector<Player> players;

}

Player tournament(vector<Player> opps) {

	if (opps.size() == 2) {
		Game game;
		game.addPlayer(opps[0].name);
		game.addPlayer(opps[1].name);
		game.shuffleDeck;
		game.dealCards;
		return game.play();
	}

	vector<Player> others;
	for (int i = 0; i < opps.size() / 2; i++) {
	
		others.push_back(opps.end() - 1);
		opps.pop_back();

	}

	tournament(opps);
	tournament(others);

}

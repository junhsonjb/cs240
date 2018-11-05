#include <iostream>
#include "Game.h"
//#include "LLC.h"

using namespace std;

int main() {

	Player p1("Junhson"), p2("Lindell");
	Game game;
	game.addPlayers(p1, p2);
	game.dealCards();

	cout << "it's not an infinite loop..." << endl;

	// time to play the game
	Player winner = game.play();
	cout<< "And the winner is ... " << winner.name << endl;

}

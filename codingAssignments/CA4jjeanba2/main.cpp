#include <iostream>
#include "Game.h"
//#include "LLC.h"

using namespace std;

int main() {

/* PLAYING CARD TESTS */

	// PlayingCard x("10", "D");
	// PlayingCard y("A", "S");
	// PlayingCard a("9", "H");
	// PlayingCard b("9", "H");

	// if (x < y) cout << "YAAHH" << endl;
	// if (!(y < x)) cout << "WHOOO" << endl;

	// if (y > x) cout << "UH HUHHHHHH" << endl;
	// if (!(x > y)) cout << "YUHHHHHH" << endl;

	// if (a == a) cout << "AYYYYY" << endl;
	// if (a == b) cout << "OOOOOOOOOOOHHH" << endl;
	// if (!(a == y)) cout << "AAHHHHHHHHH" << endl;

	// cout << x << endl << y << endl << a << endl << b << endl;

/* LLC<TYPE> TESTS */

	// Create Linked Lists to test on

	// LLC<int> numbers;
	// LLC<string> texts;
	// LLC<PlayingCard> cards;

	// // Populate each Linked List

	// for (int i = 0; i <= 10; i++)
	// 	numbers.insert(i);

	// texts.insert("Daryll");
	// texts.insert("Pam");
	// texts.insert("Michael");

	// PlayingCard card1("Q", "H");
	// PlayingCard card2("3", "D");
	// PlayingCard card3("6", "S");

	// cards.insert(card1);
	// cards.insert(card2);
	// cards.insert(card3);

	// // checking if other LLC funcs are undefined (tail() is DEFINED)
	// texts.contains("Michael");
	// texts.contains("bruhhhh");
	// texts.shuffle();
	// texts.head(1);

	// cout << endl << endl << "We got past those ones!" << endl << endl;

	// // numbers.tail();
	// // texts.tail();
	// // cards.tail();

	// cout << cards << endl;
	// cout << texts << endl;
	// cout << numbers << endl;

	// cout << "Hello There!" << endl;

	// return 0;

/* Game Tests */

	Game game;
	Player winner;
	game.shuffleDeck();
	game.dealCards();
	winner = game.play();

}

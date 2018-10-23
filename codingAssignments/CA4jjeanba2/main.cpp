#include "PlayingCard.h"

int main() {

	PlayingCard x("10", "D");
	PlayingCard y("A", "S");
	PlayingCard a("9", "H");
	PlayingCard b("9", "H");

	if (x < y) cout << "YAAHH" << endl;
	if (!(y < x)) cout << "WHOOO" << endl;

	if (y > x) cout << "UH HUHHHHHH" << endl;
	if (!(x > y)) cout << "YUHHHHHH" << endl;

	if (a == a) cout << "AYYYYY" << endl;
	if (a == b) cout << "OOOOOOOOOOOHHH" << endl;
	if (!(a == y)) cout << "AAHHHHHHHHH" << endl;

	cout << x << endl << y << endl << a << endl << b << endl;

	return 0;

}

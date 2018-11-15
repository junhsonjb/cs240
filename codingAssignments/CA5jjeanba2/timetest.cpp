#include "Time.h"

int main() {

	string am = "am", pm = "pm";
	Time aTime(10, 10, am);
	Time bTime(10, 10, am);

	Time cTime(1, 2, pm);
	Time dTime(1, 2, am);

	Time eTime(4, 4, am);
	Time fTime(12, 1, pm);

	cout << "Time objects created" << endl;

	if (aTime == bTime) {
		cout << "aTime equals bTime" << endl;
	}

	if (cTime > dTime) {
		cout << "cTime is greater than dTime" << endl;
	}

	if (dTime < cTime) {
		cout << "dTime is less than cTime" << endl;
	}

	if (eTime != fTime) {
		cout << "eTime is not equal to fTime" << endl;
	}

	cout << "Made it to the end of current testing!" << endl;

}

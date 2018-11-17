#include "Time.h"

int main() {

	// with integer constructor

	string am = "am", pm = "pm";
	Time aTime(10, 10, am);
	Time bTime(10, 10, am);

	Time cTime(1, 2, pm);
	Time dTime(1, 2, am);

	Time eTime(4, 4, am);
	Time fTime(12, 1, pm);

	// with string constructor

	Time gTime("10:10am");
	Time hTime("10:10am");

	Time iTime("01:02pm");
	Time jTime("01:02am");

	Time kTime("04:04am");
	Time lTime("12:01pm");

	cout << "Time objects created" << endl;

	cout << "Testing integer constructed Time objs" << endl;

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

	cout << "Testing string constructed Time objs" << endl;

	if (gTime == hTime) {
		cout << "aTime equals bTime" << endl;
	}

	if (iTime > jTime) {
		cout << "cTime is greater than dTime" << endl;
	}

	if (jTime < iTime) {
		cout << "dTime is less than cTime" << endl;
	}

	if (kTime != lTime) {
		cout << "eTime is not equal to fTime" << endl;
	}

	cout << "Made it to the end of current testing!" << endl;

}

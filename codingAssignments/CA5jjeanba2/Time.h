#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Time {

	public:

		int hours;
		int minutes;
		string meridiem; // must equal "am" or "pm"

		Time(string time);
		Time(int hrs, int mins, string mer);
		bool operator>(Time other);
		bool operator<(Time other);
		bool operator==(Time other);
		bool operator!=(Time other);

};

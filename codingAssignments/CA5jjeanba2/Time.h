#ifndef H_Time_H
#define H_Time_H

//#include "Edge.h"
//#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Time {

	public:

		int hours;
		int minutes;
		string meridiem; // must equal "am" or "pm" to be valid

		Time();
		Time(string time);
		Time(int hrs, int mins, string mer);
		bool operator>(Time other);
		bool operator<(Time other);
		bool operator==(Time other);
		bool operator!=(Time other);

		friend ostream & operator<<(ostream & out, const Time & time);

};

#endif

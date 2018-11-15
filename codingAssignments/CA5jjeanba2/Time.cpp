#include "Time.h"

// constructor taking string of form: HH:MMam or HH:MMpm
Time::Time(string time) {

	/* parse string of the form:
		HH:MMam or HH:MMpm */

	string hrs, mins;
	hrs = time.substr(0, 2);
	mins = time.substr(3, 2);

	hours = stoi(hrs);
	minutes = stoi(mins);
	meridiem = time.substr(5, 2);

}

// constructor taking values for each field
Time::Time(int hrs, int mins, string mer) {

	hours = hrs;
	minutes = mins;
	meridiem = mer;

}

bool Time::operator>(Time other) {

	// if they're equal return false
	if (hours == other.hours && minutes == other.minutes && meridiem == other.meridiem) {
		return false;
	}

	// if one is am and the other is pm, then return the one that is pm
	if (meridiem != other.meridiem) {
		if (meridiem == "pm") {
			return true;
		}

		return false;
	}

	/* From here on out, IF BOTH HAVE SAME MERIDIEM is IMPLIED!!! */

	if (hours != other.hours) {

		return hours > other.hours;

	}

	/* From here on out IF BOTH HAVE SAME HOURS is ALSO IMPLIED!!! */
	/* Minutes will not be the same because if they were, both the
       times would be equal, which we already handled */

	return minutes > other.minutes;

}

bool Time::operator<(Time other) {

	// if they're equal return false
	if (hours == other.hours && minutes == other.minutes && meridiem == other.meridiem) {
		return false;
	}

	/* since we already handles the times being equal,
	   we can just treat it as the opposite of the the
	   operator> function */

	return !(operator>(other));

}

bool Time::operator==(Time other) {

	// if they're equal return true
	if (hours == other.hours && minutes == other.minutes && meridiem == other.meridiem) {
		return true;
	}

}

bool Time::operator!=(Time other) {

	// we can just treat this as the opposite of operator==
	return !(operator==(other));

}

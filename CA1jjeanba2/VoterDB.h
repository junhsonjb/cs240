#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void new_info(string &last, string &first, int &age, int &street_num,
		string &street_name, string &town, string &zip_code, float &amount_donated);

void update_info(string &last, string &first, int &age, int &street_num,
				string &street_name, string &town, string &zip_code);

void view_info(string last, string first, int age, int street_num, string street_name,
				string town, string zip_code, float amount_donated);

void donate(float &amount_donated);

void report_info(string last, float amount_donated);

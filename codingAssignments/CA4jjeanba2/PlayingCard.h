#include "LLC.h"

class PlayingCard {

	public: //private: // should these be public? Ask!
		string value;
		string suit;

	public:
		PlayingCard();
		PlayingCard(string pc_value, string pc_suit);
		friend ostream & operator<<(ostream & out, const PlayingCard & pc);
		bool operator<(const PlayingCard & other);
		bool operator>(const PlayingCard & other);
		bool operator==(const PlayingCard & other);


};

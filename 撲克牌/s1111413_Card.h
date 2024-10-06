
#include <string>
#ifndef CARD
#define CARD


using namespace std;
class Card
{
public:
	Card(int,int);//Face suit
string toString();
int getSuit();
int getFace();
Card& operator=(const Card& );
friend ostream& operator<<(ostream&, const Card&);
private:
	
	const string faceNames[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
						"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	const string suitNames[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	int face = 0;
	int suit = 0;
};
#endif 
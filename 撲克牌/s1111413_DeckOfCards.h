#include <string>
#include"s1111413_List.h"
using namespace std;
#ifndef DECK
#define DECK
class DeckOfCards :private LinkedList<Card>
{
public:

	DeckOfCards();
	void reset();
	void shuffle();
	Card dealCard();
	bool moreCards();
	Card removecard();
	void clear();
private:
	int currentCard = 0;
	LinkedList<Card> mydc;
	


};
#endif 
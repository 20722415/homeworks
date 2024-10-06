#include"s1111413_DeckOfCards.h"
#ifndef  Hand_H
#define Hand_H
class Hand
{
	friend DeckOfCards;
public:
	Hand(DeckOfCards& deck);
	void print();
	friend ostream& operator<<(ostream&, Hand&);
	void takeAgain(DeckOfCards& deck);
	bool pair();
	bool twoPair();
	bool threeOfAKind();
	bool fourOfAKind();
		bool flush();
		bool fullHouse();
		bool straight();
		string type();
	LinkedList<Card> mycard;

	
	
};
#endif   
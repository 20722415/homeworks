#include <iostream>
#include"s1111413_Poker.h"
#include<iomanip>


bool PressEnterToContinue(string mesg = "Press ENTER to continue... ")
{
	int c;
	cout << mesg << endl;
	cout.flush();
	do c = getchar(); while ((c != '\n') && (c != EOF));
	return true;
}
int main() {
	DeckOfCards myDeckOfCards;
	cout << "¬~µP«e" << endl;
	for (int i = 1; myDeckOfCards.moreCards(); i++)
	{

		cout << left << setw(19) << myDeckOfCards.dealCard().toString();

		if (i % 5 == 0)
			cout << endl;
	}

	cout << endl << "--------------------------------------" << endl;
	myDeckOfCards.reset();
	//dealCard()¡Breset()¡BmoreCards() toString() test
	myDeckOfCards.shuffle();
	cout << "¬~µP«á" << endl;
	for (int i = 1; myDeckOfCards.moreCards(); i++)
	{

		cout << left << setw(19) << myDeckOfCards.dealCard().toString();

		if (i % 5 == 0)
			cout << endl;
	}

	cout << endl << "--------------------------------------" << endl;
	myDeckOfCards.reset();
	Hand a(myDeckOfCards);
	cout << "hand print and operator<<" << endl;
	cout << a << endl;
   a.print();
	cout << "­«·s©âµP" << endl;
	a.takeAgain(myDeckOfCards);
	a.print();
	DeckOfCards s;
	s.shuffle();
	Hand hand(s);
	
	
	cout << "©âµP §PÂ_ ¦A©âµP" << endl;

		try
		{
			do {

				hand.print(); // display hand
				// check for each type of hand
				if (hand.fourOfAKind())
					cout << "Hand contains four of a kind" << endl;
				if (hand.flush())
					cout << "Hand contains a flush" << endl;
				if (hand.straight())
					cout << "Hand contains a straight" << endl;
				if (hand.threeOfAKind())
					cout << "Hand contains three of a kind" << endl;
				if (hand.twoPair())
					cout << "Hand contains two pairs" << endl;
				if (hand.pair())
					cout << "Hand contains a pair" << endl;
				if (hand.fullHouse())
					cout << "Hand contains a fullHouse" << endl;

				// check for each type of hand
				if (hand.type() == "none")
					cout << "Too bad, you get nothing..." << endl;
				else
					cout << "You get " << hand.type() << " !!!" << endl;

				hand.takeAgain(myDeckOfCards);

			} while (PressEnterToContinue() && myDeckOfCards.moreCards());
		}
		catch (const Exception& e)
		{
			cout << "No more cards in the deck." << endl;
		
			
			
		}
		
		PressEnterToContinue("Press ENTER to endgame... ");

	}


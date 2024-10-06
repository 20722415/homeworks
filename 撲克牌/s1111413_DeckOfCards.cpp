#include <string>
#include"s1111413_DeckOfCards.h"
#include"s1111413_Exception.h"
#include <cstdlib> 
#include <ctime>   
#include<iostream>
#include<iomanip>
using namespace std;


DeckOfCards::DeckOfCards()
{
	mydc.clear();

	for (int j = 0; j < 13; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			Card card(j, i);
			mydc.insertAtBack(card);
		}
	}
	currentCard = 0;
}

void DeckOfCards::reset()
{
	currentCard = 0;
	
}
void DeckOfCards::clear()
{
	mydc.clear();
}
void  DeckOfCards::shuffle()
{
	srand(static_cast<unsigned int>(time(0)));
	for (int i = mydc.getSize() - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		mydc.changedata(i, j);
	}
	
	

}
Card  DeckOfCards::dealCard()
{
	Card a = mydc.getdata(currentCard);
	currentCard++;
	return a;
}
bool DeckOfCards::moreCards()
{

	if (currentCard == 52||mydc.isEmpty())
	{
		return 0;
	}


	return 1;
}

Card DeckOfCards::removecard()
{


		Card a = mydc.getdata(0);
	
		mydc.removeFromFront();
	
		currentCard++;
	return a;
}

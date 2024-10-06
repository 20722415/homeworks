#include <string>
#include"s1111413_Card.h"
#include<iostream>


using namespace std;
Card::Card(int Face, int Suit)
{
	face = Face;
	suit = Suit;
}
string Card::toString()
{
	return faceNames[face] + " of " + suitNames[suit];
}
ostream& operator<<(ostream&o, const Card&a)
{
	o << a.faceNames[a.face] << " of " << a.suitNames[a.suit] << endl;
	return o;
}
int Card::getSuit()
{
	return suit;
}
int  Card::getFace()
{
	return face;
}
Card& Card::operator=(const Card& other)
{
	suit = other.suit;
	face = other.face;
    return *this;
}

#include"s1111413_Hand.h"
#include"s1111413_Exception.h"

Hand::Hand(DeckOfCards& deck)
{
	
	for (int i = 0; i < 5; i++)
	{
		Card a = deck.removecard();

		mycard.insertAtBack(a);
		
	}

	cout << mycard.getfront();
}
void Hand::print()
{
	for (int i = 0; i < mycard.getSize(); i++)
	{

		cout << mycard.getdata(i).toString() << endl;
	}
	cout << endl;
}
void Hand::takeAgain(DeckOfCards& deck)
{
	
	
		mycard.clear();
	
	for (int i = 0; i < 5; i++)
	{
		if (!deck.moreCards())
		{
			mycard.clear();
			throw Exception("µP°ï³Q©â§¹");
			break;
		}
			
		Card a = deck.removecard();
		mycard.insertAtBack(a);
	}
}
bool Hand::pair()
{
	int count[13] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		Card a = mycard.getdata(i);	
		count[a.getFace()]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (count[i] == 2)
			return 1;
	}
	return 0;
}

bool Hand::twoPair()
{
	int count[13] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		Card a = mycard.getdata(i);
		count[a.getFace()]++;
	}
	int countp=0;
	for (int i = 0; i < 13; i++)
	{
		if (count[i] == 2 )
		{
			countp++;
		}
	}
	if (countp == 2)
		return 1;

	return 0;
}
bool Hand::threeOfAKind()
{
	int count[13] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		Card a = mycard.getdata(i);
		count[a.getFace()]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (count[i] == 3)
			return 1;
	}
	return 0;
}
bool Hand::fourOfAKind()
{
	int count[13] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		Card a = mycard.getdata(i);
		count[a.getFace()]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (count[i] == 4)
			return 1;
	}
	return 0;
}
bool Hand::flush()
{
	int suitcount[4] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		Card a = mycard.getdata(i);
		suitcount[a.getSuit()]++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (suitcount[i] == 5)
			return 1;
	}
	return 0;
}
ostream& operator<<(ostream& o, Hand& d)
{
	for (int i = 0; i < 5; i++)
	{
		
		o << d.mycard.getdata(i).toString() << endl;
	}
	o << endl;
	return o;
	
	
 }
bool Hand::fullHouse()
{
	int count[13] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		Card a = mycard.getdata(i);
		count[a.getFace()]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (count[i] == 3)
		{
			for (int j = 0; j < 13; j++)
			{
				if(count[j] == 2)
					return 1;
			}
		}
	}
	return 0;
}
bool Hand::straight()
{
	int count[13] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		Card a = mycard.getdata(i);
		count[a.getFace()]++;
	}
	for (int i = 0; i < 9; i++)
	{
		if (count[i] == 1)
		{
			if (count[i + 1] == 1 && count[i + 2] == 1 && count[i + 3] == 1 && count[i + 4] == 1)
				return 1;
		}
	}
	return 0;
}
string Hand::type()
{
	if (straight() && flush())
	{
		return "straight flush";
	}
	if (flush())
	{
		return " flush";
	}
	if (straight())
	{
		return" straight flush";
	}
	if (fourOfAKind())
	{
		return "four of a kind";
	}
	if (pair()&&threeOfAKind())
	{
		return "Full house";
	}
	if (twoPair())
	{
		return "two pairs";
	}
	if (threeOfAKind())
	{
		return "three of a kind";
	}
	if (pair())
	{
		return "one pair";
	}
	return "none";
}

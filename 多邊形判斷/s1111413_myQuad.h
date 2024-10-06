#include<iostream>
#include"s1111413_myPoint2.h"
using namespace std;

class myQuadrilateral
{
public:
	myQuadrilateral(){};
	myQuadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	friend ostream& operator<<(ostream &s, myQuadrilateral A);
	virtual string getType();
	virtual double getArea();
	virtual bool isValid();
	void print();
	 Point2 a, b, c, d;
};

class myParallelogram :public myQuadrilateral
{
public:
	 myParallelogram() {};
	 myParallelogram(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	 virtual string getType();
	virtual double getArea();
	virtual bool isValid();
	

};
class myRectangle :public myParallelogram
{
public:
	myRectangle() {};
	myRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	 string getType();
	virtual double getArea();
	virtual bool isValid();


};
class mySquare:public myRectangle
{
public:
	mySquare() {};
	mySquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	virtual string getType();
	virtual double getArea();
	virtual bool isValid();


};
class myTrapezium :public myQuadrilateral
{
public:
	myTrapezium() {};
	myTrapezium(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	virtual string getType();
	virtual double getArea();
	virtual bool isValid();
};

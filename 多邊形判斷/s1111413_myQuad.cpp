#ifndef _myQuad
#define _myQuad


#include<iostream>
#include"s1111413_myQuad.h"
using namespace std;
myQuadrilateral::myQuadrilateral(int x1, int y1 , int x2, int y2 , int x3, int y3, int x4, int y4)
{
	a(x1, y1);
	b(x2, y2);
	c(x3, y3);
	d(x4, y4);
}
string myQuadrilateral::getType()
{
	return "Quadrilateral";
}
void myQuadrilateral::print()
{
	cout << "( " << a.getX() << ", " << a.getY() << " ) ";
	cout << "( " << b.getX() << ", " << b.getY() << " ) ";
	cout << "( " << c.getX() << ", " << c.getY() << " ) ";
	cout << "( " << d.getX() << ", " << d.getY() << " ) ";
	cout << endl;
}
ostream& operator<<(ostream &s, myQuadrilateral A)
{
	
	s << "( " << A.a.getX() << ", " << A.a.getY() << " ) ";
	s << "( " << A.b.getX() << ", " << A.b.getY() << " ) ";
	s << "( " << A.c.getX() << ", " << A.c.getY() << " ) ";
	s << "( " << A.d.getX() << ", " << A.d.getY() << " ) ";
s << endl;
	return s;
}
double myQuadrilateral::getArea()
{
	int s1 = a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * d.getY() + d.getX() * a.getY();
	int s2= b.getX() *a.getY() + c.getX() * b.getY() + d.getX() * c.getY() + a.getX() * d.getY();
	double sum = s1 - s2;
	if (sum < 0)
		sum *= -1;
	return sum*0.5;
	
	
}
bool myQuadrilateral::isValid()
{
	if (a == b)
		return 0;
	if (a == c)
		return 0;
	if (a == d)
		return 0;
	if (b == c)
		return 0;
	if (c == d)
		return 0;
	if (b == d)
		return 0;
	
	Point2 vecotr1(a.getX() - b.getX(), a.getY() - b.getY());//a-b
	Point2 vecotr2(a.getX() - d.getX(), a.getY() - d.getY());//a-d
	if (vecotr1.getX() * vecotr2.getY() == vecotr2.getX() * vecotr1.getY())//三點共線
		return 0;

	Point2 vecotr3(a.getX() - b.getX(), a.getY() - b.getY());//a-b
	Point2 vecotr4(a.getX() - c.getX(), a.getY() - c.getY());//a-c
	if (vecotr3.getX() * vecotr4.getY() == vecotr4.getX() * vecotr3.getY())//三點共線
		return 0;
	Point2 vecotr5(a.getX() - c.getX(), a.getY() - c.getY());//a-c
	Point2 vecotr6(a.getX() - d.getX(), a.getY() - d.getY());//a-d
	if (vecotr5.getX() * vecotr6.getY() == vecotr6.getX() * vecotr5.getY())//三點共線
		return 0;
	return 1;

}
myParallelogram::myParallelogram(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	a(x1, y1);
	b(x2, y2);
	c(x3, y3);
	d(x4, y4);

}
string myParallelogram::getType()
{
	
	return myQuadrilateral::getType()+"-Parallelogram";
}
double myParallelogram::getArea()
{
	
	double end = a.getDistance(a, b);//底:a-b
	
	Point2 vector1(a.getX() - d.getX(), a.getY() - d.getY());//向量d-a
	Point2 vector2(c.getX() - d.getX(), c.getY() - d.getY());//向量d-c
	int dot = vector1.getX() * vector2.getX() + vector2.getY() * vector1.getY();
	float dis= pow(vector1.getX(), 2) + pow(vector1.getY(), 2);
	dis = dot / dis;
	Point2 Point( dis * vector2.getX()+d.getX(), dis * vector2.getY()+d.getY());
	double high = Point.getDistance(Point, a);
	return high * end;

}
bool myParallelogram::isValid()
{
	if (myQuadrilateral::isValid())
	{

		if (a.isParallel(a, b, c, d) && a.isParallel(a, d, b, c))//ab-cd平行 ad-bc平行
			return 1;
	}

	return 0;
}
myRectangle::myRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	a(x1, y1);
	b(x2, y2);
	c(x3, y3);
	d(x4, y4);
}
string myRectangle::getType()
{
	return myParallelogram::getType() + "-Rectangle";
}
bool  myRectangle::isValid()//垂直ab-ad ab-bc bc-cd  cd-ad
{
	Point2 vecotr1(a.getX() - b.getX(), a.getY() - b.getY());//a-b
	Point2 vecotr2(a.getX() - d.getX(), a.getY() - d.getY());//a-d
	Point2 vecotr3(b.getX() - c.getX(), b.getY() - c.getY());//b-c
	Point2 vecotr4(c.getX() - d.getX(),c.getY() - d.getY());//c-d
	 if (myParallelogram::isValid())
	 {
		
		 if (vecotr1.getX() * vecotr2.getX() + vecotr1.getY() * vecotr2.getY() == 0)
		 {
			
			 if (vecotr1.getX() * vecotr3.getX() + vecotr1.getY() * vecotr3.getY() == 0)
			 {
				
				 if (vecotr4.getX() * vecotr3.getX() + vecotr4.getY() * vecotr3.getY() == 0)
				 {
					 
					 
						 return 1;
					 
				 }
			 }
		 }
	 }
	 return 0;
}
double myRectangle::getArea()
{
	
	return a.getDistance(a, b) * a.getDistance(a, d);
}
 
mySquare::mySquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	a(x1, y1);
	b(x2, y2);
	c(x3, y3);
	d(x4, y4);

}
string mySquare::getType()
{
	return myParallelogram::getType() + "-Square";
 }

double  mySquare::getArea()
{
	return a.getDistance(a, b) * a.getDistance(a, d);
 }
bool mySquare::isValid()
{
	float lengtha = a.getDistance(a, b);
	float lengthb = a.getDistance(b, c);
	float lengthc = a.getDistance(c, d);
	float lengthd = a.getDistance(a, d);
	if (myRectangle::isValid())
	{
		if(lengtha== lengthb&& lengthb== lengthc&& lengthc== lengthd)
		{
			return 1;
		}
	}
	return 0;
}
myTrapezium::myTrapezium(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	a(x1, y1);
	b(x2, y2);
	c(x3, y3);
	d(x4, y4);
}
string myTrapezium::getType()
{
	return myQuadrilateral::getType() + "-Trapezium";
}
double myTrapezium::getArea()
{
	if (a.isParallel(a, b, c, d))//a-b c-d平行
	{
		float highend = a.getDistance(a, b);
		float lowend = a.getDistance(c, d);
		Point2 vector1(a.getX() - d.getX(), a.getY() - d.getY());//向量d-a
		Point2 vector2(c.getX() - d.getX(), c.getY() - d.getY());//向量d-c
		int dot = vector1.getX() * vector2.getX() + vector2.getY() * vector1.getY();
		float dis = pow(vector2.getX(), 2) + pow(vector2.getY(), 2);
		dis = dot / dis;
		Point2 Point(dis * vector2.getX() + d.getX(), dis * vector2.getY() + d.getY());
		double high = Point.getDistance(Point, a);
		return high * 0.5 * (highend + lowend);
	}
	float highend = a.getDistance(b, c);
	float lowend = a.getDistance(a, d);
	Point2 vector1(b.getX() - a.getX(), b.getY() - a.getY());//向量a-b
	Point2 vector2(d.getX() - a.getX(), d.getY() - a.getY());//向量a-d
	int dot = vector1.getX() * vector2.getX() + vector2.getY() * vector1.getY();
	float dis = pow(vector2.getX(), 2) + pow(vector2.getY(), 2);
	dis = dot / dis;
	Point2 Point(dis * vector2.getX() + a.getX(), dis * vector2.getY() + a.getY());
	double high = Point.getDistance(Point, b);
	return high*0.5*(highend+lowend);
 }
bool  myTrapezium::isValid()
{
	int count = 0;//計算平行邊有幾對
	if (a.isParallel(a, b, c, d))//a-b c-d
		count++;

	if (a.isParallel(a, d, c, b))//a-d c-b
		count++;

	if (count == 1)
		return 1;

	return 0;
 }
#endif


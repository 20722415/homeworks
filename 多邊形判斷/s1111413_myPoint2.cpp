#ifndef Point
#define Point

#include"s1111413_myPoint2.h"
#include<cmath>
Point2::Point2(int X,int Y)
{
	x = X;
	y = Y;
}
Point2::Point2()
{
	x = 0;
	y = 0;
}
Point2& Point2::operator()(int X,int Y)
{
	x = X;
	y = Y;
	return *this;
}
int Point2::getX()
{
	return x;
}
int Point2::getY()
{
	return y;
}
float  Point2 ::getDistance(const Point2& p1, const Point2& p2)
{
	
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	
}
bool Point2::operator==(const Point2 p1)
{
	if (x == p1.x && y == p1.y)
		return 1;

	return 0;
}
 bool Point2::isParallel(const Point2& A, const Point2& B, const Point2& C, const Point2& D)//平面向量   前兩項為一個向量 後兩項一個向量 判斷平行
{
	Point2 vector1(A.x-B.x, A.y- B.y);
	Point2 vector2(C.x - D.x,C.y - D.y);
	if (vector1.x * vector2.y == vector2.x * vector1.y)
		return 1;
	
	return 0;
}
#endif
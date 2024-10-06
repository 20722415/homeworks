#include<iostream>
using namespace std;
class Point2 
{
public:
	Point2();
	Point2(int , int );
	static float getDistance(const Point2&, const Point2&);
	static bool isParallel(const Point2& A, const Point2& B, const Point2& C, const Point2& D);
	int getX();
	int getY();
	bool operator==(const Point2);
Point2 	&operator()(int x, int y);
private:
	int x = 0;
	int y = 0;
}
;

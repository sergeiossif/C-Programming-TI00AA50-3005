#include <cmath>
#include <iostream>
using namespace std;


//Definition for exception class
class Exception {
public:
	Exception(const char *explanation0) { explanation = explanation0; }
	const char *what() const { return explanation; }
private:
	const char *explanation;
};


#define N 1000

//Class definition for Point
class Point {
	friend ostream& operator<<(ostream &out, const Point &point);
public:
	Point(float x0 = 0.0, float y0 = 0.0);
	~Point();
	float distance(const Point& p2) const;
	float distance();
	static int count;
	void print();



private:
	float x;
	float y;
	int id;
};



bool ComPoints(Point *p1, Point *p2);

//bool ComPoints(Point   &p1, Point  &p2);
/* Here is the Point class. It is almost similar same that in the program memleakharj.cpp.
    The difference is that it now has a member function distance, that calculates 
    distance between two points.
*/



//-----------------------------------------------------------------
//Implementation of class Point

#include "point_for_pointer_containers.h"
#include <memory>
Point:: Point(float x0, float y0): x(x0), y(y0) {
    id = count++;
    if (count >= N)
        throw Exception ("Does not succeed to create the last apex");
    cout << "Point constructor is done " << (void*)this << endl;
}

Point::~Point() {
    cout << "\nDestructor for Point " << (void*)this << " : ("
            << x << "," << y << ")" << endl;
}

float Point::distance(const Point& p2) const {
    float deltax = p2.x - x;
    float deltay = p2.y - y;   
    return sqrt(deltax*deltax + deltay*deltay);
}


// Friend functions of Point
ostream &operator<<(ostream & out, const Point &point) {
	out << "(" << point.x << "," << point.y << ")";
	return out;
}

void Point::print() {
	cout << "Point #" << id << " x: " << x << " y: " << y << " d(origin): " << Point::distance() << endl;
}


float Point::distance(){
	return sqrt(x*x + y*y);
}

bool ComPoints(Point *p1, Point *p2) {
	
	if (p1->distance() < p2->distance()) {
		//cout << "DEBUG POINT1" << p1->distance(origin);
		return 1;

	}
	else {
		//cout << "DEBUG POINT1" << p2->distance(origin);
		return 0;
	}


}

/*
bool ComPoints(const unique_ptr<Point> &p1, const unique_ptr<Point> &p2){

	if (p1.distance() < p2.distance()) {
		return 0;
	}




}*/
/*
bool ComPoints(const unique_ptr<Point> &p1, const unique_ptr<Point> &p2){
	if (p1->distance() < p2->distance()) {
		return 0;
	}

}*/


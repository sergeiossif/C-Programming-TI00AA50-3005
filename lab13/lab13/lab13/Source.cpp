#include "point_for_pointer_containers.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <functional>
#include <memory>


using namespace std;
int Point::count = 0;

/*
class SuperVisor {
public:
	SuperVisor(vector<Point*>  vec){
		visee = &vec;
	}

	~SuperVisor() {
		for_each(visee->begin(), visee->end(), [](Point * n) { delete n; });
	}
private:
	vector<Point*> * visee;

};*/



bool ComPoints2(const unique_ptr<Point> & p1, const unique_ptr<Point> & p2) {
	if (p1->distance() < p2->distance()) {
		//cout << "DEBUG POINT1" << p1->distance(origin);
		return 1;

	}
	else {
		//cout << "DEBUG POINT1" << p2->distance(origin);
		return 0;
	}
}



int main(){
	try{
		/*vector<Point*> points;
		//SuperVisor l = SuperVisor(points);
		srand(time(NULL));

		for (int i = 0; i < 3; i++){
			points.push_back(new Point(((float)rand()) * 10 / (float)RAND_MAX, ((float)rand()) * 10 / (float)RAND_MAX)); //make random points between 0 and 10
		}

		//throw Exception ("because i can");

		for_each(points.begin(), points.end(), [](Point * n) { n->print(); });
		sort(points.begin(), points.end(), ComPoints);
		cout << "---------------------------" << endl;
		for_each(points.begin(), points.end(), [](Point * n) { n->print(); });

		for_each(points.begin(), points.end(), [](Point * n) { delete n; });
	}
	catch (Exception e) {
		cout << "exception:" << e.what();
	}*/




		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		vector<unique_ptr<Point>> points;
		//SuperVisor l = SuperVisor(points);
		srand(time(NULL));

		for (int i = 0; i < 3; i++){
			//unique_ptr<Point>(new Point(((float)rand()) * 10 / (float)RAND_MAX, ((float)rand()) * 10 / (float)RAND_MAX));
			points.push_back(unique_ptr<Point>(new Point(((float)rand()) * 10 / (float)RAND_MAX, ((float)rand()) * 10 / (float)RAND_MAX))); //make random points between 0 and 10

		}

		throw Exception ("because i can");
		
		//for_each(points.begin(), points.end(), [](unique_ptr<Point> n) { /*n->print();*/ });
		/*sort(points.begin(), points.end(), ComPoints);
		cout << "---------------------------" << endl;
		for_each(points.begin(), points.end(), [](Point * n) { n->print(); });

		for_each(points.begin(), points.end(), [](Point * n) { delete n; });*/

		for (auto &elem : points) {
			elem->print();
		}
		sort(points.begin(), points.end(), ComPoints2);
		cout << "------------------------------------------------------------------";
		for_each(points.begin(), points.end(), [](const unique_ptr<Point> & p) { p->print(); });




	}

	catch (Exception e) {
		cout << "exception:" << e.what();
	}









	_CrtDumpMemoryLeaks();
	getchar();
	getchar();
	getchar();
	return 0;
}
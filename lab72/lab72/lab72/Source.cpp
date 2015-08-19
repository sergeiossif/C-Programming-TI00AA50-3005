#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "counter.h"

using namespace std;

class LimitedCounter{
public:
    friend ostream &operator<<(ostream &out, const LimitedCounter &c);
	//LimitedCounter(int n0 = 0);
	LimitedCounter(int n0 = 0, int upperLimit = 5);
	LimitedCounter &operator++();
	LimitedCounter operator++(int);
	~LimitedCounter();
	Counter * baseCount;
	LimitedCounter (const LimitedCounter &obj);
	bool operator<(const LimitedCounter &c2) const;
	void reset();
	
	int getCount() const;


private:
	int upperLimit;

};

LimitedCounter::LimitedCounter (const LimitedCounter &obj){
	baseCount = new Counter(obj.getCount()); 
}


LimitedCounter::~LimitedCounter(){
	delete baseCount;
	//cout << "Class destructed";
}

LimitedCounter::LimitedCounter(int n0, int up) {
	upperLimit = up;
	baseCount = new Counter(n0);
	//cout << "new object lol" << endl;
}


LimitedCounter& LimitedCounter::operator++(){
	if(this->baseCount->getCount() < upperLimit > 0){
		this->baseCount->operator++();
	}
	
	return *this;
}

LimitedCounter LimitedCounter::operator++(int){
	if(this->baseCount->getCount() < upperLimit > 0){
		LimitedCounter temp = *this;
		this->baseCount->operator++();
		return temp;
	} else {
		return *this;
	}
}


void LimitedCounter::reset(){
	this->baseCount->reset();
}


ostream &operator<<(ostream &out, const LimitedCounter &c){
	
	out << *c.baseCount;
	return out;
}

int LimitedCounter::getCount() const {
	return this->baseCount->getCount();
}

bool LimitedCounter::operator<(const LimitedCounter &c2) const{
	return this->getCount() < c2.getCount();

}





int main(){


	LimitedCounter lc(0, 5); //initial value 0, upper limit 5
	cout << lc.baseCount->getCount();
	cout << lc++ << endl; //output should be 0
	cout << ++lc << endl; //output should be 2
	lc.reset();
	for (int i = 0; i < 9; i++) {
		lc++;
		cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
	}
	
	cout << "---" << endl;

	cout << lc.getCount() << endl; //output is 5
	cout << (lc < 7) << endl;//Testing the comparison operator //output is 1
	cout << (lc < 1);//Testing the comparison operator //output is 0





	getchar();
	return 0;
}
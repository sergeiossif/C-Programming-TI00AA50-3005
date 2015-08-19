#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "counter.h"

using namespace std;

class LimitedCounter : public Counter{
public:


//    friend ostream &operator<<(ostream &out, const LimitedCounter &c);
//	//LimitedCounter(int n0 = 0);
	LimitedCounter(int n0 = 0, int upperLimit = 5);
	LimitedCounter &operator++();
	LimitedCounter operator++(int);
//	
//	
//	bool operator<(const LimitedCounter &c2) const;
//	void reset();
//	
//	int getCount() const;
//
//
private:
	int upperLimit;

};



LimitedCounter& LimitedCounter::operator++(){
	if(getCount() < upperLimit > 0){
		Counter::operator++();
		}
	
	return *this;
}

LimitedCounter LimitedCounter::operator++(int){
	//if(getCount() < upperLimit > 0){
	//	LimitedCounter temp = *this;
	//	operator++();
	//	return temp;
	//} else {
	//	return *this;
	//}
	LimitedCounter temp = *this;
	operator++();
	return temp;
}



LimitedCounter::LimitedCounter(int n0, int upperLimit0) : Counter(n0){
	upperLimit = upperLimit0;
}






class RoundupCounter : public Counter{
public:
	RoundupCounter &operator++();
	RoundupCounter operator++(int);
	RoundupCounter(int n0 = 0, int upperLimit = 5);


private:

	int upperLimit;
};


RoundupCounter& RoundupCounter::operator++(){
	if (getCount() < upperLimit > 0){
		Counter::operator++();
	}
	else{ 
		count = 0;
	}

	return *this;
}

RoundupCounter RoundupCounter::operator++(int){
	//if(getCount() < upperLimit > 0){
	//	LimitedCounter temp = *this;
	//	operator++();
	//	return temp;
	//} else {
	//	return *this;
	//}
	RoundupCounter temp = *this;
	operator++();
	return temp;
}



RoundupCounter::RoundupCounter(int n0, int upperLimit0) : Counter(n0){
	upperLimit = upperLimit0;
}





int main(){
	RoundupCounter lc(3, 5); //initial value 3, upper limit 5
//	cout << "out: " << lc.getCount() << endl;
	cout << lc++ << endl; //output should be 3
	cout << ++lc << endl; //output should be 5
	lc.reset();
	for (int i = 0; i < 9; i++) {
		lc++;
		cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
	}
	cout << "-----------------------------------" << endl;

	cout << "getcount: " << lc.getCount() << endl; //output is 5
	cout << "lc < 7: " << (lc < 7) << endl;//Testing the comparison operator //output is 1
	cout << "lc < 1: " << (lc < 1);//Testing the comparison operator //output is 0




	getchar();
	return 0;
}
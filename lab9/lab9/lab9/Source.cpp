#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "counter.h"

using namespace std;

class Observer{ //interace class

public:
	virtual void HandleLimitReached(){};


};


class LimitedCounter : public Counter{
public:


	//    friend ostream &operator<<(ostream &out, const LimitedCounter &c);
	//	//LimitedCounter(int n0 = 0);
	LimitedCounter(int n0 = 0, int upperLimit = 5);
	LimitedCounter &operator++();
	LimitedCounter operator++(int);
	void SetObserver(Observer * setobserver){
		observer = setobserver;
	}

	void Notify(){
		if (observer){
			observer->HandleLimitReached();
		}
	}

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
	Observer * observer;

};




class CounterUser: public Observer {
public:
	LimitedCounter *p;

	void IncrementBy(int n){
		for (int i = 0; i < n; i++){
			p->operator++();
		}	
	}



	CounterUser(int n0 = 0, int upperLimit = 5){
		p = new LimitedCounter(n0, upperLimit);
		p->SetObserver(this);
	}
	
	void HandleLimitReached(){
		cout << "Limit has been reached \r\n";
		p->reset();


	}

};












LimitedCounter& LimitedCounter::operator++(){
	if(getCount() < upperLimit > 0){
		Counter::operator++();
	}
	else {
		Notify();
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
		reset();
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




void UseCounter(Counter *counter, int n){
	for (int i = 0; i < n; i++){
		counter->operator++();
	}


}



int main(){
	
	
	
	//LimitedCounter counterA(0, 5);
	//RoundupCounter counterB(0, 5);

	//UseCounter(&counterA, 8); UseCounter(&counterB, 8);
	//cout << "Counter A: " << counterA << endl; // output should be 5 
	//cout << "Counter B: " << counterB << endl; // output should be 2 

	CounterUser *c = new CounterUser();
	c->IncrementBy(12);
	delete c;




	getchar();
	return 0;
}
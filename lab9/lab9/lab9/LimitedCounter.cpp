#include "LimitedCounter.h"
#include <iostream>


LimitedCounter& LimitedCounter::operator++(){
	if (getCount() < upperLimit > 0){
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



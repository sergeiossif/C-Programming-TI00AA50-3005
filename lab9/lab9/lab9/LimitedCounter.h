#include <iostream>
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


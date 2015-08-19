// Lab22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

class Dice{
private:

public:
	void initialize();
	double roll();

};


void Dice::initialize(){
	srand(time(NULL));
}

double Dice::roll(){
	return (float)rand() / RAND_MAX;
}

class Counter{
private:
	int count;
public:
	void reset();
	void increment();
	int getCount();
};

void Counter::reset(){
	count=0;};

void Counter::increment(){
	if(count < INT_MAX){
		count++;
	} else {
		cout << "\r\nCounter overflow";
	}
}

int Counter::getCount(){
	return count;
}




class Inspector{
	private:
		double minval, maxval;
	public:
		void setLimits(double min, double max);
		bool isInLimits(double val);
};

void Inspector::setLimits(double min, double max){
	minval = min;
	maxval = max;
}

bool Inspector::isInLimits(double val){
	if(val < maxval && val > minval)
		return true;
	else
		return false;
}

int main() {
	Dice dice;
	Counter counter1, counter2, i;
	Inspector inspector;

	dice.initialize();
	counter1.reset(); counter2.reset(), i.reset();
	inspector.setLimits(0.0, 0.5);
	while (i.getCount() < 100) {
		if (inspector.isInLimits(dice.roll()))
			counter1.increment();
		else 
			counter2.increment();
		i.increment();
		}
	
	cout << counter1.getCount() << endl;
	cout << counter2.getCount() << endl;


	cin.get();
	return 0;
}
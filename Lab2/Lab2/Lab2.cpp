// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Time {
private:
	int hours, minutes;
public:
	void read(string msg);
	bool lessThan(Time comp);
	int getMinutes();
	int getHours();
	void display();
    void substract(Time main, Time sub);

};

void Time::substract(Time main, Time sub){
	int tempMinutes = (main.getHours()*60 + main.getMinutes()) - (sub.getHours()*60 + sub.getMinutes());
	hours = floor(tempMinutes / 60);
	minutes = tempMinutes % 60;


}
int Time::getMinutes() {
	return minutes;
}


int Time::getHours(){
	return hours;
}




void Time::read(string msg){
cout << msg;
cin >> hours >> minutes;
}

bool Time::lessThan(Time comp){
	if (hours < comp.getHours()){
		return true;
	} else if ((hours == comp.getHours()) && minutes < comp.getMinutes()){
		return true;
	} else {
		return false;
	}
}

void Time::display(){
	cout << "\r\n" << hours << ":" << minutes;
}

int main()
{
	Time time1, time2, duration;
	time1.read("\r\nEnter time 1: ");
	time2.read("\r\nEnter time 2: ");






	if (time1.lessThan(time2)) {
		duration.substract(time2, time1);
		cout << "\r\nStarting time was ";
		time1.display();
	} else {
		duration.substract(time1, time2);
		cout << "\r\nStarting time was ";
		time2.display();
	}

	cout << "Duration was ";
	duration.display();


	cin.get();
	cin.get();
	return 0;
}


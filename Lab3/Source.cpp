// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS


//#include "stdafx.h"


#include <iostream>
#include <stdlib.h>

//#ifdef _DEBUG // Active only in Debug Configuration
//#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated
//#include <crtdbg.h> // runtime debug functions are declared here
//#endif



class String{
public:
	String(char *instring);
	~String();
	String(const String &p);
	void list();

private:
	char * c_string;

};


String::String(const String &p){
	c_string = new char[strlen(p.c_string) + 1];
	strcpy(c_string, p.c_string);
}

String::String(char *instring){
	c_string = new char[strlen(instring) + 1];
	strcpy(c_string, instring);

};

String::~String(){
	std::cout << "Destruction is now complete\r\n";
	delete c_string;
}

void String::list(){
	std::cout << c_string << "\r\n";
}




void f(String s) {
	s.list();}

int main()
{
	
	String s("abcdefgb");
	s.list();
	f(s);
	s.list();

	getchar();
	return 0;
}



/*
void f(int i) {
	String s("abcdefghijklmnopqrstuvwxyz");
	if (i % 100 == 0)
	s.list();
}
int main() {
	int i = 0;
	_CrtMemState memory; // C/C++ runtime memory management state storage
	while (i < 1000) {
		f(i++);
		// dump memory management state
		_CrtMemCheckpoint(&memory); _CrtMemDumpStatistics(&memory);
	}
	_CrtDumpMemoryLeaks(); // check if there were memory leaks
	return 0;
}
*/

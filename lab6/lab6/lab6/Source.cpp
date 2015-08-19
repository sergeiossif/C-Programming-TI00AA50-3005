// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS



#include <iostream>
#include <stdlib.h>




using namespace std;


class String{
public:
	String(char *instring);
	~String();
	String(){
		c_string = new char[1];
		nString+=1;
	}
	String(const String &p);
	char * list();
	void operator=(const String &p);
	friend ostream &operator<<(ostream &output, const String &p){
		output << p.c_string;
		return output;
	}

	String operator+(const String &p);

	String operator++();
	String operator++(int);
	char &operator[](int i);
	operator const char*();

	static const int MAX_STRING_LENGTH = 10;
	static int nString;

	const char& operator[](int i) const;
private:
	char * c_string;
	

};

String::operator const char*(){
	return c_string;
}


char & String::operator[](int i){
	if ((i >= 0) && (i < strlen(c_string))){
		return c_string[i];
	}
}
String String::operator++(){

	return *this + String("X");
}


String String::operator++(int){

	String old = *this;
	*this = *this + String("X");
	
	
	return old;
}

String String::operator+(const String &p){
	String output;
	char * str;
	str = new char[strlen(p.c_string) + strlen(this->c_string) + 1];
	strcpy(str, this->c_string);
	strcat(str, p.c_string);

	output = str;
	delete [] str;
	return output;


}
void String::operator=(const String &p){
	if (this != &p){
		delete c_string;
		c_string = new char[strlen(p.c_string) + 1];
		strcpy(c_string, p.c_string);
	}
}

String::String(const String &p){
	nString+=1;
	c_string = new char[strlen(p.c_string) + 1];
	strcpy(c_string, p.c_string);
}

String::String(char *instring){
	nString+=1;
	bool truncate = false;
	int length = strlen(instring);

	if (length > MAX_STRING_LENGTH) {
		length = MAX_STRING_LENGTH;
		truncate = true;}

	c_string = new char[length + 1];

	if (truncate) {
		strncpy(c_string, instring, length);
		c_string[length] = '\0';

	} else {
		strcpy(c_string, instring);
	}
	
	

};
const char & String::operator[](int i) const{

	if ((i >= 0) && (i < strlen(c_string))){
		return c_string[i];
	}

}



String::~String(){
	std::cout << "Destruction is now complete\r\n";
	delete c_string;
}

char * String::list(){
	return c_string;
}



void display(const String &p){
	for (int i=0; i < String::MAX_STRING_LENGTH; i++){
		cout << p[i];
	}
}

int	String::nString = 0;

int main(){
	
	cout << "number of strings: " << String::nString << endl;
	String array[4];

	cout << "number of strings: " << String::nString << endl;


	cout << endl << endl << endl << "----------------------------------------------" << endl << endl << endl;
	
	
	
	
	
	
	
	String s("abcdefgsxxxxxxx"); // MAX_STRING_LENGTH is 10
	
	s[2] = 'Y';
	display(s); // outputs the string to the screen
	
	getchar();
	return 0;
}




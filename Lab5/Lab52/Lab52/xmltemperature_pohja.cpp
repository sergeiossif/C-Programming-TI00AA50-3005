// Exercise 5

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string find_field(const string &text, string tag){
	string output, startTag, endTag;
	startTag = "<" + tag + ">";
	endTag = "</" + tag + ">";
	int start = 0, end = 0;
	
	start = text.find(startTag);
	start += startTag.size();
	end = text.find(endTag, start);
	if ((end-start) > 0 && (end-start) < 100){
		output = text.substr(start, end-start);
	} else {
		cout << "something went wrong";}
	//cout << tag << endl << startTag << endl << endTag;


	return output;

	
}
int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}
	// Now page is a string that contains the whole xml page
	
	// Here you need to write something that finds and 
	// extracts location and temperature from the XML
	// data in the string page and stores them in 
	// the strings location and temperature respectively
	
	location = find_field(page, "location");
	temperature = find_field(page, "temp_c") + " C";


	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl; 
	system("pause");
}

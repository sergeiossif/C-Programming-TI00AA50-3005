#define _CRT_RAND_S
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#ifdef _DEBUG // Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated
#include <crtdbg.h>
#endif

class WordPool {
public:
	void fill(string letter, ifstream &input);
	friend ostream &operator<<(ostream &output,  WordPool &p){
		output << p.randomWord();
		return output;
	}
	string randomWord(){
		//int r = rand() % limit;
		unsigned int  r;
		rand_s(&r);
		r = (unsigned int) ((double)r /  ((double) UINT_MAX + 1 ) * (double) limit) + 1;

		//cout << "random is: " << r << endl;
		return wordArray[r];}

	WordPool operator + (WordPool &p) {
		WordPool output;
		output.Word = Word + " " + p.randomWord();
		return output;
	}

	
	 operator std::string() const {
		return Word;}

private:
	string Word;
	string wordArray[40];
	int limit;

};


string giveStatement(string filename) {
	WordPool g, a, s, v;
	ifstream inputFile(filename);
	g.fill("G", inputFile); a.fill("A", inputFile); s.fill("S", inputFile); v.fill("V", inputFile);
	return g + a + s + v + g + a + s;
}


int main (void) {

	cout << giveStatement("oracle.dat") << endl << endl;
	//getchar();

#ifdef _DEBUG
if (_CrtDumpMemoryLeaks())
cout << "WARNING: There was a memory leak in your program" << endl;
else
cout << "Your program has no memory leaks, congratulations!" << endl;
#endif
system("PAUSE");
}

void WordPool::fill(string letter, ifstream &input){
	string line, page;
	bool state = false;
	letter = "[" + letter + "]";

	int i = 0;
	int index = 0;
	while (getline (input, line)) {
		if(!state){
			if(line == letter){
				state = true;
			}
		}	 else if(line[0] != '[') {
				wordArray[i] = line;
				i++;
			} else {state = 0;}

	}
	limit = i - 1;
	Word = randomWord();
	input.clear();
	input.seekg(0, ios::beg);

	
	}
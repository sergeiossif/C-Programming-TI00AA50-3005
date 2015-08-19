#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <functional>
using namespace std;



struct field_reader : ctype<char> { // specify '\n' as the only separator
	field_reader() : ctype<char>(get_table()) {}
	static ctype_base::mask const *get_table() {
		static vector<ctype_base::mask>
			rc(table_size, ctype_base::mask());
		rc['\n'] = ctype_base::space;
		return &rc[0];
	}
};

class Athlete{
public:

	Athlete(string inputName) { 
		name = inputName;
		id = 0;
		time = 0;
		//id++;
		//id = n++;
	}

	friend ostream& operator<<(ostream& os, const Athlete& dt){


		os << "#" << dt.id << " " << dt.name << " with the time: "<< dt.time << endl;
		return os;

	}


	void GetID() { id = n++; }
	string name;
	int id;
	operator string(){ return name; }
	static int n;
	int time;

	void ReadTime(){
		cout << "\r\Enter time for " << name  << "(id " << id << "): ";
		cin >> time;
	}

	friend bool operator< (Athlete a1, Athlete a2)
	{
		return a1.time < a2.time;
	}

	void print(){ cout << *this; }


};

int Athlete::n = 1;

int main() {
	vector<string> names;

	vector<Athlete> athletes;
	ifstream myfile("athletes.txt");
	myfile.imbue(locale(locale(), new field_reader()));// use our own separator list
	istream_iterator<string> eof;
	istream_iterator<string> iit(myfile);
	ostream_iterator<string> ostr_it(cout, "\n");

	/*istream_iterator<Athlete> eof;
	istream_iterator<Athlete> iit(myfile);
	ostream_iterator<Athlete> ostr_it(cout, "\n");*/



	copy(iit, eof, back_inserter(names));




	//copy(names.begin(), names.end(), ostr_it);


	copy(names.begin(), names.end(), back_inserter(athletes));
	//copy(names.begin(), names.end(), athletes);
	//foreach(names.begin(), names.end(), )
	//cout << "-----------------------------------------------\r\n";
	//copy(athletes.begin(), athletes.end(), ostr_it);

	random_shuffle(athletes.begin(), athletes.end());

	for_each(athletes.begin(), athletes.end(), [](Athlete &n) { n.GetID(); });

	//cout << "-----------------------------------------------\r\n";
	//copy(athletes.begin(), athletes.end(), ostr_it);

	for_each(athletes.begin(), athletes.end(), [](Athlete &n) { n.ReadTime(); }); 

	sort(athletes.begin(), athletes.end());

	//copy(athletes.begin(), athletes.end(), ostr_it);


	for_each(athletes.begin(), athletes.end(), [](Athlete &n) { cout << n; });
	



	getchar();
	getchar();
	getchar();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int main(){
	pair <int, pair<string, string>> pair1, pair2;
	pair1.first = 1;
	pair1.second = make_pair("Miko", "Salo");
	pair2.first = 2;
	pair2.second = make_pair("Marcus", "Gronholm");

//	cout << "ID: " << pair1.first << " Firstname: " <<  pair1.second.first << " Last name: ; 

	cout << "ID    First name     Last name" << endl << pair1.first << "     " << pair1.second.first << "           " << pair1.second.second << endl
		<< pair2.first << "     " << pair2.second.first << "         " << pair2.second.second;

	cout << endl << endl << endl << "__________________________________________________________________" << endl << endl << endl;


	vector <string> storage;
	string lastString;
	pair <int, string> longestString(0,"");
	vector <pair<int, int>> stats;


	while (1) {
		cin >> lastString;
		if (lastString != "stop"){
			storage.push_back(lastString);
			if (lastString.size() > longestString.first){
				longestString = make_pair(lastString.size(), lastString);
			}


		}
		else { 
			break; 
		}

		//cout << "| size :" << storage.size() << " capacity :" << storage.capacity();
		stats.push_back(make_pair(storage.size(), storage.capacity()));
	}





	cout << "Processing... " << endl;
	cout << "Longest one is: " << longestString.second << " with the size of: " << longestString.first << endl;
	cout << "Data: " << endl;
	for (vector<string>::iterator i = storage.begin(); i != storage.end(); ++i){
		cout << *i << endl;
	}

	cout << "Total amount: " << storage.size() << endl;

	cout << "Sizeof : " << sizeof(storage) << endl;

	//vector<pair<int,int>>::iterator i = stats.begin(); i != stats.end(); ++i
	cout << "Size Capacity Contents:" << endl;

	for (int i = 0; i < stats.size();i++){
		
		cout << stats[i].first << "      " << stats[i].second << "      " << "|" ;
		for (int j = 0; j < stats[i].second; j++){
			if (j < stats[i].first){
				cout << storage[j] << "|";
			}
			else { cout << "X|"; }

		}
		cout << endl;
		
		
		
		// << storage[i] << "|";
		
	
	
	
	}



	
	
	//cout << (string)get<1, string, string>(pair1.second);
	

	getchar();
	getchar();
	return 0;
}
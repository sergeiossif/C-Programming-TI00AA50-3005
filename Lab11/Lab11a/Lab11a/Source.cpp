#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <stdlib.h>
#include <algorithm>



using namespace std;

//Ordinary function
int randGen_1() {
	return rand() % 10 + 1;
}
//Function object
class RandGen_2 {
public:
	RandGen_2() : numbers() { srand(time(NULL)); }
	int operator()();
private:
	vector<int> numbers;
};
/*int iter = 1;
template <class T> void printout(T text){
	cout << "#" << iter << ":" << text << endl;
	iter++;



}*/

template <typename T>
class printOut {
public:
	printOut(){
	i = 1;
}
	void operator()(T text){
		cout << "#" << i << ":" << text << endl;
		i++;

	}
	
private:
	int i;



};

void main(void) {
	vector<int> numbers1(7), numbers2(7), similar(7);
	RandGen_2 randGen_2;
	vector<int>::iterator it;
	ostream_iterator<int> out_it(std::cout, ", ");
	//printOut<int> d;
	//this is how to use "ordinary"function
	/* srand(time(NULL)); // it is necessary to remember to call this
	generate(numbers.begin(), numbers.end(), randGen_1); */
	//this is how to use function object
	

	generate(numbers1.begin(), numbers1.end(), randGen_2);
	generate(numbers2.begin(), numbers2.end(), randGen_2);
	


	
	cout << "Set1: ";
	copy(numbers1.begin(), numbers1.end(), out_it);
	cout << "\r\nSet2: ";
	copy(numbers2.begin(), numbers2.end(), out_it);


	sort(numbers1.begin(), numbers1.end());
	sort(numbers2.begin(), numbers2.end());
	it = set_intersection(numbers1.begin(), numbers1.end(), numbers2.begin(), numbers2.end(), similar.begin());
	similar.resize(it - similar.begin());

	cout << "\r\nSimilar: \r\n";
	for_each(similar.begin(), similar.end(), printOut<int>());
	//copy(similar.begin(), similar.end(), out_it);







	getchar();
	getchar();
}
int RandGen_2::operator()() {
	int number;
	do {
		number = rand() % 10 + 1;
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}
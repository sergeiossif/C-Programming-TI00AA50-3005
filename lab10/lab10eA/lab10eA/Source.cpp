#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
struct dim {
	int row, column;
};

int main() {

	//vector < vector<int> >  matrix;
	//pair <int, int> dimensions;
	dim dimensions;
	cout << "Enter dimensions of the matrix divived by space (row column): ";
	cin >> dimensions.row >> dimensions.column;

	vector < vector<int> >  matrix(dimensions.column, vector<int>(dimensions.row));

	///cout << "row" << size.first << "col" << size.second;
	cout << endl << "Thanks, now enter integers one by one:" << endl;

	int size = dimensions.row * dimensions.column;
	int x, y;
	
	for (int i = 0; i < size; i++){

		y = i / dimensions.column;
		//cout << i << " | " << y << endl;
		x = i % dimensions.column;
		cin >> matrix[x][y];

		//cout << "x: " << x << "y: " << y << endl;

	}

	cout << "Processing... Done!" << endl << endl;

	for (int i = 0; i < dimensions.row; i++){
		for (int j = 0; j < dimensions.column; j++){
			cout << " " << matrix[j][i] << " ";
		}
		cout << endl;

	}









	getchar();
	getchar();
	return 0;

}
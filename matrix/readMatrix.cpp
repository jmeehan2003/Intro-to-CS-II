/***********************************************************
** Author: James Meehan
** Date: 4/4/2018
** Description: This is the readMatrix() function
** definition.  readMatrix() takes a pointer to a 2D
** array and the size of the matrix as parameters and
** prompts the user for all the numbers within the matrix
**********************************************************/

#include <iostream>
#include "readMatrix.hpp"
using std::cout;
using std::cin;
using std::endl;

void readMatrix(int **matrix, int size) {
	int num = size * size;
	cout << "Please enter " << num << " integers to fill the matrix: " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> matrix[i][j];
		}
	}
}


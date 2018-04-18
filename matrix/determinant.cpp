/***********************************************************
** Author: James Meehan
** Date: 4/4/2018
** Description: This is the determinant() function
** definition.  The determinant() function takes a pointer to 
** a 2D array and the size of the matrix as parameters and
** calculates and returns the determinant
**********************************************************/

#include <iostream>
#include "determinant.hpp"
using std::cout;
using std::endl;

int determinant(int **matrix, int size) {
	int det;
	if (size == 2) {
		det = ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
		cout << "The determinant is: " << det << endl;
		return det;
	}
	else if (size == 3) {
		int firstCalc = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]));
		int secondCalc = matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]));
		int thirdCalc = matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));
		det = firstCalc - secondCalc + thirdCalc;
		cout << "The determinant is: " << det << endl;
		return det;
	}
	else {
		cout << "Invalid matrix size" << endl;
		return -1;
	}
}


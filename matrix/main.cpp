#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;

int getMatrixSize();
void displayMatrix(int**, int);
void deleteMatrix(int**, int);

int main() {

	//get size of matrix from user
	int size = getMatrixSize();

	//dynamically allocate 2D matrix
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	//read into matrix, display matrix, and determinant
	readMatrix(matrix, size);
	displayMatrix(matrix, size);
	determinant(matrix, size);
	
	//delete matrix and exit
	deleteMatrix(matrix, size);
	return 0;
}

int getMatrixSize() {
	int matrixSize = 0;
	while (matrixSize != 2 && matrixSize != 3) {
		cout << "Please choose the size of your matrix. Enter 2 for 2x2 or 3 for 3x3:" << endl;
		cin >> matrixSize;
		while (std::cin.fail()) {
			cout << "Error: You must enter either 2 (for 2x2) or 3 (for 3x3). Please choose the size of your matrix: " << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> matrixSize;
		}
	}
	return matrixSize;
}

void displayMatrix(int** matrix, int size) {
	cout << endl << "The matrix is: " << endl << endl;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
	}
		cout << endl;
}
	cout << endl;
}

void deleteMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
			delete matrix[i];
	}
	delete[] matrix;
	matrix = NULL;
}
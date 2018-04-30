#include <iostream>
#include "functions.hpp"
using std::cout;

void printReverse(std::string str) {
	int n = str.size() - 1;
	if (n == 0) {
		cout << str[n] << '\n';
	}
	else {
		cout << str[n];
		std:: string s = str.substr(0, n); 
		printReverse(s);
	}
}

int sumArray(int* intArr, int size) {
	if (size == 1)
		return intArr[0];
	else {
		return intArr[size-1] + sumArray(intArr, size - 1);
	}
}

int triangularNumber(int N) {
	if (N == 1)
		return 1;
	else 
		return N + triangularNumber(N - 1);
}

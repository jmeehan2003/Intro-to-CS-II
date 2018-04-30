#include <iostream>
#include "functions.hpp"
using std::cout;
using std::cin;
using std::endl;

int menu();
void menuPause();
int main() {
	int val;
	do {
		val = menu();
	} while (val !=4);
	


	return 0;

}


int menu() {
	int val;
	cout << "Recursive Functions Menu: " << endl << endl;
	
	cout << "   1.  Print a String in Reverse" << endl;
	cout << "   2.  Sum an Array of Integers" << endl;
	cout << "   3.  Calculate a Triangular Number" << endl;
	cout << "   4.  Quit " << endl << endl; 
 
	cout << "Which option would you like to select? ";  
	cin >> val;
	
	while (cin.fail() || val < 1 || val > 4) {
		cout << "Invalid Option: Please select the number that corresponds with your selection." << endl << endl;

		cout << "   1.  Print a String in Reverse" << endl;
		cout << "   2.  Sum an Array of Integers" << endl;
		cout << "   3.  Calculate a Triangular Number" << endl;
		cout << "   4.  Quit " << endl << endl; 
 
		cout << "Which option would you like to select? ";  
		cin.clear();
		cin.ignore(245, '\n');
		cin >> val;
	}

	cin.ignore();
	cout << endl;
	if (val == 1) {
		std::string s;
		cout << "Please enter a string: ";
		getline(cin, s);
		cout << "The string in reverse is: ";
	 	printReverse(s);
		cout << endl;
		menuPause();	
	} 
	else if (val == 2) {
		int size;
		cout << "How many integers will be in the array? ";
		cin >> size;
		while (cin.fail() || size < 1) {
			cout << "Please enter an integer greater than 0. How many integers will be in the array? ";
			cin >> size;
			cin.clear();
			cin.ignore(1000, '\n');
		}	
		int array[size];
		int num;
		for (int i = 0; i < size; i++) {
			cout << "Please enter an integer: ";
			cin >> num;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid entry. Please enter an integer: ";
				cin >> num;
			} 
			array[i] = num;
		}
		cout << "The array is: ";
		for (int j = 0; j < size; j++) 
			cout << array[j] << " ";
		cout << endl << "The sum of the Array is: " << sumArray(array, size) << endl;		
		cin.ignore(1000, '\n');
		cout << endl;
		menuPause();	
	}
	else if (val == 3) {
		int triNum;
		do {
			cout << "Please enter a number (1 or greater) to get its triangular number: ";
			cin >> triNum;	
			cin.clear();
			cin.ignore(1000, '\n');
		
		} while (cin.fail() || triNum < 1);
		cout << "The triangular number of " << triNum << " is " << triangularNumber(triNum) << endl;
		cout << endl;
		menuPause();	
	}
		
	return val;
}

void menuPause() {

	cout << "Press any key to return to the Main Menu. " << endl;
	cin.clear();
	cin.get();
}

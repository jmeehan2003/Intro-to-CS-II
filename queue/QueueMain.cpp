#include <iostream>
#include "Queue.hpp"
using std::cin;
using std::cout;
using std::endl;

int listMenu();
int integerValidation(std::string, bool);

int main() {
	Queue* newQ = new Queue;
	cout << "Welcome to James's Circular Linked List Queue!" << endl << endl;
	int selection = listMenu();
	
	while (selection != 5) {
		if (selection == 1) {
			int val;
			bool valid = false;
			while (!valid) {
				std::string input;	
				cout << "Value to add: ";
				getline(cin, input, '\n');
				if (integerValidation(input, true)){
					val = std::stoi(input);	
					valid = true;
				}
				else
					cout << "Invalid entry. Please enter an integer." << endl;
			}		
				
			newQ->addBack(val);
			cout << "Your queue is: ";
			newQ->printQueue();
		}
		else if (selection == 2)
			if (!(newQ->isEmpty())) 
				cout << "The value at the front of the queue is: " << newQ->getFront() << endl << endl;
			else
				cout << "The list is empty." << endl << endl;
		else if (selection == 3) {
			if (!(newQ->isEmpty()))
				cout << "The value " << newQ->getFront() << " has been removed from the front of the queue." << endl << endl;
			newQ->removeFront();
		}
		else if (selection == 4)
			newQ->printQueue();
		else {
			cout << "Something went terribly wrong! Exiting the program." << endl;
			return -1;
		}

		selection = listMenu();
	}

	delete newQ;
	return 0;
}

int listMenu() {
	int selection = 0;
	while ( selection < 1 || selection > 5 )
	{
	cout << "Main Menu" << endl;
	cout << "Please select one of the following options: " << endl << endl;

	cout << "   1. Add a value to the back of the queue" << endl;
	cout << "   2. Display the front value" << endl;
	cout << "   3. Remove the front node" << endl;
	cout << "   4. Display the queue's contents" << endl;
	cout << "   5. Exit" << endl << endl;

	cout << "Your selection: ";
	std::string userInput;
	getline(cin, userInput, '\n');
	if (integerValidation(userInput, false))
		selection = std::stoi(userInput);
	else if(!(integerValidation(userInput, false)) || selection > 5)
		cout << endl << "Invalid entry.  Please select one of the five options by entering an integer between 1 and 5." << endl << endl;
	}

	cout << endl;
	return selection;
}

int integerValidation(std::string str, bool negativeAllowed){
	int num = 0;

	// check if string is empty
	if ( str.empty( ) )
		return num;

	// check if negatives are allowed for input
	if (negativeAllowed){	
		// allows negative integers
		if ( (int)str[0] != 45 && ( (int)str[0] < 48 || (int)str[0] > 57 ))
			return num;
		
		// check to see if all elements are integers
		for ( unsigned int i = 1; i < str.size( ); i++ ) {
			if ( (int)str[i] < 48 || (int)str[i] > 57 )
				return num;
		}
	}
	else
		// check to see if all elements are integers
		for ( unsigned int i = 0; i < str.size( ); i++ ) {
			if ( (int)str[i] < 48 || (int)str[i] > 57 )
				return num;
		}
	

	// if we haven't returned yet, then we have a valid integer
	num = 1;
	return num;
}

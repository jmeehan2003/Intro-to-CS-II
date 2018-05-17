/**********************************************************
** Author: James Meehan
** Date: 5/15/2018
** Description: Doubly linked list
************************************************************/
#include <iostream>
#include <string>
#include "list.hpp"
using std::cout;
using std::endl;
using std::cin;

int listMenu( );
int integerValidation( std::string );

int main ( ) {
	LinkedList* list = new LinkedList;
	int opt = listMenu( );
	std::string input;
	
	while ( opt != 6 ){
		// add node to head of list	
		if ( opt == 1 ){
			int val = 0;
			while ( !val ) {
				cout << "What value would you like to add to the beginning of the list? ";
				getline( cin, input, '\n' );
				if ( integerValidation( input ) ){
					val = std::stoi( input );
					addLinkAtHead( list, val );
					val = 1;
				}
				else
					cout << "Invalid entry. Please enter an integer." << endl;		
			}
		}
		// add node to tail of list
		else if ( opt == 2 ){
			int val = 0;
			while ( !val ) {
				cout << "What value would you like to add to the end of the list? ";
				getline( cin, input, '\n' );
				if ( integerValidation( input ) ){
					val = std::stoi( input );
					addLinkAtTail( list, val );
					val = 1;
				}
				else
					cout << "Invalid entry. Please enter an integer." << endl;		
			}

		}
		// delete first node
		else if ( opt == 3 )
			deleteFirstNode( list );
		// delete last node
		else if ( opt == 4 )
			deleteLastNode( list );
		// print list in reverse
		else if ( opt == 5 )
			printListReverse( list );
		// unexpected input
		else 
			cout << "Error: Invalid entry." << endl;

		opt = listMenu( );	
	}	 
	
	// user enterd 6 to exit
	cout << "Exiting program.  Goodbye :)" << endl;	
	
	// free memory and return
	deleteList( list );
	return 0;
}

int listMenu( ){
	int selection = 0;
	while ( selection < 1 || selection > 6 ){
	cout << "Welcome to the Super Linked List Creator!" << endl;
	cout << "Please choose from the following options:" << endl << endl;

	cout <<"   1. ADD a NEW node to the HEAD" << endl;
	cout <<"   2. ADD a NEW node to the TAIL" << endl;
	cout <<"   3. DELETE a node from the HEAD" << endl;
	cout <<"   4. DELETE a node from the TAIL" << endl;
	cout <<"   5. TRAVERSE the list in REVERSE" << endl;
	cout <<"   6. EXIT" << endl << endl;
	
	cout << "Your selection: ";
	
	std::string userInput;
	getline( cin, userInput, '\n' );
	if ( integerValidation( userInput ) )
		selection = std::stoi( userInput );
	else if( !(integerValidation( userInput )) || selection > 6)
		cout << endl << "Invalid entry.  Please enter an integer between 1 and 6." << endl;
	}
	
	cout << endl;
	return selection;
}

int integerValidation( std::string str ){
	int num = 0;

	// check if string is empty
	if ( str.empty( ) )
		return num;
	
	// allows negative integers
	if ( (int)str[0] != 45 && ( (int)str[0] < 48 || (int)str[0] > 57 ))
		return num;

	// check to see if all elements are integers
	for ( unsigned int i = 1; i < str.size( ); i++ ) {
		if ( (int)str[i] < 48 || (int)str[i] > 57 )
			return num;
	}

	// if we haven't returned yet, then we have a valid integer
	num = 1;
	return num;
}

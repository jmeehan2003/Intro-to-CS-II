/**********************************************************************
** Author: James Meehan
** Date : 4/8/2018 
** Description: This program takes a user specified file, stores
** the count of each specific character in an array, and then outputs
** the data to a user specified file for each paragraph in the file.
**********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "count_letters.hpp"
#include "output_letters.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

void clear_array(int*);

int main()
{
	ifstream inFile;
	string input;
	int letters[26] = {0};

	//get input file name from user
	cout << "What is the name of the file you would like to read? ";
	cin >> input;
	inFile.open(input);
	if (!inFile)
	{
		cout << "Unable to open read file! Program terminating.";
		return 1;
	}
	
	//get each character, store in the array, and then export to outFile
	while (!inFile.eof()) {
		count_letters(inFile, letters);
		ofstream outFile;
		output_letters(outFile, letters);
		clear_array(letters);
		outFile.close();
	}

	cout << endl << "Output successfully sent to file(s). Goodbye." << endl;
	inFile.close();
	return 0;
}

void clear_array(int* letters) {
	for (int i = 0; i < 26; i++)
		letters[i] = 0;
}
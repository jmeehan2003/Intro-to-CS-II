#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "count_letters.hpp"
using std::string;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

#include "output_letters.hpp"

void output_letters(ofstream & outFile, int* letters) {
	
	string output;
	//get file name from user
	cout << "What would you like to name the file containing the output? ";
	cin >> output;

	//open output file
	outFile.open(output);
	if (!outFile) {
		cout << "Output file failed to open";
	}
	
	//send data to outFile
	char first = 'a';
	for (int i = 0; i < 26; i++) {
		outFile << first << ": " << letters[i] << endl << endl;
		first++;
	}
	outFile << endl;
}

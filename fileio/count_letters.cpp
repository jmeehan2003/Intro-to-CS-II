#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "count_letters.hpp"
using std::string;
using std::ifstream;

#include "count_letters.hpp"

void count_letters(ifstream & inFile, int* letters) {
	string line; 
	getline(inFile, line);
		char ch;
		for (unsigned i = 0; i < line.length(); i++) {
			//get value of next character, change it to uppercase, and get integer value
			ch = line.at(i);
			ch = toupper(ch);
			int pos = ch - 65;

			//update letter count in array
			if (pos >= 0 && pos <= 25)
				letters[pos]++;
		}
}
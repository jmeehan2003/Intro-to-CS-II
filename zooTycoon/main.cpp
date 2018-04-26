#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "zoo.hpp"
#include "game.hpp"
using std::cout;
using std::endl;
using std::cin;

int startMenu();

int main() {
	srand(time(0));

	int play = startMenu();
	Game g1;

	// set up game if user wants to play
	if (play) {
		g1.setUp();
	}

	// run game
	while (play) {
		g1.beginDay();
		g1.randomEvent();	
		play = g1.endDay();
	}

	return 0;
}



int startMenu() {
	int val;
	cout << std::string(50, '\n') << endl;
	cout << "Please select one of the following two options:" << endl << endl;
	cout << "   1. Start Meehan's Zoo Mania" << endl;
	cout << "   2. Quit" << endl << endl;
	cout << "Press 1 to Start or 2 to Quit: ";
	cin >> val;
	while (cin.fail()) {
		cout << "Error: You did not enter an integer.  Please enter either 1 or 2." << endl;
		cout << "Please select one of the following two options:" << endl << endl;
		cout << "   1. Start Meehan's Zoo Mania" << endl;
		cout << "   2. Quit" << endl << endl;
		cout << "Press 1 to Start or 2 to Quit: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> val;
	}
	while (val != 1 && val != 2) {
		cout << "Error: Invalid number entered.  Please enter only either 1 or 2." << endl;
		cout << "Please select one of the following two options:" << endl << endl;
		cout << "   1. Start Meehan's Zoo Mania" << endl;
		cout << "   2. Quit" << endl << endl;
		cout << "Press 1 to Start or 2 to Quit: ";
		cin >> val;
	}

	if (val == 1)
		return 1;
	else {
		cout << "Exiting the program. G'day mate!" << endl;
		return 0;
	}
}

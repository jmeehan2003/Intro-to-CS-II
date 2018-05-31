#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "hpotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
using std::cin;
using std::cout;
using std::endl;


void startMenu();
int getFighter(int);
int endMenu();
int integerValidation(std::string, bool);

int main() 
{
	srand(time(NULL));
 	int playAgain = 1;
	while(playAgain != 2)
	{
		Character *c1;
		Character *c2;

		startMenu();

		// assign user selected derived class to base class pointer
		int fighter1 = getFighter(1);
		switch(fighter1) 
		{
		case 1:
			c1 = new Barbarian;
			break;
		case 2:
			c1 = new Bluemen;
			break;
		case 3:
			c1 = new Hpotter;
			break;
		case 4: 
			c1 = new Medusa;
			break;
		case 5:
			c1 = new Vampire;
			break;
		default:
			cout << "Error: Invalid input" << endl;
		}	
		cout << "Player 1 is a " << c1->getName() << endl;
	
		int fighter2 = getFighter(2);
		switch(fighter2) 
		{
		case 1:
			c2 = new Barbarian;
			break;
		case 2:
			c2 = new Bluemen;
			break;
		case 3:
			c2 = new Hpotter;
			break;
		case 4: 
			c2 = new Medusa;
			break;
		case 5:
			c2 = new Vampire;
			break;
		default:
			cout << "Error: Invalid input" << endl;
		}
		cout << "Player 2 is a " << c2->getName() << endl;
	
		int round = 1;
		int turn = 0;
		bool bothAlive = true;
		while (bothAlive)
		{
			if (turn == 0)
			{
				cout << "******************************************************************************" << endl;
				cout << "Round " << round << ": " << endl;
				cout << "Attacker: " << c1->getName() << endl;
				cout << "Defender: " << c2->getName() << "  Armor: " << c2->getArmor() << " Strength Points: " << c2->getStrength() << endl << endl;
				int att = c1->attack();
				cout << "Total Attack Roll: " << att << endl << endl;
				int def = c2->defense(att);
				cout << "Total Defense Roll: " << def << endl << endl;
				int damage = att - def - c2->getArmor();
				// clamp damage to zero
				if (damage < 0)
					damage = 0;
				cout << "Total inflicted damage: " << damage << endl;
				cout << "Defender's strength points: " << c2->getStrength() << endl << endl;
	
				// check if fighter 2 was killed
				if (c2->getStrength() <= 0)
				{
					c1->finalWords();
					cout << "Player 2's " << c2->getName() << " has been defeated in " << round << " rounds." << endl << endl;
					bothAlive = false;
					cout << "******************************************************************************" << endl;
					break;
				}
			}
			else
			{
				cout << "***************************" << endl;
				cout << "Attacker: " << c2->getName() << endl;
				cout << "Defender: " << c1->getName() << "  Armor: " << c1->getArmor() << " Strength Points: " << c1->getStrength() << endl << endl;
				int att = c2->attack();
				cout << "Total Attack Roll: " << att << endl << endl;
				int def = c1->defense(att);
				cout << "Total Defense Roll: " << def << endl << endl;
				int damage = att - def - c1->getArmor();
				// clamp damage to zero
				if (damage < 0)
					damage = 0;
				cout << "Total inflicted damage: " << damage << endl;
				cout << "Defender's strength points: " << c1->getStrength() << endl << endl;
				
				// check if fighter 1 was killed
				if (c1->getStrength() <= 0)
				{
					c2->finalWords();
					cout << "Players 1's " << c1->getName() << " has been defeated in " << round << " rounds." << endl << endl;
					bothAlive = false;
				}
				cout << "******************************************************************************" << endl;
				round++;
			}

			// alternate turns	
			turn = 1 - turn;
			
		}
		
		// free the memory
		delete c1;
		delete c2;
	
		// prompt user if they want to play again or exit
		playAgain = endMenu();
	}

	return 0;
}

void startMenu()
{
	cout << "Welcome to the Battle Royale" << endl << endl;
	
	cout << "Please choose two characters to battle each other: " << endl << endl;

	cout << "   1. Barbarian" << endl;
	cout << "   2. Blue Men" << endl;
	cout << "   3. Harry Potter" << endl;
	cout << "   4. Medusa" << endl;
	cout << "   5. Vampire" << endl << endl;
}

int getFighter(int num)
{
	int character;
	// get user input for fighter 1 and validate
	cout << "Fighter " << num << ": ";
	std::string userInput;
	do {
		getline(cin, userInput, '\n');
		if (integerValidation(userInput, false)){
			character = std::stoi(userInput);	
		}
		else if(!(integerValidation(userInput, false)) || character < 1 || character > 5)
			cout << endl << "Invalid entry.  Please select one of the five characters by entering an integer between 1 and 5." << endl << endl;
	}
	while (!(integerValidation(userInput, false)) || character < 1 || character > 5);

	return character;
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

int endMenu()
{
	int input;
	cout << endl << "Please choose from the following options: " << endl << endl;

	cout << "   1. Play again" << endl;
	cout << "   2. Exit the game" << endl;

	std::string userInput;
	do {
		getline(cin, userInput, '\n');
		if (integerValidation(userInput, false)){
			input = std::stoi(userInput);	
		}
		else if(!(integerValidation(userInput, false)) || input < 1 || input > 2)
			cout << endl << "Invalid entry.  Please enter 1 to play or 2 to exit." << endl << endl;
	}
	while (!(integerValidation(userInput, false)) || input < 1 || input > 2);
	
	return input;
}




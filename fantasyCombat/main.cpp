#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "queue.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "bluemen.hpp"
#include "hpotter.hpp"

using std::cout;
using std::endl;
using std::cin;

void battle(Queue*, Queue*, Queue*);
void getFighters(Queue*, int);
void displayScore(Queue*, Queue*, int, int);
int menuChoice();
void losersQueue(Queue*);
int integerValidation(std::string, bool);
void displayGraphic(std::string);
void clrscrn();  // linux clear screen
int teamCount = 1;

int main()
{
	int replay, numFighters1, numFighters2;
	srand(time(NULL));
	displayGraphic("fantasyCombatTitle.txt");
	if(menuChoice())
	{
		do 
		{
			Queue* team1 = new Queue;
			Queue* team2 = new Queue;
			Queue* losers = new Queue;	
		
			cout << endl <<  "FANTASY COMBAT GAME INITIATED!" << endl;
			cout << "How many fighters on team 1? ";
			cin >> numFighters1;
			cout << "How many fighters on team 2? ";
			cin >> numFighters2;
			cin.clear();
			cin.ignore(256, '\n');
			getFighters(team1, numFighters1);
			getFighters(team2, numFighters2);

			team1->printQueue();
			team2->printQueue();

			battle(team1, team2, losers);
			
			displayGraphic("combatReplay.txt");
			replay = menuChoice();
			
		} while (replay);
	}	

	return 0;
}


void battle(Queue* team1, Queue* team2, Queue* losers)
{
	displayGraphic("combatPic.txt");
	int score1, score2, fightCount;
	score1 = score2 = 0;
	fightCount = 1;	

	while(!(team1->isEmpty()) && !(team2->isEmpty()))
	{
		int turn = rand() % 2;
		int round = 1;
		bool bothAlive = true;
		Character* c1 = team1->getFront();
		Character* c2 = team2->getFront();
		clrscrn();
		displayGraphic("combatPic.txt");
		cout << "                    FIGHT# " << fightCount << ": " << c1->getName() << " VS. " << c2->getName() << endl << endl; 
		cout << "Team " << (turn + 1) << " has been randomly selected to go first this round" << endl;
		cout << "Special abilities used during this battle: " << endl;
		while(bothAlive)
		{
			if(turn == 0)
			{
				int att = c1->attack();
				int def = c2->defense(att);
				int damage = att - def - c2->getArmor();
				// clamp damage to 0
				if (damage < 0)
					damage = 0;
			
				// check if fighter 2 was killed
				if(c2->getStrength() <= 0)
				{
					cout << endl << "*********************************************************" << endl;
					cout << "Team 1 wins! ";
					c1->finalWords();
					cout << "Team 1's " << c1->getName() << " (" << c1->getType() << ") has defeated " << c2->getName() << " (" << c2->getType() << ") in " << round << " rounds." << endl << endl;
					bothAlive = false;
					// add character back to end of queue.
					team1->addBack(c1);
					// remove both characters from the front of their queues
					team1->removeFront();	
					team2->removeFront();
					// add fighter 2 to the losers queue
					losers->addBack(c2);
					cout << "Remaining Team 1 Fighters: ";
					team1->printQueue();
					cout << "Remaining Team 2 Fighters: ";
					team2->printQueue();
						
					// recovery
					if(!(team2->isEmpty()))
					{
						cout << endl;
						c1->recovery();
					}
	
					// change scores
					score1 += 2;
					score2 -= 1;
					
					cout << "Press any key to go to the next round" << endl;
					getchar();
					break;
				}
			}
			else
			{	
				int att = c2->attack();
				int def = c1->defense(att);
				int damage = att - def - c1->getArmor();
				// clamp damage to 0
				if (damage < 0)
					damage = 0;
			
				// check if fighter 2 was killed
				if(c1->getStrength() <= 0)
				{
					cout << endl << "*********************************************************" << endl;
					cout << "Team 2 wins! ";
					c2->finalWords();
					cout << "Team 2's " << c2->getName() << " (" << c2->getType() << ") has defeated " << c1->getName() << " (" << c1->getType() << ") in " << round << " rounds." << endl << endl;
					bothAlive = false;
					// add character back to end of queue.
					team2->addBack(c2);
					// remove both characters from the front of their queues
					team1->removeFront();	
					team2->removeFront();
					// add fighter 2 to the losers queue
					losers->addBack(c1);
					cout << "Remaining Team 1 Fighters: ";
					team1->printQueue();
					cout <<"Remaining Team 2 Fighters: ";
					team2->printQueue();
				
					// recovery
					if(!(team1->isEmpty()))	
					{
						cout << endl;
						c2->recovery();
					}
						
					// change scores
					score2 += 2;
					score1 -= 1;
 
					cout << "Press any key to go to the next round" << endl;
					getchar();
					break;
				}
				
				// increment round
				round++;	
			}

			// alternate turns
			turn = 1 - turn;
		}
		fightCount++;
	}
		
	// game over. display the score
	displayScore(team1, team2, score1, score2);
	
	// prompt user if they want to see the losers queue	
	losersQueue(losers);	

	// press any key to continue  
	cout << "THE TOURNAMENT IS OVER." << endl;
	cout << "Press any key to continue" << endl;
	getchar();
	getchar();
}

void displayScore(Queue* team1, Queue* team2, int score1, int score2)
{
	clrscrn();
	displayGraphic("combatEnd.txt");
	
	if (score1 > score2)
	{
		cout << "                  TEAM 1 WINS BY A SCORE OF " << score1 << " TO " << score2 << endl << endl;
		cout << "Surviving Team 1 members: ";
		team1->printQueue();
		cout << "Surviving Team 2 members: ";
		team2->printQueue();
	}
	else if (score2 > score1)
	{
		cout << "                   TEAM 2 WINS BY A SCORE OF " << score2 << " TO " << score1 << endl <<endl;
		cout << "Surviving Team 1 members: ";
		team1->printQueue();
		cout << "Surviving Team 2 members: ";
		team2->printQueue();
	}
	else
	{
		cout << "The fight ended in a tie. Team 1: " << score1 << "  Team 2: " << score2 << endl; 
	}
}


void losersQueue(Queue* losers)
{
	char choice;
	cout << endl << "Would you like to see the losers queue? (Y/N) ";
	cin >> choice;
	cout << "choice: " << choice << endl;
	while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invaled entry. Would you like to see the losers queue? (y/n) ";
		cin >> choice;
	}

	if (choice == 'y' || choice == 'Y')
	{
		losers->printLosers();
	}
}

void displayGraphic(std::string str)
{
	clrscrn();
	
	std::ifstream Graphic(str);
	std::string displayLine = "";

	if(Graphic)
	{
		while(getline(Graphic, displayLine))
		{
			cout << displayLine << endl;
		}
	}

	Graphic.close();
}

int menuChoice()
{
	int menuChoice;

	
	std::string userInput;
	do {
		getline(cin, userInput, '\n');
		if (integerValidation(userInput, false)){
			menuChoice = std::stoi(userInput);	
		}
		else if(!(integerValidation(userInput, false)) || menuChoice < 1 || menuChoice > 2)
			cout << endl << "Invalid entry.  Please enter 1 to play or 2 to exit." << endl << endl;
	}
	while (!(integerValidation(userInput, false)) || menuChoice < 1 || menuChoice > 2);

	if(menuChoice == 1)
		return 1;
	else
		return 0;
}


void getFighters(Queue* que, int numFighters)
{
	for (int i = 0; i < numFighters; i++)
	{
		cout << endl << "Team " << teamCount << ": Fighter " << i + 1 << endl;	
		cout << "Choose a character from the following options: " << endl << endl;

		cout << "   1. Barbarian" << endl;
		cout << "   2. Blue Men" << endl;
		cout << "   3. Harry Potter" << endl;
		cout << "   4. Medusa" << endl;
		cout << "   5. Vampire" << endl << endl;

		int fighter;
		cout <<"Fighter " << i + 1  << " type: ";
		std::string userInput;
		do 
		{
			getline(cin, userInput, '\n');
			if (integerValidation(userInput, false))
			{
				fighter = std::stoi(userInput);	
			}
			else if(!(integerValidation(userInput, false)) || fighter < 1 || fighter > 5)
				cout << endl << "Invalid entry.  Please select one of the five characters by entering an integer between 1 and 5." << endl << endl;
		}
		while (!(integerValidation(userInput, false)) || fighter < 1 || fighter > 5);

		std::string fname;
		cout << "Fighter " << i + 1 << "'s name: ";		
		getline(cin, fname, '\n');
		Character* c1;
		switch(fighter)
		{
		case 1:
			c1 = new Barbarian;
			c1->setName(fname);
			que->addBack(c1);
			break;
		case 2:
			c1 = new Bluemen;
			c1->setName(fname);
			que->addBack(c1);
			break;
		case 3:
			c1 = new Hpotter;
			c1->setName(fname);
			que->addBack(c1);
			break;
		case 4: 
			c1 = new Medusa;
			c1->setName(fname);
			que->addBack(c1);
			break;
		case 5:
			c1 = new Vampire;
			c1->setName(fname);
			que->addBack(c1);
			break;
		default:
			cout << "Error: Invalid input" << endl;
		}
		cout << endl;
	}	
	cout << "*****************************************************" << endl << endl;
	teamCount++;
}

int integerValidation(std::string str, bool negativeAllowed)
{
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
	{
		// check to see if all elements are integers
		for ( unsigned int i = 0; i < str.size( ); i++ ) 
		{
			if ( (int)str[i] < 48 || (int)str[i] > 57 )
				return num;
		}
	}

	// if we haven't returned yet, then we have a valid integer
	num = 1;
	return num;
}

void clrscrn()
{
	// linux clear screeen command
	cout << "\033[2J\033[1;1H";

}

/*int playAgain()
{
	int input;
	cout << endl << "Please choose from the following options: " << endl << endl;

	cout << "   1. Play again" << endl;
	cout << "   2. Exit" << endl;

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
	
	if(input == 1)
		return 1;
	else
		return 0;
	return input;
}*/

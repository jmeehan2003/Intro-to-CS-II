#include <iostream>
#include "vampire.hpp"
//#include "character.hpp"

using std::cout;
using std::endl;

Vampire::Vampire() 
{
	this->name = "Vampire";
	this->attNumDice = 1;
	this->attDiceSides = 12;
	this->defNumDice = 1;
	this->defDiceSides = 6;
	this->armor = 1;
	this->strength = 18;
}

int Vampire::defense(int attack)
{
	// determine if charm will work (50% chance attacker doesn't attack)
	int charm = rand() % 2;

	// if charm worked print out a message and don't change any strength points
	if (charm)
	{
		cout << "The vampire's charm has worked and there was no attack." << endl;
		// return value, when added with armor produces zero damage inflicted for the round
		return attack - armor;
	}
	// otherwise there is an attack and figure out the damage inflicted
	else
	{
		int rollDefense = 0;
		for (int i = 0; i < defNumDice; i++)
		{
			int roll = (rand() % defDiceSides) + 1;
			cout << "Defender Roll " << (i + 1) << ": " << roll << endl;
			rollDefense += roll;
		}

		// add in armor to the roll defense
		int totalDefense = rollDefense + armor;

		// calculate damage inflicted
		int damage = attack - totalDefense;

		// if damage was cause, subtract it from the strength points
		if (damage > 0 )
			strength -= damage;

		return rollDefense;
	}
}	

void Vampire::finalWords()
{
	cout << "You've been drained!" << endl;

}

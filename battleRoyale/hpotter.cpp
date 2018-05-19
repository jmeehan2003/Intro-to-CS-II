#include <iostream>
#include "hpotter.hpp"
using std::cout;
using std::endl;

Hpotter::Hpotter() 
{
	this->name = "Harry Potter";
	this->attNumDice = 2;
	this->attDiceSides = 6;
	this->defNumDice = 2;
	this->defDiceSides = 6;
	this->armor = 0;
	this->strength = 10;
	this->deaths = 0;
}

int Hpotter::defense(int attack)
{
	int rollDefense = 0;
	for (int i = 0; i < defNumDice; i++)
	{
		int roll = (rand() % defDiceSides) + 1;
		cout << "Defender roll " << (i + 1) << ": " << roll << endl;
		rollDefense += roll;
	}

	// add armor to roll defense
	int totalDefense = rollDefense + armor;
	
	// calculate inflicted damage
	int damage = attack - totalDefense;

	// if damage cause, subtract from character's strength poitns
	if (damage > 0)
		strength -= damage;

	if (strength <= 0 && deaths == 0)
	{
		// first time harry potter dies, he comes back with 20 strength points
		cout << "Harry Potter has used the power of hogwarts to come back to life and this time he's stronger.  Don't mess with a wizard!" << endl;
		strength = 20;
		deaths = 1;
	}

	return rollDefense;
}

void Hpotter::finalWords()
{
	cout << "Harry Potter has smote you!" << endl;
}

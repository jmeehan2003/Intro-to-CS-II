#include <iostream>
#include "bluemen.hpp"
using std::cout;
using std::endl;

Bluemen::Bluemen()
{
	this->type = "Blue Men";
	this->attNumDice = 2;
	this->attDiceSides = 10;
	this->defNumDice = 3;
	this->defDiceSides = 6;
	this->armor = 3;
	this->strength = 12;
	this->startStrength = 12;
}

int Bluemen::defense(int attack)
{
	int startStrength = strength;
	int rollDefense = 0;
	for (int i = 0; i < defNumDice; i++)
	{
		int roll = (rand() % defDiceSides) + 1;
	//	cout << "Defender roll " << (i + 1) << ": " << roll << endl;
		rollDefense += roll;
	}

	// add armor to roll defense
	int totalDefense = rollDefense + armor;
	
	// calculate inflicted damage
	int damage = attack - totalDefense;

	// if damage cause, subtract from character's strength poitns
	if (damage > 0)
		strength -= damage;

	// if bluemen haven't been killed, check to see if mob has weakened
	if (strength > 0)
	{
		if (startStrength > 8 && strength <= 8 && strength > 4)
		{
			defNumDice = 2;
			cout << name << ": The mob has been weakened. The number of defending dice is now 2" << endl;
		}
		else if (startStrength > 4 && strength <= 4)
		{
			defNumDice = 1;
			cout << name << ": The mob has been severely weakened.  The number of defending dice is now 1" << endl;
		}
	}

	return rollDefense;
}

void Bluemen::finalWords()
{
	cout << "Papa Smurf took you out!" << endl;
}

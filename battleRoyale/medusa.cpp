#include <iostream>
#include "medusa.hpp"

using std::cout;
using std::endl;

Medusa::Medusa() 
{
	this->name = "Medusa";
	this->attNumDice = 2;
	this->attDiceSides = 6;
	this->defNumDice = 1;
	this->defDiceSides = 6;
	this->armor = 3;
	this->strength = 8;
}

int Medusa::attack()
{
	int attackDamage = 0;
	for (int i = 0; i < attNumDice; i++)
	{
		int roll = (rand() % attDiceSides) + 1;
		cout << "Attacker roll " << (i + 1) << ": " << roll << endl;
		attackDamage += roll;
	}

	// if Medusa rolls a combined 12, she uses glare and wins	
	if (attackDamage == 12)
	{
		attackDamage = 10000;
		cout << "Medusa has used glare. If successful, you've been turned to stone!" << endl;
	}

	return attackDamage;
}

void Medusa::finalWords()
{
	cout << "Stoned again? Time to find a new hobby" << endl;
}

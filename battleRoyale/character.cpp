#include <iostream>
#include <stdlib.h>
#include "character.hpp"
using std::cout;
using std::endl;

Character::Character()
{
	attNumDice = 0;
	attDiceSides = 0;
	defNumDice = 0;
	defDiceSides = 0;
}


int Character::attack()
{
	int attackDamage = 0;
	for (int i = 0; i < attNumDice; i++)
	{
		int roll = (rand() % attDiceSides) + 1;
		cout << "Attacker roll " << (i + 1) << ": " << roll << endl; 
		attackDamage += roll;
	}
	
	return attackDamage;

}

int Character::defense(int attack)
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

	return rollDefense;
}

//Character::~Character(){};

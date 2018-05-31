#include <iostream>
#include "barbarian.hpp"
using std::cout;
using std::endl;

Barbarian::Barbarian() 
{
	this->type = "Barbarian";
	this->attNumDice = 2;
	this->attDiceSides = 6;
	this->defNumDice = 2;
	this->defDiceSides = 6;
	this->armor = 0;
	this->strength = 12;
	this->startStrength = 12;
}

void Barbarian::finalWords()
{
	cout << "Grunt.. Grunt.. I lift people up and tear them apart.. Grunt." << endl;
}

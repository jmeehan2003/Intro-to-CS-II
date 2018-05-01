#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	int age;
	int cost;
	int numberOfBabies;
	int baseFoodCost = 50;
	virtual double payoff() = 0;
public:
	int getAge() { return this->age; };
	int getCost() { return this->cost; };
	int getNumberOfBabies() { return this->numberOfBabies; };
	int getBaseFoodCost() { return this->baseFoodCost; };
	void incrementAge() { this->age++; };	
};

#endif

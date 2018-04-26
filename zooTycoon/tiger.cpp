#include <iostream>
#include "tiger.hpp"

Tiger::Tiger() {
	this->age = 3;
	this->cost = 10000;
	this->numberOfBabies = 1;
	this->baseFoodCost = baseFoodCost * 5;	
}

Tiger::Tiger(int age) {
	this->age = age;
	this->cost = 10000;
	this->numberOfBabies = 1;
	this->baseFoodCost = baseFoodCost * 5;
}

double Tiger::payoff() {
	return this->cost * 0.20;
}




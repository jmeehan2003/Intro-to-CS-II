#include <iostream>
#include "penguin.hpp"

Penguin::Penguin() {
	this->age = 3;
	this->cost = 1000;
	this->numberOfBabies = 5;
	this->baseFoodCost = baseFoodCost;	

}
Penguin::Penguin(int age) {
	this->age = age;
	this->cost = 1000;
	this->numberOfBabies = 5;
	this->baseFoodCost = baseFoodCost;	
}
double Penguin::payoff() {
	return this->cost * 0.10;
}

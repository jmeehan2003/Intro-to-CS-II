#include <iostream>
#include "turtle.hpp"

Turtle::Turtle() {
	this->age = 3;
	this->cost = 100;
	this->numberOfBabies = 10;
	this->baseFoodCost = baseFoodCost * 0.50;	
}

Turtle::Turtle(int age) {
	this->age = age;
	this->cost = 100;
	this->numberOfBabies = 10;
	this->baseFoodCost = baseFoodCost * 0.50;	
}
double Turtle::payoff() {
	return this->cost * 0.05;
}

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include <iostream>
#include "animal.hpp"

class Turtle : public Animal {
public:
	Turtle();
	Turtle(int age);
	double payoff();
};

#endif 

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include <iostream>
#include "animal.hpp"

class Penguin : public Animal {
public:
	Penguin();
	Penguin(int age);
	double payoff();
};

#endif 

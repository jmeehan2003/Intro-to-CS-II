#ifndef TIGER_HPP
#define TIGER_HPP

#include <iostream>
#include "animal.hpp"

class Tiger : public Animal {
private:

public:
	Tiger();
	Tiger(int);
	double payoff();
};

#endif 

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class Medusa : public Character 
{
private:
	
public:
	Medusa();
	int attack() override;
	void finalWords() override;
	virtual ~Medusa(){};
};

#endif

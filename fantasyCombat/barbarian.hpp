#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character 
{
private:
	
public:
	Barbarian();
	void finalWords() override;
	virtual ~Barbarian(){};
};

#endif

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character 
{
private:
	bool charm;
	
public:
	Vampire();
	int defense(int) override;
	void finalWords() override;
	virtual ~Vampire(){};

};

#endif

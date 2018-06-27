#ifndef HPOTTER_HPP
#define HPOTTER_HPP

#include "character.hpp"

class Hpotter : public Character 
{
private:
	int deaths;
	
public:
	Hpotter();
	int defense(int) override;
	void finalWords() override;
	virtual ~Hpotter(){};

};

#endif

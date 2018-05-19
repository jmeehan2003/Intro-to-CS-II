#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class Bluemen : public Character 
{
private:
	bool charm;
	
public:
	Bluemen();
	int defense(int) override;
	void finalWords() override;
	virtual ~Bluemen(){};

};

#endif

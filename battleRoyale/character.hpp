#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
protected:
	std::string name;
	int attNumDice;
	int attDiceSides;
	int defNumDice;
	int defDiceSides;
	int armor;
	int strength;
public:
	Character();
	virtual ~Character(){};
	virtual int attack();
	virtual int defense(int);
	virtual void finalWords() = 0;
	std::string getName() { return this->name; };
	int getStrength() { return this->strength; };
	int getArmor() { return this->armor; };
};

#endif

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
	int startStrength;
	int strength;
	std::string type;
public:
	Character();
	virtual ~Character(){};
	virtual int attack();
	virtual int defense(int);
	virtual void finalWords() = 0;
	void recovery();
	void setName(std::string name) { this->name = name; };
	void setStrength(int strength) { this->strength = strength; };
	std::string getName() { return this->name; };
	int getStrength() { return this->strength; };
	int getArmor() { return this->armor; };
	std::string getType() { return this->type; };
};

#endif

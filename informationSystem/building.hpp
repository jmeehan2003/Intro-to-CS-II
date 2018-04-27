#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>

class Building {
private:
	std::string name;
	int size;
	std::string address;
public:
	Building(){};
	Building(std::string name) { this->name = name; };
	Building(std::string name, int size, std::string addr) 
		{ this->name = name; this->size = size; this->address = addr; };
	void setName(std::string name) { this->name = name; };
	std::string getName() { return this->name; };
	void setSize(int size) { this->size = size; };
	int getSize() { return this->size; };
	void setAddress(std::string addr) { this->address = addr; };
	std::string getAddress() { return this->address; };
};

#endif

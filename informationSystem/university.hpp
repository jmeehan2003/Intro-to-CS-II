#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <iostream>
#include <string>
#include <vector>
#include "person.hpp"
#include "building.hpp"

class University {
private:
	std::string name;
	std::vector<Building> buildings;
	std::vector<Person*> people;	
public:
	University() { this->name = "Oregon State University"; };
	std::string getName() { return name; };
	void addBuilding(Building &b) { buildings.push_back(b); };
	void addPerson(Person* p) { people.push_back(p); };
	void printBuildings();
	void printPeople();
	void printNames();

};

#endif

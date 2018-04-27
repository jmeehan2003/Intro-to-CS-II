#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <iostream>
#include <string>
#include "person.hpp"

class Instructor : public Person {
private:
	double rating;
public:
	Instructor();
	Instructor(std::string name);
	void setRating(double);
	double getRating() { return this->rating; };
	void setName(std::string iname) { this->name = iname; };
	std::string getName() { return this->name; };
	void setAge(int);
	int getAge() { return this->age; };
	void do_work();
	void status();
};

#endif

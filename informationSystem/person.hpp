#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

class Person {
protected:
	std::string name;
	int age;
public:
	Person(){};
	int getAge() { return this->age; };
	std::string getName() { return this->name; };
	virtual void do_work() { int work = rand() % 120; cout << name << "did " << work << "hours of work." << endl;};
	virtual void status() { cout << "I am just a person" << endl;}
};

#endif

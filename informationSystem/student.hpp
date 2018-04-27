#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include "person.hpp"

class Student : public Person {
private:
	double GPA;
public:
	Student();
	Student(std::string name);
	void setGPA(double);
	double getGPA() { return this->GPA; };
	void setAge(int);
	void setName(std::string sname) { this->name = sname; };	
	void do_work();
	void status();
};

#endif

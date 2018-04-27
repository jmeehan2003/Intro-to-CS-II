#include <iostream>
#include <cstdlib>
#include "student.hpp"
using std::cout;
using std::endl;
using std::string;
using std::cin;

Student::Student() {
	// get random student age between 18 and 40
	this->age = (rand() % 22 + 18);
	this->GPA = rand() % 5;
}

Student::Student(std::string sname) {
	// get random student age between 18 and 40
	this->age = (rand() % 22 + 18);
	this->name = sname;
	this->GPA = rand() % 5;
}

void Student::do_work() {
	int homework = rand() % 120;
	cout << name << " did " << homework << " hours of homework" << endl;
}

void Student::status() {
	cout << "Student.  GPA: " << GPA << endl;
}

void Student::setGPA(double gpa) {
	if (gpa <= 5.0 && gpa >= 0.0) 
		this->GPA = gpa;
	else {
		double newGpa;
		do {
			cout << "GPA must be between 0.0 and 4.0." << endl;
			cout << "Please enter the student's GPA: ";
			cin >> newGpa;
		} while (cin.fail() || newGpa > 4.0 || newGpa < 0.0);
		this->GPA = newGpa;
	}
}

void Student::setAge(int age) {
	if (age < 50 && age > 17) 
		this->age = age;
	else {
		double newAge;
		do {
			cout << "Student age must be between 25 and 100" << endl;
			cout << "Please enter the instructor's age: ";
			cin >> newAge;
		} while (cin.fail() || newAge > 50 || age < 18);
		this->age = newAge;
	}
}

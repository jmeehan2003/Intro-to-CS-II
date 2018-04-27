#include <iostream>
#include <cstdlib>
#include "instructor.hpp"
using std::cout;
using std::endl;
using std::cin;

Instructor::Instructor() {
	// set age at a random number b/n 25 and 75
	this->age = rand() % 50 + 25;
	this->rating = rand() % 6;
}

Instructor::Instructor(std::string iname) {
	// set age at a random number b/n 25 and 75
	this->age = rand() % 50 + 25;
	this->name = iname;
	this->rating = rand() % 6;
}

void Instructor::setRating(double rating) {
	if (rating <= 5.0 && rating >= 0.0) 
		this->rating = rating;
	else {
		double newRating;
		do {
			cout << "Rating must be between 0.0 and 5.0." << endl;
			cout << "Please enter the instructor's rating: ";
			cin >> newRating;
		} while (cin.fail() || newRating > 5.0 || newRating < 0.0);
		this->rating = newRating;
	}
}

void Instructor::setAge(int age) {
	if (age < 101 && age > 25) 
		this->age = age;
	else {
		double newAge;
		do {
			cout << "Instructor age must be between 25 and 100" << endl;
			cout << "Please enter the instructor's age: ";
			cin >> newAge;
		} while (cin.fail() || newAge > 100 || newAge < 25);
		this->age = newAge;
	}
}

void Instructor::do_work() {
	int grading = rand() % 120;
	cout << name << " graded papers for " << grading << " hours." << endl;
}

void Instructor::status() {
	cout << "Instructor.  Rating: " << rating << endl;
}

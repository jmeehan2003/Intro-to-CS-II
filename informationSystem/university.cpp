#include <iostream>
#include "university.hpp"
using std::cout;
using std::endl;
using std::cin;

void University::printBuildings() {
	cout << std::string(100, '\n');
	cout <<  std::string(100, '*') << endl;
	int size = buildings.size();
	cout << "Information for all buildings at " << name << endl;
	for (int i = 0; i < size; i++) {
		cout << "Details for            : " << buildings[i].getName() << endl;
		cout << "Building size (sq ft.) : " << buildings[i].getSize() << endl;	
		cout << "Address                : " << buildings[i].getAddress() << endl << endl;
	}
	cout <<std::string(100, '*') << endl;
	cout << "Press any key to return to the Main Menu. " << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
}

void University::printPeople() {
	cout << std::string(100, '\n');
	cout <<  std::string(100, '*') << endl;
	int size = people.size();
	for (int i = 0; i < size; i++) {
		cout << "Details for : " << people[i]->getName() << endl;
		cout << "Age         : " << people[i]->getAge() << endl;	
		cout << "Status      : ";
		people[i]->status();
		cout  << endl;
	}
	cout <<std::string(100, '*') << endl;
	cout << "Press any key to return to the Main Menu. " << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
}

void University::printNames() {
	int person;
	int size = people.size();
	cout << "size: " << size << endl;
	cout << std::string(100, '\n');
	cout <<  std::string(100, '*') << endl;
	for (int i = 0; i < size; i++) {
		cout << (i+1) << ".  " <<  people[i]->getName() << endl;
	}
	cout <<  std::string(100, '*') << endl;
	
	cout << "Please select the number that corresponds with the person you would like to do work: ";
	cin >> person;
	
	while (cin.fail() || person < 1 || person > size) {
		cout << "You did not select a valid option. Please select the number that corresponds with the person you would like to do work: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> person;
	}
	cout << endl;
	people[person-1]->do_work();
	cout << endl << "Press any key to return to the Main Menu. " << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
}

University::~University() {
//	for (size_t i = 4; i < people.size(); i++) 
//		delete people[i];
}

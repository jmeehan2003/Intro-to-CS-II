#include <iostream>
#include <cstdlib>
#include <ctime>
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "building.hpp"
#include "university.hpp"
using std::cout;
using std::endl;
using std::cin;

void menu(University);

int main(){
	srand(time(0));

	University OSU;
	//*** hard code student / building data ***
	Person *pptr;
	Student s1("Alysha Martin");
	s1.setGPA(3.5);
	pptr = &s1;
	OSU.addPerson(pptr);
	
	Instructor i1("Pete McGill");
	i1.setRating(3.0);
	pptr = &i1;
	OSU.addPerson(pptr);
	
	Student s2("Denis Hall");
	pptr = &s2;
	OSU.addPerson(pptr);

	Instructor i2("Luyao Wolford");
	pptr = &i2;
	OSU.addPerson(pptr);

	Building b1("Adams Hall", 11168, "606 SW 15th Street");
	Building b2("Beef Pole Barn", 1080, "3550 Campus Way");
	Building b3("Dixon Recreation Center", 173776, "425 SW 26th Street");
	Building b4("Dairy Barn Milking Parler",3817 , "4490 Harrison Blvd");
	Building b5("Langton Hall", 95037, "2450 SW Jefferson Way");
	OSU.addBuilding(b1);
	OSU.addBuilding(b2);
	OSU.addBuilding(b4);
	OSU.addBuilding(b3);
	OSU.addBuilding(b5);
	//** end hard coding ***
	
	menu(OSU);
	//OSU.printPeople();
	//cout << '\n';	
	//OSU.printBuildings();

	return 0;
}

void menu(University OSU) {
	int val;
	cout << "Welcome to the Oregon State Information System" << endl << endl;	
	cout << "1.   Display Building Information" << endl;
	cout << "2.   Display Affialiated People Information" << endl;
	cout << "3.   Choose a person to do work" << endl;
	cout << "4.   Add a Building" << endl;
	cout << "5.   Add a Student or Instructor" << endl;
	cout << "6.   Exit the Program" << endl << endl;
	cout << "Please select your option: ";
	cin >> val;
	
	while (cin.fail() || val < 1 || val > 6) {
	cout << "Invalid Option: Please select the number that corresponds with your selection." << endl << endl;
	cout << "1.   Display Building Information" << endl;
	cout << "2.   Display Affialiated People Information" << endl;
	cout << "3.   Choose a person to do work" << endl;
	cout << "4.   Add a Building" << endl;
	cout << "5.   Add a Student or Instructor" << endl;
	cout << "6.   Exit the Program" << endl << endl;
	cout << "Please select your option: ";
	cin.clear();
	cin.ignore(245, '\n');
	cin >> val;
	}

	// perform selected action
	if (val == 1)
		OSU.printBuildings();
	else if (val == 2)
		OSU.printPeople();
	else if (val == 3) {
		OSU.printNames();		
	}
	else if (val == 4) {
		std::string name, addr;
		int size;
		cout << "What is the name of the building? ";
		cin.ignore();
		getline(cin, name);
		cout << "How big is " << name << "? ";
		cin >> size;
		cout << "What is the address of " << name <<"? ";
		cin.ignore();
		getline(cin, addr);
		Building newBuild(name, size, addr);
		OSU.addBuilding(newBuild);
	}
	else if (val == 5) {
		Person* pptr;
		char response;
		std::string name;
		cout << "Would you like to add a student? (y/n)" << endl;
		cin >> response;
		response = tolower(response);
		if (response == 'y') {
			cout << "What is the student's name? ";
			cin.ignore();
			getline(cin, name);
			pptr = new Student(name);
			OSU.addPerson(pptr);
			cout << "Student " << name << " added." << endl;
		}
		else {
			cout << "Would you like to add an instructor? (y/n)" << endl;
			cin >> response;
			response = tolower(response);
			if (response == 'y') {
				cout << "What is the instructor's name? ";
				cin.ignore();
				getline(cin,  name);
				pptr = new Instructor(name);
				OSU.addPerson(pptr);
				cout << "Instructor " << name << " added." << endl;
			}
		}

	}
	else if (val == 6)
		return;

		menu(OSU);


}



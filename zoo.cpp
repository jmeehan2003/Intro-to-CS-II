#include <iostream>
#include "zoo.hpp"

Zoo::Zoo() {
	this->tmax = 10;
	this->pmax = 10;
	this->turmax = 10;
	this->numTigers = 0;
	this->numPenguins = 0;
	this->numTurtles = 0;
	tarr = new Tiger[tmax];
	parr = new Penguin[pmax];
	turarr = new Turtle[turmax];
}

void Zoo::addTiger(int age) {
	// if tiger can fit in array
	if (numTigers < tmax) {
		Tiger t1(age);
		tarr[numTigers] = t1;
		this->numTigers++;
	}
	// double the size of the array
	else {
		tmax *= 2;
	 	Tiger* temp = new Tiger[tmax];
		for (int i = 0; i < numTigers; i++) {
			temp[i] = tarr[i];
		}
		delete [] tarr;
		tarr = temp;
	}

}

void Zoo::addPenguin(int age) {
	// if penguin can fit in array
	if (numPenguins < pmax) {
		Penguin p1(age);
		parr[numPenguins] = p1;
		this->numPenguins++;
	}
	// double the size of the array
	else {
		pmax *= 2;
	 	Penguin* temp = new Penguin[pmax];
		for (int i = 0; i < numPenguins; i++) {
			temp[i] = parr[i];
		}
		delete [] parr;
		parr = temp;
	}
}

void Zoo::addTurtle(int age) {
	// if turtle can fit in array
	if (numTurtles < turmax) {
		Turtle tur1(age);
		turarr[numTurtles] = tur1;
		this->numTurtles++;
	}
	// double the size of the array	
	else {
		turmax *= 2;
	 	Turtle* temp = new Turtle[turmax];
		for (int i = 0; i < numTurtles; i++) {
			temp[i] = turarr[i];
		}
		delete [] turarr;
		turarr = temp;
	}
}

void Zoo::ageTigers() {
	for (int i = 0; i < numTigers; i++)
		tarr[i].incrementAge();
}

void Zoo::agePenguins() {
	for (int i = 0; i < numPenguins; i++)
		parr[i].incrementAge();
}

void Zoo::ageTurtles() {
	for (int i = 0; i < numTurtles; i++)
		turarr[i].incrementAge();
}	

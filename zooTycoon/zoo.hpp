#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

class Zoo {
protected:
	int tmax;
	int pmax;
	int turmax;
	int numTigers;
	int numPenguins;
	int numTurtles;

public:
	Zoo();
	~Zoo();
	Tiger* tarr;
	Penguin* parr;
	Turtle* turarr;
	void addTiger(int age);
	void addPenguin(int age);
	void addTurtle(int age);
	int getNumTigers() { return numTigers; };
	int getNumPenguins() { return numPenguins; };
	int getNumTurtles() { return numTurtles; };
	void ageTigers();
	void agePenguins();
	void ageTurtles();
	void reduceTigers() { numTigers--; };
	void reducePenguins() { numPenguins--; };
	void reduceTurtles() { numTurtles--; };
};

#endif

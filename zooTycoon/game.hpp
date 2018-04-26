#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "zoo.hpp"
#include "tiger.hpp"
#include "penguin.hpp"

class Game {
private:
	int days;
	int balance;
	int bonus;
	Zoo zoo;
public:
	Game();
	int getDays() { return this->days; };
	int getBalance() { return this->balance; };
 	void randomEvent();	
	void purchaseTiger(int age);
	void purchasePenguin(int age);
	void purchaseTurtle(int age);
	void addTiger(int age);
	void addPenguin(int age);
	void addTurtle(int age);
	int getNumTigers();
	int getNumPenguins();
	int getNumTurtles();
	void tigerBonus();
	void sickAnimal();
	void animalBirth();
	void setUp();
	void beginDay();
	int endDay();
};

#endif

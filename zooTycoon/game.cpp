#include <iostream>
#include "game.hpp"
using std::cout;
using std::endl;
using std::cin;

Game::Game() {
	this->days = 0;
	this->balance = 50000;
	this->bonus = 0;
}

void Game::purchaseTiger(int age) {
	zoo.addTiger(age);
	balance -= zoo.tarr[0].getCost();
}

void Game::addTiger(int age) {
	zoo.addTiger(age);
}
void Game::purchasePenguin(int age) {
	zoo.addPenguin(age);
	balance -= zoo.parr[0].getCost();
}

void Game::addPenguin(int age) {
	zoo.addPenguin(age);
}

void Game::purchaseTurtle(int age) {
	zoo.addTurtle(age);
	balance -= zoo.turarr[0].getCost();
}

void Game::addTurtle(int age) {
	zoo.addTurtle(age);
}

int Game::getNumTigers() {
	return zoo.getNumTigers();
}

int Game::getNumPenguins() {
	return zoo.getNumPenguins();
}

int Game::getNumTurtles() {
	return zoo.getNumTurtles();
}
void Game::randomEvent() {
	cout << std::string(100, '*') << endl;
	cout << "DAILY BULLETIN: " << endl;
	int random = rand() % 4;
	if (random == 0) {
		sickAnimal();
	}
	else if (random == 1)
		tigerBonus();
	else if (random == 2)
		animalBirth();
	else if (random ==3) {
		cout << "Nothing eventful happended today" << endl;
	}
	cout << std::string(100, '*');

}

void Game::tigerBonus() {
	bonus = rand() % 250 + 250;
	
	int message = rand() % 2;
	if (message == 0) {
		cout << "Today is National Tiger Day! Tigers generate more money today.  You'll make an extra $" << bonus << " for each tiger you own!" << endl;
	}
	else
		cout << "Oprah featured one of your tigers on her show.  Tigers generate more money today.  You'll make an extra $" << bonus << " for each tiger you own!" << endl;
}

void Game::sickAnimal() {
	bool animalFound = false;
	int counter = 0;
	int randomAnim = rand() % 3;
	while (!animalFound && counter < 3){
		if (randomAnim == 0) {
			if (getNumTigers() > 0 ) {
				cout << "Oh no!  A tiger was impaled trying to escape and died." << endl;
				zoo.reduceTigers();
				cout << "You now have " << getNumTigers() << " tigers" << endl;
				animalFound = true;
			}
			else {
				randomAnim += 1;	
				counter++;
			}
		}
		if (randomAnim == 1) {
			if (getNumPenguins() > 0 ) {
				cout << "Oh no!  A penguin waddled off a cliff and died." << endl;
				zoo.reducePenguins();
				cout << "You now have " << getNumPenguins() << " penguins" << endl;
				animalFound = true;
			}
			else {
				randomAnim += 1;
				counter++;
			}	
		}
		if (randomAnim == 2) {
			if (getNumTurtles() > 0 ) {
				cout << "Oh no!  Putting the turtle in the tiger pen was a bad idea. It has been eaten." << endl;
				zoo.reduceTurtles();
				cout << "You now have " << getNumTurtles() << " turtles" << endl;
				animalFound = true;
			}
			else {
				randomAnim = 0;	
				counter++;
			}
		}
	}

	if (counter >= 3)
		cout << "The conditions at the zoo at horrendous.  If you had any animals, one would have died today." << endl;

}

void Game::animalBirth() {
	bool motherFound = false;
	int counter = 0;
	int randomAnim = rand() % 3;
	while (!motherFound && counter < 3){
		// if randomAnim is 0, then check to see if there any any tigers in the zoo
		if (randomAnim == 0 && getNumTigers() > 0) {
			// iterate through tiger array to see if there are any adults
			for (int i = 0; i < getNumTigers(); i++) {
				// if there is an adult, add the babies to the tiger array and end the while loop
				if (zoo.tarr[i].getAge() >= 3) {
					motherFound = true;
					for (int j = 0; j < zoo.tarr[i].getNumberOfBabies(); j++){
						addTiger(0);	
					}
					cout << "Congratulations! Momma tiger just had " << zoo.tarr[0].getNumberOfBabies() << " baby." << endl;
					return;
				}
			}
		}
		// if randomAnim is 1, then check to see if there are any penguins in the zoo
		if (randomAnim == 1 && getNumPenguins() > 0) {
			// iterate through tiger array to see if there are any adults
			for (int i = 0; i < getNumPenguins(); i++) {
				// if there is an adult, add the babies to the tiger array and end the while loop
				if (zoo.parr[i].getAge() >= 3) {
					motherFound = true;
					for (int j = 0; j < zoo.parr[i].getNumberOfBabies(); j++){
						addPenguin(0);	
					}
					cout << "Congratulations! Momma penguin just had " << zoo.parr[0].getNumberOfBabies() << " babies." << endl;
					return;
				}
			}
		}
			
		// if randomAnim is 2, then check to see if there are any turtles in the zoo
		if (randomAnim == 2 && getNumTurtles() > 0) {
			// iterate through tiger array to see if there are any adults
			for (int i = 0; i < getNumTurtles(); i++) {
				// if there is an adult, add the babies to the tiger array and end the while loop
				if (zoo.turarr[i].getAge() >= 3) {
					motherFound = true;
					for (int j = 0; j < zoo.turarr[i].getNumberOfBabies(); j++){
						addTurtle(0);	
					}
					cout << "Congratulations! Momma turtle just had " << zoo.turarr[0].getNumberOfBabies() << " babies." << endl;
					return;
				}
			}
		}
		
		// increment randomAnim and counter in case there were no adults in randomly selected animal
		randomAnim++;
		if (randomAnim >= 2)
			randomAnim = 0;	
		counter++;		
	}

	if (counter >= 3)
		cout << "The condition were perfect for baby making today but no animals are old enough for the funny business." << endl;

}


void Game::setUp() {
	int tigers, penguins, turtles;
	cout << std::string(100, '\n');
	cout << "You have $" << balance << " in your bank account. The availability and price of animals are: " << endl; 
	cout << "             1. Tigers                $10,000" << endl;
	cout << "             2. Penguins               $1,000" << endl;
	cout << "             3. Turtles                  $100" << endl << endl;

	cout << "You must buy either 1 or 2 of each animal to start your zoo." << endl;
	cout << "How many tigers would you like to purchase? ";
	cin >> tigers;
	for (int i = 0; i < tigers; i++) 
		purchaseTiger(1);

	cout << "How many penguins would you like to purchase? ";
	cin >> penguins;
	for (int i = 0; i < penguins; i++) 
		purchasePenguin(1);

	cout << "How many turtles would you like to purchase? ";
	cin >> turtles;
	for (int i = 0; i < turtles; i++) 
		purchaseTurtle(1);
	
	// clear screen
	cout << std::string(100, '\n') << endl;	
}

void Game::beginDay() {
	cout << std::string(100, '*') << endl;
	days++;
	cout << "Today is Day " << days << "!" << endl;
	cout << "You have " << getNumTigers() << " tigers." << endl;	
	cout << "You have " << getNumPenguins() << " penguins." << endl;
	cout << "You have " << getNumTurtles() << " turtles." << endl;

	int feedcost = 0;
	if(getNumTigers()){
		feedcost +=  (getNumTigers() * zoo.tarr[0].getBaseFoodCost());
		zoo.ageTigers();	
	}
	if(getNumPenguins()) {
		feedcost += (getNumPenguins() * zoo.parr[0].getBaseFoodCost());
		zoo.agePenguins();
	}
	if(getNumTurtles()) {
		feedcost += (getNumTurtles() * zoo.turarr[0].getBaseFoodCost());
		zoo.ageTurtles();
	}
	balance -= feedcost;
	cout << "Your feeding costs for the day are $" << feedcost << endl;
	cout << "After deducting feed costs, your balance is $" << balance << endl << endl;  	
}

int Game::endDay() {
	// 10% chance of a no profit day
	int badDay = rand() % 10;
	if (badDay == 0) {
		cout << endl << endl << "Health inspectors shut your zoo down for the day. You earned no money today." << endl;
	}
	else {
		double profit = 0;
		if(getNumTigers()){
			profit += (getNumTigers() * zoo.tarr[0].payoff());
			profit += (getNumTigers() * bonus);
		}
		if(getNumPenguins())
			profit += (getNumPenguins() * zoo.parr[0].payoff());
		if(getNumTurtles())
			profit += (getNumTurtles() * zoo.turarr[0].payoff());

		cout << endl << endl << "Your have made a profit of $" << profit << " from visitors to your zoo" << endl;
		balance += profit;
	}
		cout << "Your balance is now $" << balance << endl;
		cout << std::string(100, '*') << endl;	
	

	// reset bonus to 0
	bonus = 0;

	// end game if player is out of money
	if (balance <= 0) {
		cout << endl << "You've gone bankrupt and lost your zoo to foreclosure.  GAME OVER!" << endl;
		return 0;
	}

	// prompt if user would like to buy another animal 
	int answer;
	cout << "Would you like to purchase another animal for the zoo? Press 1 for yes or 2 for no: ";
	cin >> answer;
	if (answer == 1) {
		int animal;
		cout << "Which animal would you like to purchase? " << endl << endl;
		cout << "             1. Tigers                $10,000" << endl;
		cout << "             2. Penguins               $1,000" << endl;
		cout << "             3. Turtles                  $100" << endl << endl;
		cin >> animal;
		if (animal == 1) {
			purchaseTiger(3);
			cout << "You purchased a tiger!" << endl;
		}
		else if (animal == 2) {
			purchasePenguin(3);
			cout << "You purchased a penguin!" << endl;
		}
		else if(animal == 3) {
			purchaseTurtle(3);
			cout << "Really?  You bought another turtle!?!" << endl;
		}
	}	
	
	cout << "Your end of day balance is $" << balance << endl << endl;
			
	//prompt user is they would like to continue playing
	int playAgain;
	cout << "Would you like to continue playing? Press 1 for yes or 2 for no" << endl;
	cin >> playAgain;
	if (playAgain == 1) {
		cout << std::string(100, '\n') << endl;
		return 1;
	}
	else
		return 0;
}

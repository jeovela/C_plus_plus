/******************
 **Program Name: Animal.cpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the implementation file for the class Animal. It 
 **contains 2 constructors,one of which is the defualt, 5 getter functiions, a
 ** destructor, and 3 member functions. 
*******************/

#include "Zoo.hpp"
#include "Animal.hpp"

#include<iostream>

/****************
 **Description: This is the defualt constructor. All member variables are set to **defaults.
*****************/
Animal::Animal()
{
	age = 0;
	cost = 0;
	numOfBabies = 0;
	baseFoodCost = 0;
	payoff = 0;
}

/***************
 **Description: This is the constructor with the 5 member variables as 
 **parameters: age, cost number of babies, base food cost and the payoff. Using  **this pointer for obj to be assigned.
****************/
Animal::Animal(int age, int cost, int numOfBabies, int baseFoodCost, int payoff)
{
	this->age = age;
	this->cost = cost;
	this->numOfBabies = numOfBabies;
	this->baseFoodCost = baseFoodCost;
	this->payoff = payoff;
}

/*****************
 **Description: This is a copyconstructor. It will initialize an object with th
 **data of another obj that is being initialized.
 ********************/                 
Animal::Animal(const Animal &obj)
{
	age = obj.age;
	cost = obj.cost;
	numOfBabies = obj.numOfBabies;
	baseFoodCost = obj.baseFoodCost;
	payoff = obj.payoff;
}

/****************
 **Description: This is the destructor for the class Animal.
*****************/
Animal::~Animal()
{


}


/****************
 **Description: This is a getter function, returns the age.
****************/
int Animal::getAge()
{
	return age;
}

/****************
**Description: This is a getter function, returns the cost.
****************/
int Animal::getCost()
{
	return cost;
}

/****************
 **Description: This is a getter function, returns the number of babies.
****************/
int Animal::getNumOfBabies()
{
	return numOfBabies;
}

/****************
 **Description: This is a getter function, returns the base food cost.
****************/
int Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

/****************
 **Description: This is a getter function, returns the payoff
****************/
int Animal::getPayoff()
{
	return payoff;
}

/****************
 **Description: This function will add 1 to the age of an animal. 
 **Called in the function addAge() from the class Zoo.
****************/
void Animal::increaseAge()
{
	age++;
}

/*****************
 **Description: This is an operator overload function. 
*****************/
void Animal::operator=(const Animal &obj)
{
	age = obj.age;
        cost = obj.cost;
        numOfBabies = obj.numOfBabies;
        baseFoodCost = obj.baseFoodCost;
        payoff = obj.payoff;
}                

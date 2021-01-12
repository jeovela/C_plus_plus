/************************
 **Program Name: Penguin.cpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the implementation file for the class Penguin. Penguin is a derived class from the
 **Animal class. It contains constructors and a destructor that is not otherwise inherited
 **by the derived class.
 **********************/

#include "Animal.hpp"
#include "Penguin.hpp"

#include <iostream>

/*****************
 **Description: This is the default consructor for the class Penguin.
******************/
Penguin::Penguin()
{


}

/****************
 **Description: This is the constructor for Penguin. It uses a member initializa **tion list allows this constructor to be initialized by the constructor in the **parent/super class Animal. Parameters include: age -which will vary, the cost ** of a penguin - 1000, the number of babies a penguin can have - 5, base food 
 **cost of 1 times base cost and payoff - 100
****************/
Penguin::Penguin(int age) : Animal(age, 1000, 5, 1, 100)
{
        //empty due to member initialization list
        //constructor in Animal class initializes first
}

/****************
 **Description: This is the copy constructor. It will also use member initalization list. Data type
 **not required in the member initialization ().
**************/
Penguin::Penguin(const Penguin &obj) : Animal (obj)
{
	//empty due to member initialization list
}

/***************
 **Description: This is the overloaded assignment function. It calls on the parent class
 **function to be performed.
****************/
void Penguin::operator=(const Penguin &obj)
{
	Animal::operator=(obj);
}

/*************
 **Description: This is the destructor.
*************/
Penguin::~Penguin()
{


}

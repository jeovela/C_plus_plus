/************************
 **Program Name: Turtle.cpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the implementation file for the class Turtle. Turtle is a derived class from the
 **Animal class. It contains constructors and a destructor that is not otherwise inherited
 **by the derived class.
**********************/

#include "Animal.hpp"
#include "Turtle.hpp"

#include <iostream>

/*****************
 **Description: This is the default consructor for the class Turtle.
******************/
Turtle::Turtle()
{


}

/****************
 **Description: This is the constructor for Turtle. It uses a member
 **initialization list allows this constructor to be initialized by the 
 **constructor in the parent/super class Animal. Parameters include: age -which  **will vary, the cost of a turtle - 100, the number of babies a turtle can have - 10, base food cost - 50% off base cost and payoff - 5
****************/
Turtle::Turtle(int age) : Animal(age, 100, 10, 10, 5)
{
	//empty due to member initialization list
	//constructor in Animal class initializes first
}

/****************
 **Description: This is the copy constructor. It will also use member initalization list. Data type
 **not required in the member initialization ().
**************/
Turtle::Turtle(const Turtle &obj) : Animal (obj)
{
	//empty due to member initialization list
}

/***************
 **Description: This is the overloaded assignment function. It calls on the parent class
 **function to be performed.
****************/
void Turtle::operator=(const Turtle &obj)
{
	Animal::operator=(obj);
}

/***************
 **Description: This is the destructor.
***************/
Turtle::~Turtle()
{

}

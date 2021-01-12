/********************
 **Program Name: Tiger.cpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the implementation file for the class Tiger. Tiger is a derived class from the
 **Animal class. It contains constructors and a destructor that is not otherwise inherited
 **by the derived class.
**********************/

#include "Animal.hpp"
#include "Tiger.hpp"

#include <iostream>

/****************
 **Description: This is the default constructor for class Tiger
****************/
Tiger::Tiger()
{
	//nothing placed here
}

/****************
 **Description: This constructor uses member initialization list that allows
 **this constructor to be initialized by the constructor in parent/super class
 **Animal. Parameters include age, which will vary, the cost of a tiger 10000,
 ** number of babies a tiger can have 1, base food cost which is 5x the base 
 **cost(10), and payoff 2000.
****************/
Tiger::Tiger(int age) : Animal (age, 10000, 1, 5, 2000)
{
	//empty due to memeber initialization list
	//constructor in Animal class initializes first
}

/****************
 **Description: This is the copy constructor. It will also use member initalization list. Data type
 **not required in the member initialization ()
 ****************/
Tiger::Tiger(const Tiger &obj) : Animal (obj)
{
	//empty due to member initialization list
}

/****************
 **Description: This is the overloaded assignment function. It calls on the parent class
 **function to be performed.
****************/
void Tiger::operator=(const Tiger &obj)
{
	Animal::operator=(obj);
	
}
/****************
 **Description: This is the destructor.
****************/
Tiger::~Tiger()
{

}                

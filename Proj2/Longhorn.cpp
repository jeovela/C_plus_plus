/*******************
 **Program Name: Longhorn.cpp
 **Author: Jeovani Vela
 **Date 1/25/18
 **Description: This is the implementation file for the class Longhorn. It is
 **a derived class from Animal. It contains constructors and destructor not
 **otherwise inhereited from Animal.
****************/

#include "Animal.hpp"
#include "Longhorn.hpp"

#include <iostream>

/****************
 **Description: This is the deafulat constructor.
**************/
Longhorn::Longhorn()
{


}

/****************
 **Description: This is the constructor for Longhorn. It uses a member 
 **initialization list that allows this constructor to be initialized by the 
 **constructor in the parent/super class Animal. Parameters include: age -which  **will vary, the cost of a Longhorn - 2000, the number of babies a longhorn 
 **can have - 1, base food cost - double base cost and payoff - 1000
****************/
Longhorn::Longhorn(int age) : Animal (age, 5000, 1, 2, 1000)
{
	//empty due to memeber initialization list
	//constructor in Animal class initializes first
}

/****************
 **Description: This is the copy constructor. It will also use member 
 **initalization list. Data type not required in the member initialization ()
 ***************/
Longhorn::Longhorn(const Longhorn &obj) : Animal (obj)
{
        //empty due to member initialization list
}

/***************
 **Description: This is the overloaded assignment function. Calls on
 **parent class.
***************/
void Longhorn::operator=(const Longhorn &obj)
{
	Animal::operator=(obj);
}

/**************
 **Description: This is the destructor.
***************/
Longhorn::~Longhorn()
{


}
   

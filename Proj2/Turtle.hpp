/****************
 **Program Name: Turtle.hpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the specification file for the class Turtle. It is a derived class 
 **from the class Animal.
****************/

#ifndef TURTLE_H
#define TURTLE_H

class Turtle : public Animal
{
	public:
		Turtle(); 	//default constructor
		Turtle(int age);	//constructor
		Turtle(const Turtle&);	//copy constructor
		void operator=(const Turtle&);	//overloaded assignment function
		~Turtle();		//destructor
};
#endif

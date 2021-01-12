/****************
 **Program Name: Longhorn.hpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the specification file for the class Longhorn.
 **It is a dervied class from the class Animal.
*****************/

#ifndef LONGHORN_H
#define LONGHORN_H

class Longhorn : public Animal
{
	public:
		Longhorn();	//defult constructor
		Longhorn(int age);	//constructor
		Longhorn(const Longhorn&);	//copy constructor
		void operator=(const Longhorn&);	//overload assignment
		~Longhorn();	//destructor
};
#endif 

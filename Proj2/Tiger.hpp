/****************
 **Program Name: Tiger.hpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the specification file for the class Tiger. It is a dervied class from
 **the class Animal.
*****************/

#ifndef TIGER_H
#define TIGER_H


class Tiger : public Animal
{
	public:
		Tiger();	//defualt constructor
		Tiger(int age);		//constructor
		Tiger(const Tiger&);	//copy constructor
		void operator=(const Tiger&);	//Overloaded assignment function
		~Tiger();	//destructor
};
#endif

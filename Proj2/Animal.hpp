/*****************
 **Program Name: Animal.hpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the specification file for the class Animal. There are 5 **member variables which were all chosen by Prof. Zhang. YOU MUST NOT ADD
 **NOR MODIFY THE MEMBER VARIABLES FOR THIS CLASS. Most importantly, this class  **will serve as the super class or parent class to the derived classes: Tiger,  **Turtle, Penguin, and Longhorn.
****************/

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
	private:
		int age;
		int cost;
		int numOfBabies;
		int baseFoodCost;
		int payoff;

	public:
		Animal();	//default constructor
		Animal(int, int, int, int, int);
		Animal(const Animal&);	//copy constructor
		~Animal();	//destructor
		//getter functions
		int getAge();
		int getCost();
		int getNumOfBabies();
		int getBaseFoodCost();
		int getPayoff();
		void increaseAge();	
		void operator=(const Animal&);	//opertor overload function
};
#endif




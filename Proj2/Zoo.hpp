/**********************
 **Program Name: Zoo.hpp
 **Author: Jeovani Vela
 **Date: 1/26/18
 **Description: This is the specification file for the class Zoo. 
***********************/

#ifndef ZOO_H
#define ZOO_H

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

class Zoo
{
	private:
		int bank;
		bool boom;
		int day;	//will act as counter. Set at 1	
		int numOfTigers;
		int numOfTurtles;
		int numOfPenguins;
		int numOfLonghorns;
		Animal **animals;
		int feedType;	//will hold the type of feed selected by user
		int feedCost;	//do not confuse with Animal class member

	public:
		Zoo();	//constrcutor
		~Zoo(); //destructor	
		void printStartScreen();
		void startMenu();
		void createAnimal();
		void runDay();	//simulate a day at the zoo	
		void addAge();	//add age to animals
		void animalCount();	//show animal count
		void printDailyBudget();
		void feedingTime();	//feed the animals: base food cost = 20
		void randomEvent();	//must occur after feeding
		void sickAnimal();	//sickness function - animal will die
		void birth();	//birth of an animals
		bool checkTigerAge();//this will check if an animal is of age
		bool checkTurtleAge();
		bool checkPenguinAge();
		bool checkLonghornAge();
		//marker
		void daysPayoff();	//calculate payoff for the day	
		void endOfDay();	//ask user to play agian & buy an animal
		void buyAnimal();	
					
};
#endif

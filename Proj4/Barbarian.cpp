/***********************
 **Program Name: Barbarian.cpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the implementation file for the derived class
 **Barbarian. Its parent class is Character.
**********************/

#include "Character.hpp"
#include "Barbarian.hpp"

#include <iostream>
#include <cstdlib>	//necessary for rand()
#include <string>

using std::cout;
using std::endl;
using std::string;

/*******************
 **Description: This is the constructor for the class Barbarian. Member
 **variables inherited by Character class are assigned the values from 
 **Character spec sheet. Name chosen by user for character set in the Character
 **constructor.
********************/
Barbarian::Barbarian(string newName) : Character(newName)
{
	this->armor = 0;
	this->strengthPoints = 12;
	this->name = "Barbarian";
}

/******************
 **Description: This is the destructor for the derived class Barbarian.
*******************/
Barbarian::~Barbarian()
{
	//empty
}

/**************
 **Description: This is the Barbarian's attack roll. There are 2 die to roll,
 **each is 6-sided.
****************/
int Barbarian::attackRoll()
{
	int roll;
	int attackDie1, attackDie2;	//has two die to roll
	
	attackDie1 = rand() % 6 + 1;	//return a random # between 1-6
	attackDie2 = rand() % 6 + 1;

	//calculate
	roll = attackDie1 + attackDie2;

	/*commenting out the following for Proj4
	cout << "___________\n";
	cout << "|ATTACKING|\n";
	cout << "-----------\n";
	cout << endl;	//spacing
	cout << "The Barbarian rolled " << roll << " attack points!\n";
	cout << endl;	//spacing*/

	return roll;
		
}

/****************
 **Description: This is the Barbarian's defensive roll. There are two die to
 **roll each 6-sided.
****************/
int Barbarian::defenseRoll()
{
	int roll;
	int defenseDie1, defenseDie2;	//has 2 die to roll

	defenseDie1 = rand() % 6 + 1;	//return a random # between 1-6
	defenseDie2 = rand() % 6 + 1;

	//calculate
	roll = defenseDie1 + defenseDie2;

	/*commenting out the following for Proj4
	cout << "___________\n";
	cout << "|DEFENDING|\n";
	cout << "-----------\n";
	cout << endl;	//spacing
	cout << "The Barbarian rolled " << roll << " defensive points!\n";
	cout << "The Barbarian's armor: " << this->getArmor() << endl;
	cout << endl;*/

	return roll;
}

/************************
 **Description: This function determines if the character is dead. 
 **If the character's life is <= 0, he is dead.  Will return bool value.
**************************/
bool Barbarian::isDead()
{
        if(life <= 0)
        {
                return true;
        }
        else
        {
                return false;
        }
}


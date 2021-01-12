/*******************
 **Program Name: blueMen.cpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the implementation file for the derived class
 **Blue Men.
******************/

#include "Character.hpp"
#include "blueMen.hpp"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/********************
 **Description: This is the constructor for the class Blue Men. Member
 **variables inherited by Character class are assigned the values from 
 **the Characted spec sheet. Name selected by user is set in the 
 **Character constructor.
**********************/
BlueMen::BlueMen(string newName) : Character (newName)
{
	this->armor = 3;
	this->strengthPoints = 12;
	this->name = "Blue Men";
}

/******************
 **Description: This is the destructor for the derived class BlueMen.
******************/
BlueMen::~BlueMen()
{
	//empty
}

/****************
 **Description: This is the Blue Men's attack roll. They have
 ** 2 die that are 10-sided to roll.
****************/
int BlueMen::attackRoll()
{
	int roll;
	int attackDie1, attackDie2;	//has 2 die to roll

	attackDie1 = rand() % 10 + 1;	//return a random # between 1-10

	attackDie2 = rand() % 10 + 1;

	//calculate
	roll = attackDie1 + attackDie2;
	
	/*commenting out the follwoing for Proj4
	cout << "___________\n";
        cout << "|ATTACKING|\n";
        cout << "-----------\n";
	cout << endl;	//spacing
	cout << "The Blue Men rolled " << roll << " attack points!\n";
	cout << endl;*/

	return roll;
}

/********************
 **Description: This is the Blue Men's defensive roll. They have 3 die
 **that are 6-sided to roll. They lose one die of defense for every 4 
 **points of damage.
*********************/
int BlueMen::defenseRoll()
{
	int roll;
	int defenseDie1, defenseDie2, defenseDie3; //has 3 die to roll
	
	if(this->getStrengthPoints() >= 9 && this->getStrengthPoints() <= 12)
	{
		defenseDie1 = rand() % 6 + 1;	//return a random # between 1-6
		defenseDie2 = rand() % 6 + 1;
		defenseDie3 = rand() % 6 + 1;

		//calculate
		roll = defenseDie1 + defenseDie2 + defenseDie3;
		
		/*commenting out the following for Proj4	
 		cout << "___________\n";
	        cout << "|DEFENDING|\n";
       		cout << "-----------\n";
		cout << endl;   
	        cout << "The Blue Men rolled " << roll << " defensive points!\n";
        	cout << "The Blue Men's armor: " << this->getArmor() << endl;
		cout << endl;*/

		return roll;
	}

	if(this->getStrengthPoints() >= 5 && this->getStrengthPoints() <= 8)
	{
		defenseDie1 = rand() % 6 + 1;
		defenseDie2 = rand() % 6 + 1;

		//calculate
		roll = defenseDie1 + defenseDie2;

		/*commenting out the following for Proj4		
		cout << "___________\n";
        	cout << "|DEFENDING|\n";
        	cout << "-----------\n";
		cout << endl;   
	        cout << "The Blue Men rolled " << roll << " defensive points!\n";
        	cout << "The Blue Men's armor: " << this->getArmor() << endl;
		cout << endl;*/

		return roll;
	}

	if(this->getStrengthPoints() >= 0 && this->getStrengthPoints() <= 4)
	{
		defenseDie1 = rand() % 6 + 1;

		roll = defenseDie1;	//assign value from defenseDie1 to roll
		
		/*commenting out the following for Proj4
		cout << "___________\n";
        	cout << "|DEFENDING|\n";
	        cout << "-----------\n";		
		cout << endl;
		cout << "The Blue Men rolled " << roll << " defensive points!\n";
		cout << "The Blue Men's armor: " << this->getArmor() << endl;
		cout << endl;*/

		return roll;
	}
}

/*********************
 **Description: This function determines if the character is dead. 
 **If the character's life is <= 0, he is dead.  Will return bool value. 
***********************/
bool BlueMen::isDead()
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


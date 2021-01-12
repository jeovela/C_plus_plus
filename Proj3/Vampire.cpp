/*********************
 **Program Name: Vampire.cpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the implementation file for the derived class
 **Vampire.
***********************/

#include "Character.hpp"
#include "Vampire.hpp"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/******************
 **Description: This is the constructor for the class Vampire. Member
 **variables inherited by Character class are assigned the values from 
 **the Character spec sheet.
*******************/
Vampire::Vampire() : Character()
{
	this->armor = 1;
	this->strengthPoints = 18;
	this->name = "Vampire";
}

/****************
 **Description: This is the destructor for the derived class Vampire.
*****************/
Vampire::~Vampire()
{
	//empty
}

/****************
 **Description: This is the Vampire's attack roll. It has 1 die to roll that 
 **is 12-sided.
*****************/
int Vampire::attackRoll()
{
	int roll;
	int attackDie1;		//only has 1 die to roll


	attackDie1 = rand() % 12 + 1;	//return random # between 1-12

	roll = attackDie1;	//assign value to roll

	cout << "___________\n";
        cout << "|ATTACKING|\n";
        cout << "-----------\n";
	cout << endl;	//spacing
	cout << "The Vampire rolled " << roll << " attack points!\n";
	cout << endl;

	return roll;
}

/*********************
 **Description: This is the Vampire's defensive roll. It has 1 die to roll
 **that is 6 sided. It will also calculate if the Vampire can charm his opponent.
 **If random # between 1-4 equals 2 or 4, the Vampire's charm kicks in (50% chance)
 **and he charms the attacker to not attacking him. Thus, I set his defenseDie roll 
 **to 9999 so it can withstand any attack when the roll value is returned. If the 
 **random # does not equal 2 or 4, the defense roll (defenseDie1) stays some # between
 **1-6. 
********************/
int Vampire::defenseRoll()
{
	int roll;
	int defenseDie1;	//only has 1 die to roll

	defenseDie1 = rand() % 6 + 1;	//return a random # between 1-6

	roll = defenseDie1;	//assign value to roll

	cout << "___________\n";
        cout << "|DEFENDING|\n";
        cout << "-----------\n";
	cout << endl;	//spacing
	cout << "The Vampire rolled " << roll << " defensive points!\n";
	cout << "The Vampire's armor: " << this->getArmor() << endl;
	cout << endl;

	//determine if Vampire's special ability kicks in or not. 50% chance
	int temp;

	temp = rand() % 4 + 1;	//return a random # between 1-4
	
	if(temp == 2 || temp == 4)
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "The Vampire has charmed his attacker!\n";
		cout << "The opponent will not attack when charmed!\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		//set defense roll to 9999 so it can withstand any attack
		roll = 9999;	
	}

	return roll;
}

/********************
 **Description: This function determines if the character is dead. 
 **If the character's life is <= 0, he is dead.  Will return bool value.
**********************/
bool Vampire::isDead()
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


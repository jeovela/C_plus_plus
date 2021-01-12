/*********************
 **Program Name: Character.cpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the implementation file for the class Character.
 **This class will serve as an abstract class, thus its functions will
 **be pure virtual functions. This is the base/parent class. Those 
 **functions that are pure virtual functions will not be declared here.
 **Only in the derived classes.
*********************/

#include "Character.hpp"
#include "ListNode.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


/******************
 **Description: This is the constructor for the class Character. It sets the name
 **selected by the user to the Character. 
*******************/
Character::Character(string newName)
{
	life = 1;	//life tracker
	ID = newName;
}

/*****************
 **Description: This is the destructor. It is just a virtual function.
******************/
Character::~Character()
{

}

/******************
 **Description: This function calculates the attack and defense of 
 **the character to determine how much a charcter has lost in strength.
 **Its parameters are the values returned from the attackRoll() and
 **defenseRoll() functions, which are both int.
 **
 **Using the function set by the professor to calculate the damage:
 **     damage = attacker's roll - defender's roll - defender's armor
******************/
void Character::damageInflicted(int attack, int defense)
{
	//assign the strengthPoints to the startingStrength so it can be tracked
	startingStrength = strengthPoints;
	
	int totalDamage = 0;

	if(attack > (defense+armor))
	{
		totalDamage = (attack - defense - armor);

		strengthPoints -= (attack - defense - armor);
	}

	if(strengthPoints <= 0)
	{
		strengthPoints = 0;
		life--;	//character dies
	}

	/*commenting out the following below for Proj4

	cout << endl;	//spacing
	cout << "___________________________\n";	
	cout << "|Total Damage Inflicted: " << totalDamage << "|" << endl;
	cout << "---------------------------\n";
	cout << endl;	//spacing
	cout << name << "'s strength was: " << startingStrength << endl;	
	cout << name << "'s strength is now: " << strengthPoints << endl;
	cout << "________________________________________\n";
	cout << endl;
	cout << "----------------------------------------\n";
	cout << endl;*/
}

/******************
 **Description: The next five functions are getter functions.
******************/
int Character::getArmor()
{
	return armor;
}

int Character::getStrengthPoints()
{
	return strengthPoints;
}

int Character::getLife()
{
	return life;
}

string Character::getName()
{
	return name;
}

string Character::getId()
{
	return ID;
}

/********************
 **Description: This function restore some strength back to the 
 **winner of the round in the tournament. 
 **Adds 5 points of strength back to Character.
 ************************/
void Character::restoreStrength()
{
	cout << "Restoring 5 points of health to the winner, ";
	cout << getName() << ", " << getId() << "!\n";
	cout << "  -Strength was: " << strengthPoints << endl;
	strengthPoints += 5;	//5 points added to strength
	cout << "  -Strength is now: " << strengthPoints << endl;
	cout << endl;
}

	 


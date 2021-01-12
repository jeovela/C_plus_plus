/*********************
 **Program Name: Medusa.cpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the implementation file for the derived class
 **Medusa. Its parent class is Character.
**********************/

#include "Character.hpp"
#include "Medusa.hpp"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/*******************
 **Description: This is the constructor for the class Medusa. Member
 **variables inherited by the Character class are assigned the values from
 **the Character spec sheet. User selected name is set in the Character 
 **constructor.
***********************/
Medusa::Medusa(string newName) : Character(newName)
{	
	this->armor = 3;
	this->strengthPoints = 8;
	this->name = "Medusa";
}

/*******************
 **Description: This is the destructor for the class Medusa.
*******************/
Medusa::~Medusa()
{
	//empty
}

/*****************
 **Description: This is Medusa's attack roll. She has 2 die that 
 **are 6-sided to roll. If she rolls a 12 then her special ability glare kicks in.
 **Her roll is then set 9999 so it can attack any defense and armor.
******************/
int Medusa::attackRoll()
{
	int roll;
	int attackDie1, attackDie2;

	attackDie1 = rand() % 6 + 1;	//return a random # between 1-6
	attackDie2 = rand() % 6 + 1;

	//calculate
	roll = attackDie1 + attackDie2;

	/*commenting out the following for Proj4
	cout << "___________\n";
        cout << "|ATTACKING|\n";
        cout << "-----------\n";	
	cout << endl;	//spacing
	cout << "Medusa rolled " << roll << " attack points!\n";
	cout << endl;*/

	//Medusa's special ability, glare will kick in if she rolls a 12
	//will set the roll to 9999 so it can attack any defense and
	//kill opponent with glare alone
	if(roll == 12)
	{
		/*commenting out the follwoing for Proj4
		cout << endl;	//spacing
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Medusa has used her special ability, glare!\n";
		cout << "The opponent has turned into stone!\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << endl;*/
		
		//set roll to 9999 so it attack any defense & armor
		roll = 9999;

		return roll;
	}
		
	return roll;
}

/*******************
 **Description: This is Medusa's defensive roll. She has 1 die
 **to roll that is 6-sided.
******************/
int Medusa::defenseRoll()
{
	int roll;
	int defenseDie1;

	defenseDie1 = rand() % 6 + 1;	//return a random # between 1-6

	//assign value to roll
	roll = defenseDie1;

	/*commenting out the following for Proj4
	cout << "___________\n";
        cout << "|DEFENDING|\n";
        cout << "-----------\n";
	cout << endl;	//spacing
	cout << "Medusa rolled " << roll << " defensive points!\n";
	cout << "Medusa's armor: " << this->getArmor() << endl;
	cout << endl;*/

	return roll;

}

/***********************
 **Description: This function determines if the character is dead. 
 **If the character's life is <= 0, he is dead.  Will return bool value. 
***********************/
bool Medusa::isDead()
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


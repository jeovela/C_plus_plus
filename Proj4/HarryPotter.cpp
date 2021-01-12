/***********************
 **Program Name: HarryPotter.cpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the implementation file for the derived class
 **Harry Potter. Its parent class is Character.
**********************/

#include "Character.hpp"
#include "HarryPotter.hpp"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/******************
 **Description: This is the constructor for the class Harry Potter.
 **Member variables inherited by the Character class are assigned the
 **values from the Character spec sheet. User selected name is set in the
 **Character constructor.
*****************/
HarryPotter::HarryPotter(string newName) : Character(newName)
{	
	this->armor = 0;
	//starts @ 10, but when points drop to zero, it rebounds to 20
	//second time it goes to 0, Harry dies
	this->strengthPoints = 10; 
	this->name = "Harry Potter";
}

/********************
 **Description: This is the destructor for the class Harry Potter
********************/
HarryPotter::~HarryPotter()
{
	//empty
}

/*****************
 **Description: This is Harry Potter's attack roll. He has 2 die
 **that are 6-sided to roll.
******************/
int HarryPotter::attackRoll()
{
	int roll;
	int attackDie1, attackDie2;

	attackDie1 = rand() % 6 + 1;
	attackDie2 = rand() % 6 + 1;

	//calculate
	roll = attackDie1 + attackDie2;

	/*commenting out the following for Proj4
	cout << "___________\n";
        cout << "|ATTACKING|\n";
        cout << "-----------\n";
	cout << endl;	//spacing
	cout << "Harry Potter rolled " << roll << " attack points!\n";
	cout << endl;*/

	return roll;
}

/******************
 **Description: This is Harry Potter's defensive roll. He has 2 die
 **to roll that are 6-sided each.
*****************/
int HarryPotter::defenseRoll()
{
	int roll;
	int defenseDie1, defenseDie2;

	defenseDie1 = rand() % 6 + 1;	//return a random # between 1-6
	defenseDie2 = rand() % 6 + 1;

	//calculate
	roll = defenseDie1 + defenseDie2;
	
	/*commenting out the following for Proj4
	cout << "___________\n";
        cout << "|DEFENDING|\n";
        cout << "-----------\n";
	cout << endl;	//spacing
	cout << "Harry Potter rolled " << roll << " defensive points!\n";
	cout << "Harry Potter's armor: " << this->getArmor() << endl;
	cout << endl;*/

	return roll;	
}

/**********************
 **Description: This function determines if the character is dead. 
 **If the character's life is <= 0, he is dead.  Will return bool value.
 **Additionally, Harry's special ability will kick in if dies. If he dies, a 
 **message will appear stating Harry's recovered and 20 strength pts are added.
 **Using bool value set in specification file to T to make sure his special
 **ability only happens once. Bool value is set to F after the message appears so
 **that when Harry does die again, his special ability wont cont. to kick in.
************************/
bool HarryPotter::isDead()
{
	if(life <= 0 && once)
	{
		/*commenting out the following for Proj4
		cout << endl;	//spacing
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "Wait! Harry's not dead yet!\n";
                cout << "His strength points has recovered to 20!\n";
                cout << "All thanks to special ability, Hogwarts!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << endl;*/
			
		//add 20 to starting strength points
		this->strengthPoints += 20;
        	life++;		//add 1 back to his life
		//set once to false so this is only ran once
		once = false;

		return false;	//must return F so compiler knows he is not dead

	}

        else if(life <= 0)
        {	
                return true;
        }

        else
        {
                return false;
        }
}


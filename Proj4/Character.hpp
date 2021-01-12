/*********************
 **Program Name: Character.hpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the specification file for the class Character.
 **This class will serve as an abstract class, thus its functions will
 **be pure virtual functions. This is the base/parent class.
*********************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using std::string;

class Character
{
	protected:
		string name;
		int armor;
		int strengthPoints;
		int life;
		int startingStrength;	//will keep track of strength pts	
		string ID;
	public:
		Character(string newName);//constructor that sets the user chosen name
		virtual ~Character();	//destructor
		virtual int attackRoll() = 0;	//pure virtual function
		virtual int defenseRoll() = 0;	//pure virtual function
		virtual void damageInflicted(int attack, int defense);
		int getArmor();		//getter functions
		int getStrengthPoints();	
		int getLife();
		string getName();
		virtual bool isDead() = 0;	//determine if char is dead yet
		string getId();	//returns user chosen name
		void restoreStrength();
};
#endif



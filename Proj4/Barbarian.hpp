/********************
 **Program Name: Barbarian.hpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the specification file for the derived class
 **Barbarian. It's parent class is Character.
**********************/

#ifndef BARBARIAN_H
#define BARBARIAN_H

#include <string>

using std::string;

class Barbarian : public Character
{
	public:
		Barbarian(string newName);	//constructor
		~Barbarian();	//destructor
		virtual int attackRoll();	
		virtual int defenseRoll();
		virtual bool isDead();

};
#endif

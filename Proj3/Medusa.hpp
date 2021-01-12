/********************
 **Program Name: Medusa.hpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the specification file for the derived class 
 **Medusa. Its parent class is Character.
*********************/

#ifndef MEDUSA_H
#define MEDUSA_H

class Medusa : public Character
{
	public:
		Medusa();	//constructor
		~Medusa();	//destructor
		virtual int attackRoll();
		virtual int defenseRoll();
		virtual bool isDead();
};
#endif

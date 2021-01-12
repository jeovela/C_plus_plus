/***********************
 **Program Name: blueMen.hpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the specification file for the derived class
 **Blue Men. Its parent class is Character.
*************************/

#ifndef BLUEMEN_H
#define BLUEMEN_H

class BlueMen : public Character
{
	public:
		BlueMen();	//constructor
		~BlueMen();	//destructor
		virtual int attackRoll();
		virtual int defenseRoll();
		virtual bool isDead();

};
#endif

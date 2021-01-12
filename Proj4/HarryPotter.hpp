/********************
 **Program Name: HarryPotter.hpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the specification file for the derived class
 **Harry Potter. Its parent class is Character.
********************/

#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H

using std::string;

class HarryPotter : public Character
{
	private:
		bool once = true;	//keep track of Harry's deaths set to T
	public:
		HarryPotter(string n);		//constructor
		~HarryPotter();		//destructor
		virtual int attackRoll();
		virtual int defenseRoll();
		virtual bool isDead();
};
#endif

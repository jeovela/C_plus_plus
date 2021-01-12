/*********************
 **Program Name: Breakroom.hpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the specification file for the 
 **derived class Breakroom.
********************/

#ifndef BREAKROOM_H
#define BREAKROOM_H

class Breakroom : public Space
{
	public:
		Breakroom();
		virtual int promptMenu();
};
#endif

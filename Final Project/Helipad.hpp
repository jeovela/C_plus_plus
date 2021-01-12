/************************
 **Program Name: Helipad.hpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the specification file for the 
 **derived class Helipad.
********************/

#ifndef HELIPAD_H
#define HELIPAD_H

class Helipad : public Space
{
	public:
		Helipad();
		virtual int promptMenu();
};
#endif

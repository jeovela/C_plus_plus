/****************
 **Progam Name: smokingArea.hpp
 **Author: Jeovani Vela
 **Date: 3/12/18
 **Description: This is the specification file for the
 **derived class SmokingArea.
*****************/

#ifndef SMOKINGAREA_H
#define SMOKINGAREA_H

class SmokingArea : public Space
{
	protected:
		bool knife;
	public:
		SmokingArea();	//constructor
		virtual int promptMenu();
		void knifeInPocket(bool t); 
};
#endif

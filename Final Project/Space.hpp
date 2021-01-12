/*********************
 **Program Name: Space.hpp
 **Author: Jeovani Vela
 **Date: 3/11/18
 **Description: This is the specification file for the class Space.
 **This class will be an abstract class, thus no objects of
 **this class can be declared and instead pointers of this type
 **will be used. This class will also serve as a Parent class to
 **the spaces used in the game Die Hard OKC.
**********************/

#ifndef SPACE_H
#define SPACE_H

#include <string>

using std::string;

class Space
{
	protected:
		//following pointer will serve as links in the building
		Space *right;
		Space *left;
		Space *up;
		Space *down;
		Space *up1;	//additional space pointer
		Space *up2;
		Space *up3;
		Space *up4;
		Space *up5;
		Space *up6;
		Space *up7;
		Space *down1;	
		Space *down2;
		Space *down3;
		Space *down4;
		Space *down5;
		Space *down6;
		Space *down7;	
		string name;	//name of space

	public:
		Space();
		~Space();	//destructor;
		void setName(string n);
		string getName();

		void setRightSpace(Space*);
		void setLeftSpace(Space*);
		void setUpSpace(Space*);
		void setUp1Space(Space*);
		void setUp2Space(Space*);
		void setUp3Space(Space*);
		void setUp4Space(Space*);
		void setUp5Space(Space*);
		void setUp6Space(Space*);
		void setUp7Space(Space*);
		void setDownSpace(Space*);
		void setDown1Space(Space*);
		void setDown2Space(Space*);
		void setDown3Space(Space*);
		void setDown4Space(Space*);
		void setDown5Space(Space*);
		void setDown6Space(Space*);
		void setDown7Space(Space*);

		Space* getRightSpace();
		Space* getLeftSpace();
		Space* getUpSpace();
		Space* getDownSpace();

		virtual int promptMenu() = 0;	//pure virtual function
};
#endif

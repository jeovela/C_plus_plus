/********************
 **Program Name: Space.cpp
 **Author: Jeovani Vela
 **Date: 3/11/18
 **Description: This is the implementation file for the class
 **Space. This class is an abstract class.
**********************/

#include "Space.hpp"

#include <iostream>
#include <string>

using std::string;

/********************
 **Description: This is the constructor for the abstract class Space.
 **Sets the member variables that are pointers to nullptr;
**********************/
Space::Space()
{
	right = nullptr;
	left = nullptr;
	up = nullptr;
	up1 = nullptr;	//additional space pointer
	up2 = nullptr;
	up3 = nullptr;
	up4 = nullptr;
	up5 = nullptr;
	up6 = nullptr;
	up7 = nullptr;
	down = nullptr;
	down1 = nullptr;
	down2 = nullptr;
	down3 = nullptr;
	down4 = nullptr;
	down5 = nullptr;
	down6 = nullptr;
	down7 = nullptr;
}

/****************
 **Description: This is the destructor for the class Space.
***************/
Space::~Space()
{
	//empty
}
	
/******************
 **Description: This function is a setter function and sets
 **the name for the Space the character is currently in.
*********************/
void Space::setName(string n)
{
	name = n;
}

/********************
 **Description: The following functions are setter functions.
 **They will help set the adjacent spaces when Character moves
 **through the building.
***********************/
void Space::setRightSpace(Space* r)
{
	right = r;
}

void Space::setLeftSpace(Space *l)
{
	left = l;
}

void Space::setUpSpace(Space *u)
{
	up = u;
}

//set up spaces
void Space::setUp1Space(Space *u1)
{
        up1 = u1;
}
void Space::setUp2Space(Space *u2)
{
        up2 = u2;
}

void Space::setUp3Space(Space *u3)
{
        up3 = u3;
}

void Space::setUp4Space(Space *u4)
{
        up4 = u4;
}

void Space::setUp5Space(Space *u5)
{
        up5 = u5;
}

void Space::setUp6Space(Space *u6)
{
        up6 = u6;
}

void Space::setUp7Space(Space *u7)
{
        up7 = u7;
}

//set down spaces
void Space::setDownSpace(Space *d)
{
	down = d;
}

void Space::setDown1Space(Space *d1)
{
        down1 = d1;
}

void Space::setDown2Space(Space *d2)
{
        down2 = d2;
}

void Space::setDown3Space(Space *d3)
{
        down3 = d3;
}

void Space::setDown4Space(Space *d4)
{
        down4 = d4;
}

void Space::setDown5Space(Space *d5)
{
        down5 = d5;
}

void Space::setDown6Space(Space *d6)
{
        down6 = d6;
}

void Space::setDown7Space(Space *d7)
{
        down7 = d7;
}

/**********************
 **Description: The following 5 functions are getter functions.
**********************/
string Space::getName()
{
	return name;
}

Space* Space::getRightSpace()
{
	return right;
}

Space* Space::getLeftSpace()
{
	return left;
}

Space* Space::getUpSpace()
{
	return up;
}

Space* Space::getDownSpace()
{
	return down;
}


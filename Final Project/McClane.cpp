/****************
 **Program Name: McClane.cpp
 **Author: Jeovani Vela
 **Date: 3/12/18
 **Description: This is the specification file for the
 **class McClane. This class is the character, John McClane.
 **Using a Queue ADT as a container for John which is his
 **pant cargo pocket.
****************/

#include "McClane.hpp"
#include "Space.hpp"
#include "Game.hpp"
#include "parkingGarage.hpp"
#include "smokingArea.hpp"
#include "landRecords.hpp"
#include "Breakroom.hpp"
#include "ceoOffice.hpp"
#include "towerRestaurant.hpp"
#include "Helipad.hpp"

#include <iostream>
#include <queue>	//required for Queue STL
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::queue;	//required for Queue STL usage

/*******************
 **Description: This is the defualt constructor for the class
 **McClane. It just clears the Queue to make sure nothin is in
 **there. It also sets the member variables kinfe and map to 
 **false so they can be changed to false once they are added
 **to the Queue.
*******************/
McClane::McClane()
{
	cargoPantPocket = {};
}

/*************** 
 **THis function when called adds an item to
 **the Queue which is John's cargo pant pocket
 **aka "container". Using STL queue library to
 **push item onto Queue.
***************/
void McClane::addItem(string stuff)
{
	//push onto Queue
	cargoPantPocket.push(stuff);

	if(cargoPantPocket.size() > 0)	//check if item is added
	{
		cout << endl;
		cout << stuff << " added to cargo pant pocket!\n";
		cout << endl;
	}
}
		
/******************
 **Description: This is the destructor for the class McClane.
 **It pops off stuff in the queue.
******************/
McClane::~McClane()
{
	//empty
}

int McClane::returnSize()
{
	return (int)cargoPantPocket.size();
}

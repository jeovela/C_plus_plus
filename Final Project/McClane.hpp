/****************
 **Program Name: McClane.hpp
 **Author: Jeovani Vela
 **Date: 3/12/18
 **Description: This is the specification file for the
 **class McClane. This class is the character, John McClane.
 **Using a Queue ADT as a container for John which is his
 **pant cargo pocket.
****************/

#ifndef MCCLANE_H
#define MCCLANE_H

#include "Space.hpp"

#include <iostream>
#include <queue>	//required for container
#include <string>

using std::string;
using std::queue;	//required for queue STL usage

class McClane
{
	protected:
		queue<string> cargoPantPocket;	//declare Queue ADT
	public:
		McClane();	//constructor;
		~McClane();	//destructor
		//used when John goes moves to another space
		void addItem(string stuff);	//used to add stuff to queue
		int returnSize();
};
#endif

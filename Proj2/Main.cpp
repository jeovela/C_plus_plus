/*******************
 **Program Name: Main.cpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the main file for project 2. This file will utilize the  **class Zoo to play the game Zoo Tycoon.
******************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Longhorn.hpp"

#include<iostream>

using std::cout;
using std::endl;

int main()
{
	//create Zoo object
	Zoo z;
	
	//print out start screen
	z.printStartScreen();
	z.startMenu();
	z.runDay();

	return 0;
}

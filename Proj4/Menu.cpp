/*********************
 **Program Name: Menu.cpp
 **Author: Jeovani Vela
 **Date: 2/26/18
 **Description: This is the implementation file for the function display
 **menu.
**********************/

#include "Menu.hpp"

#include <iostream>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::set;

/******************
 **Description: This function displys two options to the user, start the game
 **or quit. Function returns a value type int.
******************/
int startMenu()
{
	int selection;

	cout << endl;	//spacing
	cout << "Please select one of the two choices below.\n";
	cout << endl;	//spacing
	cout << "1. Play\n";
	cout << "2. Exit\n";
	cout << endl;	//spacing

	cin >> selection;

	//input validator
	while(selection < 1 || selection > 2)
	{
		cin.clear();
		cin.ignore(500, '\n');
		cout << "You entered an incorrect selection.\n";
		cout << "Enter 1 to play or 2 to quit.\n";
		cin >> selection;
	}

	if(selection == 1 || selection == 2)
	{
		return selection;
	}
}

/****************
 **Progam Name: landRecords.cpp
 **Author: Jeovani Vela
 **Date: 3/13/18
 **Description: This is the specification file for the
 **derived class LandRecordsOffice.
*****************/

#include "Space.hpp"
#include "landRecords.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*******************
 **Description: This is the constructor for the derived class
 **LandRecordsOffice. Set the name for the space.
*******************/
LandRecordsOffice::LandRecordsOffice()
{
	setName("Land Records Office");
}

/********************
 **Description: This function presents the user with a
 **menu specific to the Space John is currently in.
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
*********************/
int LandRecordsOffice::promptMenu()
{
	int choice;
	Game g;
	McClane m;

	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;
	cout << "1. Search the land records office.\n";
	cout << "2. Go to the staff breakroom.\n";
	cout << "3. Take the elevator up to the conference room.\n";
	cout << "4. Take the elevator up to the CEO office.\n";
	cout << "5. Take the elevator up to the tower restaurant.\n";
	cout << "6. Take the elevator up to the helipad.\n";
	cout << "7. Take the elevator down to the lobby.\n";
	cout << "8. Take the elevator down to the parking garage.\n";
	cout << "9. Take the elevator down to the designated smoking area.\n";
	cout << endl;
	cin >> choice;
	cout << endl;

	while(choice < 1 || choice > 9)
	{
		cin.clear();
		cin.ignore(500,'\n');
		cout << "ERROR! - Invalid choice./n";
		cout << "Enter a number between 1 and 9";
		cin >> choice;
		cout << endl;
	}

	if(choice == 1)
	{
		int choice2;

		cout << endl;
		cout << "You decide to approach?\n";
		cout << endl;
		cout << "1. The filing cabinets.\n";
		cout << "2. The materials lying on the table.\n";
		cout << "3. The dead body on the floor.\n";

		cout << endl;
		cin >> choice2;
		cout << endl;
		
		while(choice2 < 1 || choice2 > 3)
		{
			cin.clear();
			cin.ignore(500,'\n');
			cout << "ERROR! - Invalid choice./n";
			cout << "Enter either 1, 2, or 3.\n";
			cin >> choice2;
			cout << endl;
		}

		if(choice2 == 1)
		{
			cout << "John searches the filing cabinets\n";
			cout << "but discovers nothing.\n";
			cout << endl;
		}
		if(choice2 == 2)
		{
			cout << "John shuffles through all the paper\n";
			cout << "and materials on the table and\n";
			cout << "discovers a security code!\n";
			cout << "	~Security Code Found~	\n";
				m.addItem("1st set of codes");
				bool temp = true;
				g.changeCode1(temp);
			cout << endl;
		}
		if(choice2 == 3)
		{
			cout << "John rumages through the pockets of the\n";
			cout << "dead person and finds nothing.\n";
			cout << endl;
		}
	}
	if(choice == 2)
	{
		return 5;
	}	
	if(choice == 3)
	{
		return 6;
	}
	if(choice == 4)
	{
		return 7;
	}
	if(choice == 5)
	{
		return 8;
	}
	if(choice == 6)
	{
		return 9;
	}
	if(choice == 7)
	{
		return 3;
	}
	if(choice == 8)
	{
		return 1;
	}
	if(choice == 9)
	{
		return 2;
	}
}
		

/*******************
 **Progam Name: Breakroom.cpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the implemenation file 
 **for the derived class Breakroom.
********************/

#include "Space.hpp"
#include "Breakroom.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/********************
 **Description: THis is the constructor for the derived
 **class breakroom.
*******************/
Breakroom::Breakroom()
{
	setName("Staff Breakroom");
}

/*******************
 **Description: This is the virtual void function designed to 
 **present the user/player with a menu specifically designed for
 **the class John McClane currently is in.
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
***********************/
int Breakroom::promptMenu()
{
	int choice;
	McClane m;	//declaring McClane object here
	Game g;
	
	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;
	cout << "1. Search the staff breakroom.\n";
	cout << "2. Go to the land records office.\n";
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
		cout << "1. The suspicious refrigerator in the corner.\n";
		cout << "2. The seating lounge. \n";
		cout << "3. The cabinets.\n";

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
			cout << "John opens the refrigerator and\n";
			cout << "sarin gas is released in the space!\n";
			cout << "The refrigerator was booby-trapped!\n";
			cout << endl;
			cout << "John has died!\n";
                        cout << endl;
			bool temp = true;
			g.changeSarin(temp);
		}

		if(choice2 == 2)
		{
			cout << "John searches the seating lounge\n";
			cout << "and finds nothing but company memos\n";
			cout << "and change in between the cushions.\n";
			cout << endl;
		}
		if(choice2 == 3)
		{
			cout << "John hastily goes through each\n";
			cout << "cabinet to find nothing but\n";
			cout << "plasticware and old cans of coffee.\n";
		}
	}

	if(choice == 2)
	{
		return 4;
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

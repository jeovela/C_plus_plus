/************************
 **Program Name: Helipad.cpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the implementation file for the 
 **derived class Helipad.
********************/

#include "Space.hpp"
#include "Helipad.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/********************
 **Description: This is the constructor for the derived class
 **Helipad.
*******************/
Helipad::Helipad()
{
	setName("Helipad");
}

/************************
 **Description: This function presents the user with a 
 **menu specific to the Space John is currently in.
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
 *********************/
int Helipad::promptMenu()
{
	int choice;
	Game g;

	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;
	cout << "1. Search the helipad.\n";
	cout << "2. Take the elevator down to the tower restaurant.\n";
	cout << "3. Take the elevator down to the CEO Office.\n";
	cout << "4. Take the elevator down to the conference room.\n";
	cout << "5. Take the elevator down to the staff breakroom.\n";
	cout << "6. Take the elevator down to the land records office.\n";
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
	{	char choice2;
		cout << "The helipad is empty other than a briefcase\n";
		cout << "standing up in the middle of the pad.\n";
		cout << endl;
		cout << "Open the briefcase?\n";
		cout << endl;
		cout << "Enter either 'Y' or 'N'.\n";
		cin >> choice2;
		cout << endl;

		while(!(toupper(choice2) == 'Y') || toupper(choice2) == 'N')
		{
			cin.clear();
			cin.ignore(500,'\n');
			cout << "ERROR! Invalid input!\n";
			cout << "Enter either 'Y' or 'N' \n";
			cin >> choice2;
			cout << endl;
		}
		if(toupper(choice2) == 'Y')
		{
			cout << "Shit, its anthrax!\n";
			cout << "John has died!\n";
			cout << endl;
			bool temp = true;
			g.changeAnthrax(temp);
		}
	}

	if(choice == 2)
	{
		return 8;
	}
	if(choice == 3)
	{
		return 7;
	}
	if(choice == 4)
	{
		return 6;
	}
	if(choice == 5)
	{
		return 5;
	}
	if(choice == 6)
	{
	       return 4;
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



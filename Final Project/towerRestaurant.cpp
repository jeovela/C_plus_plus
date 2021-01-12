/********************
 **Program Name: towerRestaurant.cpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the implementation file for the 
 **derived class TowerRestaurant.
*******************/

#include "Space.hpp"
#include "towerRestaurant.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**********************
 **Description: This is the constructor for the derived class
 **TowerRestaurant.
*********************/
TowerRestaurant::TowerRestaurant()
{
	setName("Tower Restaurant");
}

/************************
 **Description: This function presents the user with a 
 **menu specific to the Space John is currently in.
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
 ********************/
int TowerRestaurant::promptMenu()
{
	int choice;
	Game g;
	McClane m;
	
	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;
	cout << "1. Search the tower restaurant.\n";
	cout << "2. Take the elevator up to the helipad.\n";
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
	{
		int choice2;

		cout << endl;
		cout << "You decide to approach?\n";
		cout << endl;
		cout << "1. The cash register.\n";
		cout << "2. The kitchen.\n";
		cout << "3. The bar.\n";

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
			cout << "John doesn't even attempt to\n";
			cout << "search for the codes.\n";
			cout << "Instead he pockets the cash in\n";
			cout << "register.\n";
			cout << endl;

		}
		if(choice2 == 2)
		{
			cout << "John searches the entire kitchen\n";
			cout << "until he follows a trail of blood\n";
			cout << "to the walk-in freezer.\n";
			cout << "Inside he finds an execuitve who\n";
			cout << "was killed execution style with\n";
			cout << "a security code stapeled to his face!\n";
			cout << "	~Security Code Found!~	\n";
			cout << endl;
			m.addItem("3rd set of codes");
			bool temp = true;
			g.changeCode3(temp);
		}
		if(choice2 == 3)
		{
			cout << "Frustrated, tired, and stressed to\n";
			cout << "the max, John pours himself a drink\n";
			cout << "before proceeding to search for the\n";				cout << "remaining security codes.\n";
			cout << endl;
		}
	}
	if(choice == 2)
	{
		return 9;
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

	

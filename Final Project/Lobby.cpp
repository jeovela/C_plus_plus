/*****************
 **Program Name: Lobby.cpp
 **Author: Jeovani Vela
 **Date: 3/13/18
 **Description: This is the implementation file 
 **for the derived class Lobby.
********************/

#include "Space.hpp"
#include "Lobby.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*******************
 **Description: This is the constructor for the derived
 **class Lobby.
*****************/
Lobby::Lobby()
{
	setName("Lobby");
}

/*****************
 **Description: This is the virtual void function designed to 
 **present the user/player with a menu specifically designed for
 **the class John McClane currently is in.
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
******************/
int Lobby::promptMenu()
{
	int choice;
	Game g;

	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;
	cout << "1. Search the Lobby.\n";
	cout << "2. Take the elevator down to the parking garage.\n";
	cout << "3. Take the elevator down to the smoking area.\n";
	cout << "4. Take the elevator up to the land records office.\n";
	cout << "5. Take the elevator up to the staff breakroom.\n";
	cout << "6. Take the elevator up to the conference room.\n";
	cout << "7. Take the elevator up to the CEO office.\n";
	cout << "8. Take the elevator up to the Tower Restaurant.\n";
	cout << "9. Take the elevator up the helipad.\n";
	cout << endl;
	cin >> choice;
	cout << endl;

	//input validator
	while(choice < 1 || choice > 9)
	{
		cin.clear();
		cin.ignore(500,'\n');
		cout << "ERROR! - Invalid choice.\n";
		cout << "Enter a number between 1 and 9.\n";
		cin >> choice;
		cout << endl;
	}

	if(choice == 1)
	{
		int choice2;

		cout << endl;
		cout << "You decide to approach?\n";
		cout << endl;
		cout << "1. The person fleeing the lobby.\n";
		cout << "2. The trash can next to the elevator\n";
		cout << "3. The lobby security desk.\n";
		cout << endl;
		cin >> choice2;
		cout << endl;

		//input validator
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
			cout << "John approaches the person running\n";
			cout << "towards the exit and asks if she knows\n";
			cout << "anything.\n";
			cout << "She replies - \" I saw some people in the\n";
			cout << "conference room leave something behind.\"\n";
			cout << endl;
			cout << "Maybe a security code is in the conference room?\n";
			cout << endl;
		}
		if(choice2 == 2)
		{
			cout << "John searches the trash can and finds nothing.\n";
			cout << endl;
		}
		if(choice2 == 3)
		{
			cout << "John rummages through the security desk in\n";
			cout << "the lobby and finds nothing, but a map\n";
			cout << "of Devon Tower.\n";
			cout << endl;
			g.displayMap();
		}
	}
	if(choice == 2)
	{
		return 1;
	}
	if(choice == 3)
	{
		return 2;
	}
	if(choice == 4)
	{
		return 4;
	}
	if(choice == 5)
	{
		return 5;
	}
	if(choice == 6)
	{
		return 6;
	}
	if(choice == 7)
	{
		return 7;
	}
	if(choice == 8)
	{
		return 8;
	}
	if(choice == 9)
	{
		return 9;
	}
}

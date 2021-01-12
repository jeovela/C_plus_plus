/******************
 **Program Name: parkingGarage.cpp
 **Author: Jeovani Vela
 **Date: 3/11/18
 **Description: This is the implementation file for the derived
 **class ParkingGarage.
************************/

#include "Space.hpp"
#include "parkingGarage.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/************************
 **Description: This is the constructor for the derived class
 **ParkingGarage.
**************************/
ParkingGarage::ParkingGarage() : Space()
{
	setName("Parking Garage");
}

/******************
 **Description: This is the virtual void function designed to 
 **present the user/player with a menu specifically designed for
 **the class John McClane currently is in.
 **
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
**********************/
int ParkingGarage::promptMenu()
{
	int choice;
	Game g;

	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;
	cout << "1. Search the parking garage.\n";
	cout << "2. Go to the designated smoking area.\n";
	cout << "3. Take the elevator up to the lobby.\n";
	cout << "4. Take the elevator up to the land records office.\n";
	cout << "5. Take the elevator up to the staff breakroom.\n";
	cout << "6. Take the elevator up to the conference room.\n";
	cout << "7. Take the elevator up to the CEO office.\n";
	cout << "8. Take the elevator up to the tower restaurant.\n";
	cout << "9. Take the elevator up to the helipad.\n";
	
	cout << endl;
	cin >> choice;
	cout << endl;

	//input validator
	while(choice < 1 || choice > 9)
	{
		cin.clear();
		cin.ignore(500,'\n');
		cout << "ERROR! - Invalid choice./n";
		cout << "Enter a number between 1 and 9\n";
		cin >> choice;
		cout << endl;
	}

	if(choice == 1)
	{
		int choice2;

		cout << endl;
		cout << "You decide to approach?\n";
		cout << endl;
		cout << "1. The bomb.\n";
		cout << "2. The creepy white van with no windows.\n";
		cout << "3. The parking garage restrooms.\n";
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
			cout << "John searches the bomb for clues, but there is\n";
			cout << "nothing there except for the serial number.\n";
			cout << "Serial No. TF-P35481100142010\n";
			cout << endl;
			cout << "John screams \"f*#&!\"\n";
			cout << endl;
		}
		if(choice2 == 2)
		{
			char decision;

			cout << "You open the doors to the van only\n";
			cout << "to discover 9 hostages tied up and\n";
			cout << "blindfolded.\n";
			cout << endl;;
			cout << "Do you want to help them?\n";
			cout << "Enter 'Y' for yes or 'N' for No.\n";
			cin >> decision;
			cout << endl;
			
			//input validator
			while(!(toupper(decision) == 'Y' || toupper(decision) == 'N'))
			{
				cin.clear();
				cin.ignore(500,'\n');
				cout << "ERROR! - Invalid selection.\n";	
				cout << "Enter either 'Y' or 'N'.\n";
				cin >> decision;
				cout << endl;
			}

			if(toupper(decision) == 'Y')
			{
				cout << "John rescues the 9 hostages!\n";
				cout << "Afterwards one of the hostages\n";
				cout << "who is a janitor gives you a\n";			
				cout <<"map.\n";
				cout << endl;
				g.displayMap();	//function call
				cout << "John takes it and places it in\n";
				cout << "his cargo pant pocket.\n";

				//add  map to queue (i.e. container)
				McClane m;	//declare McClane object
				m.addItem("map");

				//set bool member variable map to True
				bool temp = true;
				g.setMapBool(temp);
				
			}
			if(toupper(decision) == 'N')
			{
				cout << "John says \"f@%# it\" and\n";
				cout << "moves on.\n";
				cout << endl;
			}
		}
		if(choice2 == 3)
		{
			cout << "John kicks in the door to the men's\n";
			cout << "restrooms and searches the stalls.\n";
			cout << "He finds nothing but overflowing urinals,\n";
			cout << "unflushed toilets, and a disgusting stench.\n";
			cout << endl;
			cout << "John searches the women's restrooms next.\n";
			cout << "All he finds is a clogged toilet and a shoe\n";
			cout << "with a broken heel.\n";
			cout << endl;
			cout << " 	 ~No security codes!~\n";
			cout << endl;
		}
	}
	if(choice == 2)
	{
		return 2;
	}
	if(choice == 3)
	{
		return 3;
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

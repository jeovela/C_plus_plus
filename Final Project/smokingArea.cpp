/*****************
 **Program Name: smokingArea.cpp
 **Author: Jeovani Vela
 **Date: 3/12/18
 **Description: This is the implementation file for
 **the derived class SmokingArea.
*****************/

#include "Space.hpp"
#include "smokingArea.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/************************
**Description: This is the constructor for the derived class
**SmokingArea.
***************************/
SmokingArea::SmokingArea()
{
	setName("Designated Smoking Area");
	knife = false;
}

/************************
 **Description: This is the virtual void function designed to 
 **present the user/player with a menu specifically designed for
 **the class John McClane currently is in. 
 **
 **Note: John must have the knife to access the drop boxes.
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
********************/
int SmokingArea::promptMenu()
{
	int choice;
	Game g;	//declare Game object to add to container

	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;
	cout << "1. Search the designated smoking area.\n";
	cout << "2. Go to the parking garage.\n";
	cout << "3. Take the elevator up to the lobby.\n";
	cout << "4. Take the elevator up to the land records office.\n";
	cout << "5. Take the elevator up to the staff breakroom.\n";
	cout << "6. Take the elevator up to the conference room.\n";
	cout << "7. Take the elevator up to the CEO office.\n";
	cout << "8. Take the elevator up to the Tower Restaurant.\n";
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
		cout << "1. The stranger walking by.\n";
		cout << "2. The pack of cigarettes on the ground.\n";
		cout << "3. The FedEx and UPS drop boxes.\n";
		cout << "4. The dead security guard lying in a pool of blood.\n";

		cout << endl;
		cin >> choice2;
		cout << endl;

		//input validator
		while(choice2 < 1 || choice2 > 4)
		{
			cin.clear();
			cin.ignore(500,'\n');
			cout << "ERROR! - Invalid choice./n";
			cout << "Enter either 1, 2, 3 or 4.\n";
			cin >> choice2;
			cout << endl;
		}

		if(choice2 == 1)
		{
			cout << "John grabs the passerby and asks\n";
			cout << "what he is doing here and if he knows\n";
			cout << "anything.\n";
			cout << endl;
			cout << "The guy shouts \"let me go!\"\n";
			cout << "\"I don't know shit! I work across\n";
			cout << "the street!\"\n";
			cout << endl;
			cout << "John releases the guy and he\n";
			cout << "responds, \"F@^# off!\"\n";
			cout << endl;
			cout << "John throws him the finger.\n";
			cout << endl;
		}
		if(choice2 == 2)
		{
			cout << "John grabs the pack of cigarettes.\n";
			cout << "No security codes, but there is a\n";
			cout << "scrumpled cigarette.\n";
			cout << endl;
			cout << "John decides to take a 15 min smoke\n";
			cout << "break.\n";
			cout << endl;
		}
		if(choice2 == 3)
		{
			//if John has the knife	
			if(knife == true)
			{
				cout << "John uses the pocket knife\n";
				cout << "picked up from the dead\n";
				cout << "security guard to pick\n";
				cout << "open the locks on the\n";
				cout << "drop boxes, but no luck.\n";
				cout << endl;
				cout << " 	~No security codes!~\n";
				cout << endl;
			}
			else //with no knife
			{
				cout << "Looks like John needs to\n";
				cout << "pick the lock on these.\n";
				cout << "drop boxes.\n";
				cout << endl;
				cout << "Maybe that dead security\n";
				cout << "guard lying on the ground a\n";
				cout << "couple feet away has\n";
				cout << "something of use.\n";
				cout << endl;
			}
		}				
	
		if(choice2 == 4)
		{
			cout << "John searches the security guard\n";
			cout << "only to find a pocket knife.\n";
			cout << "John takes it and places it in his\n";
			cout << "cargo pant pocket.\n";
			cout << endl;
			//function call-set knife to true
			bool temp = true;
			knifeInPocket(temp);
			g.changeKnife(temp);	//change static member variable
		}
	}
	if(choice == 2)
	{
		return 1;	
	}
	if(choice == 3)
	{
		cout << "John smokes a cigarette in the elevator as he\n";
		cout << "contemplates his next move.\n";
		cout << endl;
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

/**********************
 **Description: Function sets the member variable knife to true.
***********************/
void SmokingArea::knifeInPocket(bool t)
{
	knife = t;
}
	

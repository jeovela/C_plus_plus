/****************
 **Progam Name: conferenceRoom.cpp
 **Author: Jeovani Vela
 **Date: 3/13/18
 **Description: This is the specification file for the
 **derived class ConferenceRoom.
*****************/

#include "Space.hpp"
#include "conferenceRoom.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>
#include <cstdlib> //required for random

using std::cout;
using std::cin;
using std::endl;

/****************
 **Description: This is the constructor for the derived
 **class ConferenceRoom.
*******************/
ConferenceRoom::ConferenceRoom()
{
	setName("Conference Room");
}

/********************
 **Description: This function presents the user with a 
 **menu specific to the Space John is currently in.
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
 ********************/
int ConferenceRoom::promptMenu()
{
	int choice, random;
	McClane m;	//declaring McClane object here
	Game g;
	
	srand((unsigned)time(0));

	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;
	cout << "1. Search the conference room.\n";
	cout << "2. Go to the CEO's office.\n";
	cout << "3. Take the elevator up to the tower restaurant.\n";
	cout << "4. Take the elevator up to the helipad.\n";
	cout << "5. Take the elevator down to the land records office.\n";
	cout << "6. Take the elevator down to the staff breakroom.\n";
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
		cout << "Oh shit, a terrorist was hiding out in the\n";
		cout << "conference room and he has a pistol!\n";
		cout << endl;
		
		if(g.getKnife() == false)
		{
			cout << "With no weapon John quickly snags a book\n";
			cout << "from the conference table and throws it at\n";
			cout << "the terrorist's face!\n";
			cout << endl;

			//John has less of a chance surviving with a book
			random = rand() % 6 + 1;	//return a random # 1-6
			
			if(random == 2 || random == 4)
			{
				cout << "John knocked him out with a book!\n";
				cout << endl;
				cout << "He walks over and finishes the job.\n";
				cout << endl;
				cout << "John McClane -- yippee ki yay mother f*%#$@!\n";
				cout << endl;
			}
			else
			{
				cout << "Shit! John missed!\n";
				cout << "The terrorist fires one shot and\n";
				cout << "kills John instantly!\n";
				cout << endl;
				bool temp = true;
				g.changeDies(temp);
 			}
		}
		if(g.getKnife() == true)
		{
			cout << "John quickly grabs the pocket knife\n";
			cout << "acquired from the dead security guard\n";
			cout << "and throws it at the terrorist's face!\n";
			cout << endl;

			//John has better chance of survival with knife
			random = rand() % 6 + 1;
			
			if(random != 1)
			{
				cout << "John killed the terrorist!\n";
				cout << "The knife hit him square in\n";
				cout << "between the eyes!\n";
				cout << endl;
				cout << "John McClane -- yippee ki yay mother f*%#$@!\n";
			}
			else
			{
				cout << "Shit! John missed!\n";
                                cout << "The terrorist fires one shot and\n";
                                cout << "kills John instantly!\n";
				cout << random << endl;
                                cout << endl;
				bool temp = true;
                                g.changeDies(temp);
			}
		}
	}
	if(choice == 2)
	{
		return 7;
	}
	if(choice == 3)
	{
		return 8;
	}
	if(choice == 4)
	{
		return 9;
	}
	if(choice == 5)
	{
		return 4;
	}
	if(choice == 6)
	{
		return 5;
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

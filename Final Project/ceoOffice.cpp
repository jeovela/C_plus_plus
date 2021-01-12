/*******************
 **Program Name: ceoOffice.cpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the specification file for the 
 **derived class CeoOffice.
 ********************/

#include "Space.hpp"
#include "ceoOffice.hpp"
#include "Game.hpp"
#include "McClane.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/********************
 **Description: This is the constructor for the derived
 **class CeoOffice.
*********************/
CeoOffice::CeoOffice()
{
	setName("CEO's Office");
}

/********************
 **Description: This function presents the user with a 
 **menu specific to the Space John is currently in.
 **Once all 3 security codes are collected a function endGame()
 **is called to end the game.
 ********************/
int CeoOffice::promptMenu()
{
	int choice;
	McClane m;	
	Game g;
		cout << endl;
                cout << "What would you like to do?\n";
                cout << endl;
                cout << "1. Search the CEO's office.\n";
                cout << "2. Go to the conference room.\n";
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
                        int choice2;

                        cout << endl;
                        cout << "You decide to approach?\n";
                        cout << endl;
                        cout << "1. The desk.\n";
                        cout << "2. The bookshelf.\n";
                        cout << "3. The coat rack.\n";

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
				cout << "John goes through the desk and finds\n";
				cout << "nothing but office supplies and a\n";
				cout << "few dirty photos.\n";
				cout << "Blackmail?\n";
				cout << endl;
                        }
                        if(choice2 == 2)
                        {
				cout << "John clears the bookshelf in a rush\n";
				cout << "searching for a security code but\n";
				cout << "nothing is found.\n";
				cout << "Hmmmm, maybe those coat pockets have\n";
				cout << "something.\n";
				cout << endl;
                        }
                        if(choice2 == 3)
                        {
				cout << "John searches the pockets in the\n";
				cout << "brown coat, but nothing.\n";
				cout << "Next, he searches the black coat\n";
				cout << "and wa-la, a security code!\n";
                        	cout << "	~Security Code Found!~	\n";
				cout << endl;
				m.addItem("2nd set of codes");
				bool temp = true;
				g.changeCode2(temp);
			}
                }
		if(choice == 2)
		{
			return 6;
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


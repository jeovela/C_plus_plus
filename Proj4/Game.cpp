/***********************
 **Program Name: Game.cpp
 **Author: Jeovani Vela
 **Date: 2/9/18
 **Description: This is the implementation file for functions related to the
 **game play of Fantasy Fight Club.
**************************/


#include "Game.hpp"
#include "Menu.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "blueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "ListNode.hpp"
#include "Tourney.hpp"

#include <iostream>
#include <cstdlib>	//required for rand()

using std::cout;
using std::cin;
using std::endl;

/********************
 **Description: Function is called after a Character dies and asks user
 **if they want to play again or not. If no, program ends. If yes, game 
 **starts over.
*********************/
void playAgain()
{
	char choice;

	cout << "Would you like to play again or quit?\n";
	cout << "Enter 'P' to \"Play Again or 'Q' \"Quit\".\n";
	cout << endl;
	cin >> choice;

	//input validator
	while(!(toupper(choice) == 'P' || toupper(choice) == 'Q'))
	{
		cin.clear();
		cin.ignore(500, '\n');
		cout << "ERROR! You entered an invalid character.\n";
		cout << "Please enter 'P' to \"Play Again\" or 'Q' to";
		cout << " \"Quit\".\n";
		cin >> choice;
	}

	if(toupper(choice) == 'P')
	{
		//play game again
		Tourney t;
		t.displayMenu();
		t.playGame();
	}

	else if(toupper(choice) == 'Q')
	{	
		//game ends
		cout << endl;	//spacing	
		cout << "Thanks for playing!\n";
		cout << "   and remember...\n";
		cout << endl;
		cout << "The first rule of Fight Club is, you DO NOT talk";
		cout << " about Fight Club. -- Tyler Durden\n";
		cout << endl;
	}
}

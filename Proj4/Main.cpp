/*********************
 **Program Name: Main.cpp
 **Author: Jeovani Vela
 **Date: 2/28/18
 **Description: This is the Main file for proj4, fantasy fight game. User
 **first prompted with a menu to play the game or quit. If user chooses to 
 **quit, program ends. If user decides to play, the displayMenu() function will
 **kick in. User chooses the number of fighters for each team, picks the 
 **characters to fight and gives them nicknames before the games is simulated.
*********************/

#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "blueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "ListNode.hpp"
#include "Tourney.hpp"
#include "LineupQueue.hpp"
#include "LoserStack.hpp"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

int main()
{
	srand((unsigned)time(0));
	
	int val;	//will hold return value from function,startMenu()

	val = startMenu();

	if(val == 1)
	{
		Tourney t;	//create Tourney object
		t.displayMenu();	//set the lineups for both teams.
		t.playGame();
	}
		
	return 0;
}

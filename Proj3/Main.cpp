/*********************
 **Program Name: Main.cpp
 **Author: Jeovani Vela
 **Date: 2/7/18
 **Description: This is the Main file for proj3, fantasy game.
*********************/

#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "blueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Menu.hpp"
#include "Game.hpp"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

int main()
{
	srand((unsigned)time(0));

	playGame();
		
	return 0;
}

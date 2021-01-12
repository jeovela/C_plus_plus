/*******************
 **Program Name: Main.cpp
 **Author: Jeovani Vela
 **Date: 3/11/18
 **Description: This is the main file for my final project in 162.
*******************/

#include "Game.hpp"
#include "Breakroom.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main ()
{
	cout << endl;
	cout << "		       DIE-HARD OKC		\n";
	cout << endl;
	cout << endl;
	cout << "Help! Terrorist have stolen sensitive information and left\n";
	cout << "a bomb in the parking garage of the Devon Tower in downtown\n";
	cout << "Oklahoma City before fleeing in a helicopter off the tower rooftop!\n";
	cout << endl;

	cout << "Luckily NYPD officer John McClane who is in town to watch\n";
	cout << "his favorite NBA team, The OKC Thunder, has seen the news\n";
	cout << "and is making his way to the scene now.\n";
	cout << endl;
	cout << "The FBI and OKC Police have debriefed John on the situation.\n";
	cout << "Game Objective:\n";
	cout << "Search Devon Tower for 3 different security codes\n";
	cout << "needed to diffuse the bomb before time expires.\n";
	cout << "You will have 15 hours to collect all 3 codes.\n";
	cout << endl;
	cout << "Lastly, pay attention for clues in the game!\n";
	cout << endl;
	cout << "John McClane -- yippee ki yay mother f*%#$@!\n";
	cout << endl;

	Game g;	//declare game object
	g.createBuilding();	//setup game links
	g.playGame();

	return 0;
}

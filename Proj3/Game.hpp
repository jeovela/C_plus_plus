/************************
 **Program Name: Game.hpp
 **Author: Jeovani Vela
 **Date: 2/9/18
 **Description: This is the declaration file for functions related to the
 **game play of Fantasy Fight Club.
**************************/

#include "Character.hpp"
#include "Menu.hpp"

void playGame();	//this function will have menu() and create objs

//function has two parameters, a the objects of the Characters created
void attackCharacter(Character *attacker, Character *defender);

void playAgain();	//asks user to play again or quit

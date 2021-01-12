/****************
 **Program Name: Tourney.hpp
 **Author: Jeovani Vela
 **Date: 2/26/18
 **Description: This is the specification file for the class Toruney
****************/

#ifndef TOURNEY_HPP
#define TOURNEY_HPP

#include "LineupQueue.hpp"
#include "LoserStack.hpp"

class Tourney
{
	protected:
		LineupQueue team1;
		LineupQueue team2;
		int round;
		int team1Score;
		int team2Score;
		LoserStack loser1;
		LoserStack loser2;
	public:
		Tourney();
		~Tourney();
		void displayMenu();	//set lineups here
		void playGame();
		void playRound(Character *character1, Character *character2);
		void attackCharacter(Character *attacker, Character *defender);	
		void displayScore();
		void displayWinner();	
};
#endif

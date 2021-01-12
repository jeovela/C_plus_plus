/******************
 **Program Name: Tourney.cpp
 **Author: Jeovani Vela
 **Date: 2/26/18
 **Description: This is the specification file for the class Tourney
*****************/

#include "Tourney.hpp"
#include "Character.hpp"
#include "ListNode.hpp"
#include "LineupQueue.hpp"
#include "LoserStack.hpp"
#include "Game.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************
 **Description: This is the constructor for the class Tourney. 
***********************/
Tourney::Tourney()
{
	team1Score = 0;
	team2Score = 0;
	round = 0;	//round will be iterated in the playRound();
}

/********************
 **Description: This is the destructor for the class Tourney. It
 **calls on the member functions associated with the LoserStack class and
 **LineupQueue class.
***********************/
Tourney::~Tourney()
{
	//deallocate for team1 and loser1
	while(team1.getQueueSize() > 0)
	{
		delete team1.dequeue();
	}
	while(loser1.getStackSize() > 0)
	{
		delete loser1.popStack();
	}

	//deallocate for team2 and loser2
	while(team2.getQueueSize() > 0)
	{
		delete team2.dequeue();
	}
	while(loser2.getStackSize() > 0)
	{
		delete loser2.popStack();
	}
}

/*******************
 **Description: In this function the user is first prompted to select the
 **number of fighters for each team. The function will then use that number
 **to display a do-while loop for each team selection of characters. When the
 **user selects a character he/she will be prompted to provide a name. It 
 **will then assign the correct sub-class obj to a Character pointer to be 
 **added to the list via another function, the addCharacter(Character *c); 
 **Each character is also set to either Team1 or Team2 which are 
 **LineupQueue objects. This function will basically set the lineups for
 **both teams. Once set, the game calls on a function, playGame() to 
 **simulate the game.
********************/
void Tourney::displayMenu()
{
        int size;

        cout << endl;

        cout << "           ____________________________________________\n";
        cout << "          | Welcome to the Fantasy Fight Club Tourney |\n";
        cout << "          ---------------------------------------------\n";
        cout << endl;
        cout << endl;

        cout << "Enter the number of fighters for each team.\n";
        cin >> size;

	//input validation
	while(size <= 0)
        {
                cin.clear();
                cin.ignore(500, '\n');
		cout << endl;
                cout << "You entered an incorrect selection.\n";
                cout << "Enter a positive number greater than zero.\n";
                cin >> size;
        }


        if(size > 0)
        {
                size *= 2;
        }

        int temp, choice;
        temp = size;
        temp /= 2;
	
    cout << endl;
    cout << "Please select " << size << " characters for the tournament.\n";
    cout << "The first " << temp << " selected will be Team 1.\n";
    cout << "The remaining " << temp << " selected will be Team 2.\n";
	cout << endl;

	int count = 0;	//counter

	cout << "1. Barbarian\n";
	cout << "2. Vampire\n";
	cout << "3. Blue Men\n";
	cout << "4. Medusa\n";
	cout << "5. Harry Potter\n";
	cout << endl;

	string newName;
	//team 1 selection
	cout << "_________\n";
	cout << "|Team 1 |\n";
	cout << "---------\n";
	do
	{
		cin >> choice;
		//input validation
		while(choice < 1 || choice > 5)
	        {
        	        cin.clear();
               		cin.ignore(500, '\n');
                	cout << "You did not enter a valid choice. Select a number";
			cout << " 1 through 5.\n";
                	cin >> choice;
        	}

		if(choice == 1)
		{
			cout << "Enter a nickname for this fighter.\n";
			cin.ignore();	//included the ignore die to \n above
                        getline(cin,newName);
			Character *character = new Barbarian(newName);
			//function call adds fighter to team1
			team1.addCharacter(character);  
			count++;
			cout << endl;
		}
		if(choice == 2)
       	 	{
			cout << "Enter a nickname for this fighter.\n";
                        cin.ignore();
                        getline(cin,newName);
                        Character *character = new Vampire(newName);
			team1.addCharacter(character);  
			count++;
			cout << endl;
       		}
		if(choice == 3)
        	{
			cout << "Enter a nickname for this fighter.\n";
                        cin.ignore();
                        getline(cin,newName);
                        Character *character = new BlueMen(newName);
			team1.addCharacter(character);  
			count++;
			cout << endl;
        	}
		if(choice == 4)
        	{
                        cout << "Enter a nickname for this fighter.\n";
			cin.ignore();
                        getline(cin,newName);
                        Character *character = new Medusa(newName);
			team1.addCharacter(character);  
			count++;
			cout << endl;
        	}
		if(choice == 5)
        	{	
			cout << "Enter a nickname for this fighter.\n";
                        cin.ignore();
                        getline(cin,newName);
                        Character *character = new HarryPotter(newName);
			team1.addCharacter(character);
			count++;
			cout << endl;
        	}
	
	}while(count < temp);


	count = 0;	//must reset counter
	
	//team 2 selection
        cout << "_________\n";
        cout << "|Team 2 |\n";
        cout << "---------\n";
        do
        {
                cin >> choice;

		//input validation
		while(choice < 1 || choice > 5)
                {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "You did not enter a valid choice. Select a number";
                        cout << " 1 through 5.\n";
                        cin >> choice;
                }
	
                if(choice == 1)
                {
			cout << "Enter a nickname for this fighter.\n";
                        cin.ignore();
                        getline(cin,newName);
                        Character *character = new Barbarian(newName);
                	//funcation call adds fighter to team2
			team2.addCharacter(character);  
			count++;
			cout << endl;        
                }	
                if(choice == 2)
                {
			cout << "Enter a nickname for this fighter.\n";
                        cin.ignore();
                        getline(cin,newName);
                        Character *character = new Vampire(newName);
                	team2.addCharacter(character);
                        count++;
                        cout << endl;
		}
                if(choice == 3)
                {
			cout << "Enter a nickname for this fighter.\n";
                        cin.ignore();
                        getline(cin,newName);
                        Character *character = new BlueMen(newName);
                	team2.addCharacter(character);
                        count++;
                        cout << endl;
		}
                if(choice == 4)
                {
			cout << "Enter a nickname for this fighter.\n";
                        cin.ignore();
                        getline(cin,newName);      
	        	Character *character = new Medusa(newName);
                	team2.addCharacter(character);
                        count++;
                        cout << endl;
		}

		if(choice == 5)
                {
			cout << "Enter a nickname for this fighter.\n";
                        cin.ignore();
			getline(cin,newName);
			Character *character = new HarryPotter(newName);
                	team2.addCharacter(character);
                        count++;
                        cout << endl;
		}

        }while(count < temp);

	//LINEUPS ARE SET!
}

/*********************
 **Description: This function is called in Main right after the displayMenu()
 **function which sets the lineups for each team. This function will run the 
 **fantasy fighting tournament until one team no longer has any characters
 **available to continue fighting.
*********************/
void Tourney::playGame()
{

	while(team1.getQueueSize() > 0 && team2.getQueueSize() > 0)
	{
		playRound(team1.getCharacter(), team2.getCharacter());
	
		//if Character on team1 dies	
		if(team1.getCharacter()->isDead())
		{
		//removes dead Character from LineupQueue and moved to Stack
			loser1.addCharacter(team1.dequeue());
			team2.getCharacter()->restoreStrength();
			team2.shiftQueue();	//winner moves to back of Queue
			team2Score++;	//team 2 gets point
			
		}
		//if character on team 2 dies
		else if(team2.getCharacter()->isDead())
		{
			loser2.addCharacter(team2.dequeue());
			team1.getCharacter()->restoreStrength();
			team1.shiftQueue();
			team1Score++;
		}
		displayScore();	//function call
	}

	displayWinner();	//display the winner of the Tournament
	//ask to display loser stack
	playAgain();	//ask to play again
}

/*********************
 **Description: This function performs a round in the tournament. It takes 
 **pointers to two Character objects, then will randomly set which
 **Character/fighter will fight attack first. It will display information
 **about the round at the end.
*******************/
void Tourney::playRound(Character *character1, Character *character2)
{
	int random;
	random = rand() % 2 + 1;	//returns a rand # either 1 or 2 

	//simulate round until a Character/fighter dies
	while(!character1->isDead() && !character2->isDead())
	{
		if(random == 1)	//character 1 attacks first
		{
			attackCharacter(character1, character2);
		}	
		else if (random == 2)	//character2 attacks first
		{
			attackCharacter(character2, character1);
		}
		//swap attackers based on random num
		if(random == 1)	//character 2 attacks first now
		{
			attackCharacter(character2, character1);
		}
		else if(random == 2)	//character 1 attacks first now
		{	
			attackCharacter(character1, character2);
		}
	
	}

	//if character1 dies and character2 wins
	if(character1->isDead() && !character2->isDead())
	{
		round++;	//round iterated

		cout << "Round " << round << ": Team 1 " << character1->getName() << " ";
		cout << character1->getId() << " vs. " << "Team 2 " << character2->getName() << " ";
		cout << character2->getId() << ", " << character2->getName();
		cout << " " << character2->getId() << " Won!" << endl;
		cout << endl;
	}

	//if character1 wins and character2 dies
	else if(!character1->isDead() && character2->isDead())
        {
		round++;	//round iterted

                cout << "Round " << round << ": Team 1 " << character1->getName() << " ";
                cout << character1->getId() << " vs. " << "Team 2 " << character2->getName() << " ";
                cout << character2->getId() << ", " << character1->getName();
                cout << " " << character1->getId() << " Won!" << endl;
		cout << endl;
	}
}

/*********************
 **Description: This function takes the pointers to the attack and defender
 **Characters and uses them roll their respective attackRoll() or defenseRoll()
********************/
void Tourney::attackCharacter(Character *attacker, Character *defender)
{
	defender->damageInflicted(attacker->attackRoll(), defender->defenseRoll());	
}

/********************
 **Description: This function prints the score of the tournament.
***********************/
void Tourney::displayScore()
{
	cout << "_________________\n";
	cout << "|Team 1 score: " << team1Score << "|\n";
	cout << "|Team 2 score: " << team2Score << "|\n";
	cout << "-----------------\n";
	cout << endl;
}

/********************
 **Description: This function will display the winner of the tournament. 
 **It will also ask the user if they want to display the LoserStack.
***********************/
void Tourney::displayWinner()
{
	char choice;

	if(team1Score > team2Score)
	{
		cout << "____________________________\n";
		cout << "|Team 1 Won the Tournament!|\n";
		cout << "----------------------------\n";
		cout << endl;
		
		cout << "Would you like to display the content in the loser pile?\n";
		cout << "Choose 'Y' for Yes and 'N' for No.\n";
		cin >> choice;
		cout << endl;
		
		//input validator		
		while(!(toupper(choice) == 'Y' || toupper(choice) == 'N'))
		{
			cin.clear();
			cin.ignore(500, '\n');
			cout << "ERROR! You entered an invalid character.\n";
			cout << "Please enter 'Y' for Yes or 'N' for No.\n";
			cin >> choice;
			cout << endl;
		}
		if(toupper(choice) == 'Y')
		{
			loser2.printLoserStack();
			cout << endl;
		}

	}
	else if(team1Score < team2Score)
	{
		cout << "____________________________\n";
                cout << "|Team 2 Won the Tournament!|\n";
                cout << "----------------------------\n";
                cout << endl;

		cout << "Would you like to display the content in the loser pile?\n";
                cout << "Choose 'Y' for Yes and 'N' for No.\n";
                cin >> choice;
                cout << endl;

                while(!(toupper(choice) == 'Y' || toupper(choice) == 'N'))
                {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "ERROR! You entered an invalid character.\n";
                        cout << "Please enter 'Y' for Yes or 'N' for No.\n";
                        cin >> choice;
                        cout << endl;
                }
                if(toupper(choice) == 'Y')
                {
                        loser1.printLoserStack();
                        cout << endl;
                }

	}
	else if(team1Score == team2Score)
	{
		cout << "_____________\n";
		cout << "|It's a tie!|\n";
		cout << "-------------\n";
		cout << endl;

		cout << "Would you like to display the content in the loser pile?\n";
                cout << "Choose 'Y' for Yes and 'N' for No.\n";
                cin >> choice;
                cout << endl;

                while(!(toupper(choice) == 'Y' || toupper(choice) == 'N'))
                {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "ERROR! You entered an invalid character.\n";
                        cout << "Please enter 'Y' for Yes or 'N' for No.\n";
                        cin >> choice;
                        cout << endl;
                }
                if(toupper(choice) == 'Y')
                {
			//print both teams losers
			loser1.printLoserStack();
                        loser2.printLoserStack();
                        cout << endl;
                }

	}
}


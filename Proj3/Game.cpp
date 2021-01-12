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

#include <iostream>
#include <cstdlib>	//required for rand()

using std::cout;
using std::cin;
using std::endl;

/*****************************
 **Description: This function is called in Main. It first contains a function
 **call to display the menu to the user so he/she may choose the Characters 
 **to fight. After choosing the displayMenu() returns an array[2] which contains
 **numbers that will correlate with a number here in order to create the correct
 **Character obj and assign it to a pointer type Character. Next this function
 **will determine who will attack first before calling on the attackCharacter()
 **function.
 *******************************/
void playGame()
{
	Character *character1 = NULL;
        Character *character2 = NULL;

	int *value;     //will hold return value which is an array[2]
        value = displayMenu();  //function call to display menu

	//using the array that was returned to determine #'s in subscript
	//in order to create the correct Character obj
	
	//create obj for character1 in value[0]
	if(value[0] == 1)
        {
                character1 = new Barbarian;
        }
        else if(value[0] == 2)
        {
                character1 = new Vampire;
        }
        else if(value[0] == 3)
        {
                character1 = new BlueMen;
        }
        else if(value[0] == 4)
        {
                character1 = new Medusa;
        }

        else if(value[0] == 5)
        {
                character1 = new HarryPotter;
        }

	//create obj for character2 in value[1]
	if(value[1] == 1)
        {
                character2 = new Barbarian;
        }
        else if(value[1] == 2)
        {
                character2 = new Vampire;
        }
        else if(value[1] == 3)
        {
                character2 = new BlueMen;
        }
        else if(value[1] == 4)
        {
                character2 = new Medusa;
        }

        else if(value[1] == 5)
        {
                character2 = new HarryPotter;
        }

	//determine which Character will attack first and pass it 
	//in the parameters of the attackCharacter() function
	
	int random;
        random  = rand() % 6 + 1;       //return a random # between 1-6

	int counter = 1;	//used to display rd

        if(random == 2 || random == 4 || random == 6)
        {
		//character2 attacks first -- function call
		//keep calling function until Character dies
		while(!character1->isDead() && !character2->isDead())
		{
			//display rd before each function call
			cout << endl;		//spacing
			cout << "Round: " << counter << endl;
			counter++;
			cout << endl;
			
			//function call
			attackCharacter(character2, character1);
			
			if(character1->isDead() && !character2->isDead())
                        {	
				cout << endl;
                                cout << character1->getName() << " has died!\n";
                                cout << character2->getName() << " has won!\n";
				cout << endl;
				cout << "	___________\n";
				cout << "	|GAME OVER|\n";
				cout << "	-----------\n";
				playAgain();
				break;
                        }

                        else if(!character1->isDead() && character2->isDead())
                        {
				cout << endl;
                                cout << character2->getName() << " has died!\n";
                                cout << character1->getName() << " has won!\n";
                        	cout << endl;
				cout << "       ___________\n";
                                cout << "       |GAME OVER|\n";
                                cout << "       -----------\n";
                                playAgain();
				break;
			}
			
			//cout << endl;	
			//cout << "Round: " << counter << endl;
                        //counter++;
                        //cout << endl;
		
			//function call
			attackCharacter(character1, character2);

			if(character1->isDead() && !character2->isDead())
			{
				cout << endl;
				cout << character1->getName() << " has died!\n";
				cout << character2->getName() << " has won!\n";
				cout << endl;
				cout << "       ___________\n";
                                cout << "       |GAME OVER|\n";
                                cout << "       -----------\n";
                                playAgain();
				break;
			}

			else if(!character1->isDead() && character2->isDead())
			{
				cout << endl;
				cout << character2->getName() << " has died!\n";
				cout << character1->getName() << " has won!\n";
				cout << endl;
				cout << "       ___________\n";
                                cout << "       |GAME OVER|\n";
                                cout << "       -----------\n";
                                playAgain();
				break;
			}
			
		}
	}

	else if(random == 1 || random == 3 || random == 5)
	{
		//character1 attacks first -- function call
		//keep calling function until a Character dies
		while(!character1->isDead() && !character2->isDead())
                {
			cout << endl;
			cout << "Round: " << counter << endl;
                        counter++;
                        cout << endl;
			
			//function call
                        attackCharacter(character1, character2);
			
			if(character1->isDead() && !character2->isDead())
                        {
                                cout << endl;
                                cout << character1->getName() << " has died!\n";
                                cout << character2->getName() << " has won!\n";
                                cout << endl;
				cout << "       ___________\n";
                                cout << "       |GAME OVER|\n";
                                cout << "       -----------\n";
				playAgain();
				break;
                        }

                        else if(!character1->isDead() && character2->isDead())
                        {
                                cout << endl;
                                cout << character2->getName() << " has died!\n";
                                cout << character1->getName() << " has won!\n";
                                cout << endl;
				cout << "       ___________\n";
                                cout << "       |GAME OVER|\n";
                                cout << "       -----------\n";
                        	playAgain();
				break;
			}

			//cout << endl;
			//cout << "Round: " << counter << endl;
                        //counter++;
                        //cout << endl;

			//function call
			attackCharacter(character2, character1);
			
			if(character1->isDead() && !character2->isDead())
                        {
                                cout << endl;
                                cout << character1->getName() << " has died!\n";
                                cout << character2->getName() << " has won!\n";
                                cout << endl;
				cout << "       ___________\n";
                                cout << "       |GAME OVER|\n";
                                cout << "       -----------\n";
                        	playAgain();
				break;
			}

                        else if(!character1->isDead() && character2->isDead())
                        {
                                cout << endl;
                                cout << character2->getName() << " has died!\n";
                                cout << character1->getName() << " has won!\n";
                                cout << endl;
				cout << "       ___________\n";
                                cout << "       |GAME OVER|\n";
                                cout << "       -----------\n";
                        	playAgain();
				break;
			}

                }

	}

	
	//deallocate memory
	//Programmer's note: Must have [] as pointer is pointing to an array
    delete [] value;
    value = NULL;

    delete character1;
    delete character2;

    character1 = NULL;
    character2 = NULL;
}

/*****************************
 **Description: This function is called in the playGame(). Its parameters
 **include 2 pointers of type Character. The pointer pointing to defender
 **calls on the damageInflicted(int, int) function. The parameters for the 
 **damageInflicted function are the rolls determined in each sub-class
 **via virtual functions attackRoll() & defenseRoll().
******************************/
void attackCharacter(Character *attacker, Character *defender)
{
	cout << endl;	//spacing
	defender->damageInflicted(attacker->attackRoll(), defender->defenseRoll());
}


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
		playGame();	//function call
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

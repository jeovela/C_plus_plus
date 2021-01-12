/***************
 **Program Name: Main.cpp
 **Author: Jeovani Vela
 **Date: 1/13/18
 **Description: This is the main file. It contains a series of function calls
 **that will fulfill the simulation of Langston's Ant. It also contains an infinite
 **for loop that allows the user the choice to play again or quit.
*******************/

#include "menuFunction.hpp"
#include "Ant.hpp"

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	char choice, option;

	//function call w/ function returning a char 
	choice = startMenu();

	//if startMenu function returns a start value, 's', optionMenu kicks in
	if(toupper(choice) == 'S')
	{
		//function call w/ Ant obj sim serving as return value
		//Ant obj also declared
		Ant sim = optionMenu();
		
		//will print board - must be called in {} to stay in scope
		//will display placement of ant(*) and steps starting at 0
		sim.printBoard();

		//set the number of steps from the user to counter
		int counter;
		counter = sim.getNsteps();
		
		//print function moveAnt until number of steps is complete
		for(int i=0; i<counter; i++)
		{
			sim.moveAnt();
		}


	//ask to play again
        for(;;)    //infinite for loop
        {
            cout << "Would you like to play again? Enter 'S' to play again";
            cout << " or 'Q' to quit.\n";
            cin >> option;

            while(!(toupper(option) == 'S' || toupper(option) == 'Q'))
        	{
        		cin.clear();
        		cin.ignore(500, '\n');
       			cout << "ERROR! You entered an invalid character.\n";
            		cout << "Please enter 'S' to \"Start\" or 'Q' to \"Quit\".\n";
            		cin >> option;
        	}		

            if(toupper(option) == 'S')
            {
                Ant sim = optionMenu();
                sim.printBoard();

                int count;
                count = sim.getNsteps();

                for(int i=0; i<count; i++)
                {
                        sim.moveAnt();
                }
            }
            else if(toupper(option) == 'Q')
            {
                break;
            }
        }
	}

	return 0;
}

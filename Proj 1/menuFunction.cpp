/*******************
 **Program Name: menuFunction.cpp
 **Author: Jeovani Vela
 **Date: 1/13/18
 **Description: This is the implementation file for the menuFunction. It contains a two functions, one
 **to ask the user to play or quit, and another that takes in user inputs from a menu.
 ********************/

#include "menuFunction.hpp"
#include "Ant.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*************
 **Description: This function presents the user w/ two options, start or quit
 **the program. It validates the user's input and if 's' or 'q' is input by
 **user, the function returns the value to main to determine if next function is
 **required to perform Ant simulator.
*************/
char startMenu()
{
	char input;

        cout << "Hello, welcome to the Langston Ant Simulator.\n";
        cout << "To begin type 'S' to \"Start\" or 'Q' to \"Quit\".\n";
        cin >>input;

        //input validation
         while(!(toupper(input) == 'S' || toupper(input) == 'Q'))
        {
        	cin.clear();
        	cin.ignore(500, '\n');
       		cout << "ERROR! You entered an invalid character.\n";
            cout << "Please enter 'S' to \"Start\" or 'Q' to \"Quit\".\n";
            cin >>input;
	}

	if(toupper(input) == 'S' || toupper(input) == 'Q')
	{
		return input;
	}

}

/*************
 **Description: This function presents the user with options to input data
 **required for the ant simulation. User inputs will be validated. The function
 **will have constructor at the end to make an Ant obj.
**************/
Ant optionMenu()
{
	int row, col, steps, startRow, startCol;
	string startDir;
	int choice;
	int count = 0;	//counter

    do
    {
        cout << "***********Langston's Ant Menu***********\n";
		cout << "1. Enter the number of rows for the board.\n";
		cout << "2. Enter the number of columns for the board.\n";
		cout << "3. Enter the number of steps during simulation.\n";
		cout << "4. Enter the starting row of the ant.\n";
		cout << "5. Enter the starting column of the ant.\n";
		cout << "6. Enter the starting direction for the ant --";
		cout << "up, down, left, right.\n";
		cout << "___________Enter your selection___________ \n";   
		cin >> choice;
	   
		//input validation
		while(!(choice >= 1 && choice <= 6)) //changed setup
		{
		cin.clear();	//clear error flags
		cin.ignore(500,'\n');	//ignore chars
		cout << "You entered a wrong selection. Please enter a";
		cout << " number 1-6.\n";
		cin >> choice;
		}
		
		//using counter to control do while loop. Once 6 choices 
		//have been selected, do while will cease and Ant obj returned
		if(choice >= 1 && choice <= 6)
		{
			count = count + 1;
		}

		if(choice == 1)
		{
			cout << "Enter the number of rows on the board.\n";
			cout << "Number of rows cannot be less than 3.\n";
			cin >> row;
			while(row < 3) //if # of rows is less than 3
                        {
                                cin.clear();
                                cin.ignore(500,'\n');
                                cout << "The number of rows must be greater";
				cout << " than three.\n";
                                cin >> row;
                        }

		}

		if(choice == 2)
		{
			cout << "Enter the number of columns on the board.\n";
			cout << "Number of columns cannot be less than 3 or";
			cout << " less than the number of rows.\n";
			cin >> col;
			//if # of cols is less than # of rows or less than 3
			while(col < row || col < 3)
			{
				cin.clear();
				cin.ignore(500,'\n');
				cout << "The number of columns cannot be less";
				cout << " than the number of rows. Please";
				cout << " enter a number greater or equal to";
				cout << " the number of rows or at least 3.\n";
				cin >> col;
			}
		}

		if(choice == 3)
		{
			cout << "Enter the number of steps for the simulation.\n";
			cin >> steps;
			while(steps <= 0) //if # of steps is less than or = to 0
                        {
                                cin.clear();
                                cin.ignore(500,'\n');
                                cout << "The number of steps must be greater";
                                cout << " than one.\n";
                                cin >> steps;
                        }

		}

		if(choice == 4)
		{
			cout << "Enter the starting row for the ant.\n";
			cin >> startRow;
			//if startRow is > than row or != to int data type
			//or if startRow is less than 0
			while(startRow > row || !cin || startRow < 0)
                        {
                                cin.clear();
                                cin.ignore(500,'\n');
                                cout << "The starting row must be a number not";
                                cout << " greater than the number of rows.\n";
                                cin >> startRow;
                        }

		}

		if(choice == 5)
		{
			cout << "Enter the starting column for the ant.\n";
			cin >> startCol;
			//if startCol is > than row or != to int data type
			//or if startCol less than  0
			while(startCol > col || !cin || startCol < 0) 
                        {
                                cin.clear();
                                cin.ignore(500,'\n');
                                cout << "The starting col must be a number not";
                                cout << " greater than the number of columns.\n";
                                cin >> startCol;
                        }
		}

		if(choice == 6)
		{
			cout << "Enter the starting direction for the ant --";
			cout << "up, down, left, right.\n";
			cin >> startDir;
            //if input does not match up, down, left or right
			while(!(startDir == "up" || startDir == "down" || startDir == "left" || startDir == "right"))
                        {
                                cin.clear();
                                cin.ignore(500,'\n');
                                cout << "You must enter either up, down, left";
				cout << " or right.\n";
                                cin >> startDir;
                        }

		}

	}while(count < 6); 

	//once all inputs are filled, Ant obj is to be created and initalized
	//return statement contains a contructor for the class Ant
	if(count == 6)
	{
		return Ant(row, col, steps, startRow, startCol, startDir);	
	}
}

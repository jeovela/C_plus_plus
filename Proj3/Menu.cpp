/*********************
 **Program Name: Menu.cpp
 **Author: Jeovani Vela
 **Date: 2/8/18
 **Description: This is the implementation file for the function display
 **menu.
**********************/


#include "Menu.hpp"

#include <iostream>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::set;

int* displayMenu()
{
	int selections;
	
	int *array;	//used to hold selections from user
	int size = 2;	//size of array will be two

	int x = 1;

	cout << endl;	//spacing
	cout << "           _________________________________\n";
	cout << "	   | Welcome to Fantasy Fight Club |\n";
	cout << "	   ---------------------------------\n";
	cout << endl;
	cout << endl;	//spacing

	cout << "Please choose 2 characters from below to fight one another.\n";
	cout << endl;

	cout << "1. Barbarian\n";
	cout << "2. Vampire\n";
	cout << "3. Blue Men\n";
	cout << "4. Medusa\n";
	cout << "5. Harry Potter\n";
	cout << endl;	//spacing

	//dynamically allocate memory for an array to hold the two selections
	array = new int[size];
	
	for(int i=0; i<size; i++)
	{
		cin >> array[i];
		
		//input validator - check if # 1-5 is entered
		while(array[i] < 1 || array[i] > 5)
		{
			cin.clear();
			cin.ignore(500, '\n');
			cout << "You did not enter a valid number. Enter a ";
			cout << "number 1-5.\n";
			cin >> array[i];
				
		}
	}

	//check to make sure user did not input the same # twice
	/*int temp;

	temp = array[0];	//assign subscript[0] to temp
	
	if(array[1] == temp)
	{
		//do-while loop will continue if user continues to input same 
		//Character # or if # input is less than 1 or greater than 5
		do
		{
			cout << endl;	//spacing
			cout << "You've already selected that character.\n";
                       	cout << "Choose another character 1-5.\n";	
			cin >> array[1];
			cout << endl;	//spacing
		}while(array[1] == temp || (array[1] < 1 || array[1] > 5));

	}*/		

	//return array with values
	return array;

	//deallocate memory
	delete [] array;
	
	array = NULL;
}

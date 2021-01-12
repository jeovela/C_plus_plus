/*************
 **Program Name: Ant.cpp
 **Author: Jeovani Vela
 **Date: 1/13/18
 **Description: This is the implementation file for the class Ant. It has a couple member functions that
 **will enable the ant simulation to be performed. It also has a defult constructor just in case.
*************/

#include "Ant.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

/***************
 **Description: This is the defualt constructor. All member variables are 
 **initialized to the minimums, 3. W/ starting direction down.
***************/
Ant::Ant()
{
	nRow = 3;
	nCol = 3;
	nSteps = 3;
	startingRow = 3;
	startingCol = 3;
	direction = "down";
	color = " ";
	count = 0;
	
	//private member function call
	board = makeBoard(nRow, nCol, startingRow, startingCol);
}

/************
 **Description: A constructor with 6 parameters and contains a member function.
 **It sets the user inputs to the class member variables before calling on a 
 **class member function to build the board based on user inputs passed as 
 **arguments. The start color is white since board is all white. Counter is
 **initialized to 0 for iterations.
***************/
Ant::Ant(int r, int c, int s, int sR, int sC, string d)
{
	nRow = r;
	nCol = c;
	nSteps = s;
	startingRow = sR;
	startingCol = sC;
	direction = d;
	
	color = " ";	//start will always be white since board is all white 
	count = 0;	//counter

	//private member function call - user inputs are passed to make board
	board = makeBoard(nRow, nCol, startingRow, startingCol);
}
	
/****************
 **Description: This function makes the board for the ant simulation. It takes
 **the user inputs of row, col, startingRow & startingCol. row and col set the
 **height x length of the board, startingRow & startingCol are used to set the
 **placement of the ant (*).Using a pointer to pointer of strings.
****************/
string** Ant::makeBoard(int nRow, int nCol, int startingRow, int startingCol)
{
	//dynamically allocate memory for board, using user input to make r&c
	board = new string*[nRow];
        for(int i=0; i<nRow; i++)
        {
                board[i] = new string[nCol];
        }

	//make board full of white spaces
	for(int i=0; i<nRow; i++)
        {
                for(int j=0; j<nCol; j++)
                        board[i][j] = color;    //color is " "
        }

	//place ant (*) at starting row and col from user inputs
	for(int i=0; i<nRow; i++)
	{
		for(int j=0; j<nCol; j++)
		{
			if((i == startingRow) && (j == startingCol))
			{
				board[i][j] = "*";
			}
		}
	}

	return board;
}

/**********
 **Description: This function prints the board, with all spaces set to white
 **(" ") to start, it also prints out " |" to give the board dimensions and the 
 **starting location of the ant (*). Also prints out # of steps & the direction
 **the ant is facing for each iteration when called upon.
 **Note to programmer:
 **All board print outs are on the same line followed by <<. Another way to cout
 **would cause board issues
************/
void Ant::printBoard()
{
	//using member variables to display direction & num of steps performed
	cout << "Ant facing: " << direction << endl;
        cout << "Step #" << count << endl;
	
	for(int i=0; i<nRow; i++)
	{
		for(int j=0; j<nCol; j++)
			cout << " " << "|" << board[i][j];
			cout << endl;	
	}

	cout << endl;
}

/****************
 **Description: This function changes the direction and moves the ant (*), while **also mainting the switiching of the color on the board, keeping track of the
 **number of steps and printing the board function after each iteration. The     **function also has a return value of bool that returns a T/F to determine end.
 **The counter (count) which was set to 0 in the constructor & will keep track
 ** of the steps based on the user input of how many steps. It will return true  **once all steps are complete.
 **Function rules: If ant is on white space, turn right 90 degrees and change
 **the space to black. If ant is on black space, turn left 90 degrees and change
 **the space to white.
****************/
bool Ant:: moveAnt()
{
	int pastRow = startingRow;
	int pastCol = startingCol;
	string pastColor = color;

	//rotate ant (*) based on color on board & starting direction
	//if white
	if(color == " ")
	{
		if(direction == "up")
		{
			direction = "right";
		}

		else if(direction == "down")
		{
			direction = "left";
		}

		else if(direction == "right")
		{
			direction = "down";
		}

		else if(direction == "left")
		{
			direction = "up";
		}
	}
	
	//if black
	else if(color == "#")
	{
		if(direction == "up")
		{
			direction = "left";
		}
	
		else if(direction == "down")
		{
			direction = "right";
		}

		else if(direction == "right")
		{
			direction = "up";
		}

		else if(direction == "left")
		{
			direction = "down";
		}
	}

	//move ant (*) based on the direction it is facing
	if(direction == "up")
	{
		startingRow--;	//minus 1
	}

	else if(direction == "down")
	{
		startingRow++;	//plus 1
	}

	else if(direction == "right")
	{
		startingCol++;
	}

	else if(direction == "left")
	{
		startingCol--;
	}

	//Edge case logic - everytime ant (*) reaches the border of the board
	//its location is mirrored on the opposite end so simulator continues
	if(startingRow == nRow)
	{
		startingRow = 0;
	}

	if(startingRow == -1)
	{
		startingRow = nRow - 1;
	}

	if(startingCol == nCol)
	{
		startingCol = 0;
	}

	if(startingCol == -1)
	{
		startingCol = nCol - 1;
	}

	//ant's color on the board is tracked
	color = board[startingRow][startingCol];

	//flip the color on the board
	//if past color on board is white, flip to black
	if(pastColor == " ")
	{
		board[pastRow][pastCol] = "#";
	}

	//if past color on board is black, flip to white
	else if(pastColor == "#")
	{
		board[pastRow][pastCol] = " ";
	}

	//change the placement of the ant (*)
	board[startingRow][startingCol] = "*";

	count++;

	//member function called
	printBoard();

	//counter - will return T/F
	if(count < nSteps)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**************
 **Description: This is the destructor. Will delete dynamically allocated memory **specifically, **board.
**************/
Ant::~Ant()
{
	for(int i=0; i<nRow; i++)
	{
		delete [] board[i];
	}

	delete [] board;

	board = NULL;
}

/*************
 **Description: This is a getter function. Returns the number of steps.
************/
int Ant::getNsteps()
{
	return nSteps;
}

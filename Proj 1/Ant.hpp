/***************
 **Program Name: Ant.hpp
 **Author: Jeovani Vela
 **Date: 1/13/18
 **Description: This is the specification file for the class Ant.
***************/

#ifndef ANT_H
#define ANT_H

#include<string>

using std::string;

class Ant
{
	private:
		int nRow;
		int nCol;
		int nSteps;
		int startingRow;
		int startingCol;
		int count;	//counter to track steps
		string direction;
		string color;
		string **board;
		string **makeBoard(int nRow, int nCol, int startingRow, int startingCol);
    
	public:
		Ant();  //default constructor
		//constructor w/ 6 parameters
		Ant(int r, int c, int s, int sR, int sC, string d);
		void printBoard();
		~Ant();
		bool moveAnt();
		int getNsteps();
};
#endif

/******************
 **Program Name: LoserStack.cpp
 **Author: Jeovani Vela
 **Date: 2/28/18
 **Description: This is the implementation file for the class LoserStack. 
 **This stack serves as an ADT which "contains" the losers from the 
 **fighting tournament.
*********************/

#include "LoserStack.hpp"
#include "LineupQueue.hpp"
#include "ListNode.hpp"
#include "Tourney.hpp"

#include <iostream>

using std::cout;
using std::endl;

/********************
 **Description: This is the constructor for the class LoserStack. It initializes
 **the pointers to nullptr and sets the size of the stack at 0.
***********************/
LoserStack::LoserStack()
{
	stackSize = 0;
	top = nullptr;
	bottom = nullptr;
}

/*********************
 **Description: This is the destructor for the class LoserStack. It will 
 **deallocate memory for every node in the stack. "LIFO"
***********************/
LoserStack::~LoserStack()
{
	if(stackSize > 0)
	{
		ListNode *clrNode;
		clrNode = top;	

		while(clrNode->getPrev() != nullptr)
		{
			clrNode = clrNode->getPrev();
			delete clrNode->getNext();
		}	
		delete clrNode;
	}
}

/********************
 **Description: This function takes a pointer to a Character and adds it to 
 **the top of the list. The Character sent in the parameters is the loser from
 **the round in the tournament.
***********************/
void LoserStack::addCharacter(Character *loser)
{
	ListNode *node;		//create a node for the stack
	node = new ListNode(loser);	//assign the new node the loser

	//if stack is empty, the top and bottom pointer point to new node
	if(stackSize == 0)
	{
		top = node;
		bottom = node;
	}

	else	//add the new node on top of the prev node created. 
	{
		top->setNext(node);	//set the new node as next in the stack
		node->setPrev(top);	//set node's prev to be the top
		top = node;	//set top pointer to point to new node created
	}

	stackSize++;	//counter to have program keep track of stack's size
}

/********************
 **Description: This function will pop off the top node of the stack. It
 **returns a pointer to a Character at the top of the stack and remove it. 
***********************/
Character* LoserStack::popStack()
{
	if(stackSize > 0)
	{
		ListNode *popNode;
		popNode = top;

		Character *popChar;	//popChar short for popCharacter
		popChar = top->getCharacter();
		if(top->getPrev() != nullptr)
		{
			top = top->getPrev();
			top->setNext(nullptr);
		}
		delete popNode;
		stackSize--;
		return popChar;
	}
}

/*****************
 **Description: A getter function that returns the Stack's size.
****************/
int LoserStack::getStackSize()
{
	return stackSize;
}

/*****************
 **Description: This function will print the losers that are currently in the Stack.
*****************/
void LoserStack::printLoserStack()
{
	if(stackSize > 0)
	{
		ListNode *printNode;	//declare a node
		printNode = top;	//assign it the top of the stack

		cout << "     LOSER STACK     \n";
		cout << "---------------------\n";
		for(int i=0; i< stackSize; i++)
		{
			cout << printNode->getName() << ", ";
			cout << printNode->getId() << endl;
			printNode = printNode->getPrev();
		}
	}
}

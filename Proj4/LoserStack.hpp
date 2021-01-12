/********************
 **Program Name: LoserStack.hpp
 **Author: Jeovani Vela
 **Date: 2/28/18
 **Description: This is the specification file for the class LoserStack. 
 **The LoserStack acts as a container where the losers from a round of fighting are
 **moved to and stored and later displayed if user chooses to. Stack is a "last-in,
 **first-out" container. "LIFO"
*********************/

#ifndef LOSERSTACK_H
#define LOSERSTACK_H

#include "Character.hpp"
#include "ListNode.hpp"

class LoserStack
{
	protected:
		int stackSize;
		ListNode *top;
		ListNode *bottom;
	public:
		LoserStack();
		~LoserStack();
		//add losing Character/fighter to the stack
		void addCharacter(Character *loser);
		Character* popStack();
		int getStackSize();
		void printLoserStack();
};
#endif

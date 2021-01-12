/****************
 **Program Name: ListNode.hpp
 **Author: Jeovani Vela
 **Date: 2/26/18
 **Description: This is the implementation file for the struct ListNode. The
 **nodes created from this struct will be used to traverse the LineupQueue and
 **the LoserStack in the fighting tournament. It also contains member functions
 **that can be called upon to set and get information from the Queue or Stack.
 **Including two getter functions that call upon Character member functions.
***************/

#ifndef LISTNODE_H
#define LISTNODE_H

#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "blueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include <string>

using std::string;

struct ListNode
{
	Character *character;	//node will hold data type, Character
	ListNode *next;
	ListNode *prev;

	ListNode();
	ListNode(Character *c);
	void setNext(ListNode *nextCharacter);	//setter function
	void setPrev(ListNode *prevCharacter);	//setter function
	Character* getCharacter();   //returns pointer type Character
	ListNode* getNext();		//returns pointer type ListNode
	ListNode* getPrev();
	string getName();
	string getId();		//returns nickname given by user
};
#endif

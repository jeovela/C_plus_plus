/****************
 **Program Name: ListNode.cpp
 **Author: Jeovani Vela
 **Date: 2/26/18
 **Description: This is the specification file for the struct ListNode.
***************/

#include "ListNode.hpp"
#include "Character.hpp"

#include <iostream>

/***************
 **Description: This is the default constructor for the struct. Initalizes
 **the pointers in the node to nullptr;
***************/
ListNode::ListNode()
{
	character = nullptr;
	next = nullptr;
	prev = nullptr;
}

/**************
 **Description: This is the constructor for the struct, ListNode. It sets the 
 **next and prev pointers to nullptr and the Character pointer passed is set
 **to member variable, character.
***************/
ListNode::ListNode(Character *c)
{
	character = c;
	next = nullptr;
	prev = nullptr;
}

/*****************
 **Description: The follwoing two functions are setter functions. They will 
 **set the prev and next pointers in the ListNode to the specified ListNode
 **pointer passed.
*****************/
void ListNode::setNext(ListNode *nextCharacter)
{
	next = nextCharacter;
}

void ListNode::setPrev(ListNode *prevCharacter)
{
	prev = prevCharacter;
}

/******************
 **Description: This getter function returns the ListNode's data member, a 
 **pointer to a Character.
*****************/
Character* ListNode::getCharacter()
{
	return character;
}

/****************
 **Description: This getter function returns the pointer to its next node.
***************/
ListNode* ListNode::getNext()
{
	return next;
}

/***************
 **Description: This getter function returns the pointer to its prev node.
***************/
ListNode* ListNode::getPrev()
{
	return prev;
}

/****************
 **Description: This function returns the name of the Character. The pointer
 **type Character accesses its member f unction from the Character class via
 **the -> since it is a pointer.
***************/
string ListNode::getName()
{
	return character->getName();
}

/****************
 **Description: This function returns the nickname of the Character given 
 **by the user. The pointer type Character accesses its member function 
 **from the Character class via the -> since it is a pointer.
***************/
string ListNode::getId()
{
	return character->getId();
}

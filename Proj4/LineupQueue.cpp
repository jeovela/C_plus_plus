/****************
 **Program Name: LineupQueue.cpp
 **Author: Jeovani Vela
 **Date: 2/28/18
 **Description: This is the implementation file for the class LineupQueue.
****************/

#include "LineupQueue.hpp"
#include "ListNode.hpp"
#include "Character.hpp"

/*******************
 **Description: This is the constructor for the class LineupQueue. Sets all
 **member variables to nullptr and the size of the queue to zero. Queue size 
 **will be vital as it will help determine and set the head in the circular 
 **doubly linked list.
*****************/
LineupQueue::LineupQueue()
{
	queueSize = 0;
	front = nullptr;
	back = nullptr;
}

/***************
 **Description: This is the destructor for the class LineupQueue. It will
 **deallocate memory for each node in the Queue. It will remove from front.
**************/
LineupQueue::~LineupQueue()
{
	if(queueSize > 0)
	{
		ListNode *clrNode;
		clrNode = front;
		back->setNext(nullptr);

		while(clrNode->getNext() != nullptr)
		{
			clrNode = clrNode->getNext();
			delete clrNode->getPrev();
		}
		delete clrNode;
	}
}

/*****************
 **Description: This function will take a pointer to a Character object and 
 **add it the Queue. It will allocate for a new node and will change the
 **next and prev pointers accordingly.
******************/
void LineupQueue::addCharacter(Character *fighter)
{
	ListNode *node;		//create a node
	node = new ListNode(fighter);	//assigned the pointer to a Char obj.

	//if the Queue is empty, the node is set to point back to itself
	if(queueSize == 0)
	{
		//front and back pointers are set to the new node created
		front = node;
		back = node;
		//the front is set with the next and prev parts of the node
		//to form circular format for one node
		front->setNext(front);
		front->setPrev(front);
	}

	else	//new node created is set to the back of the list/Queue
	{
		//node sets its parts to point to the previous node
		node->setPrev(back);
		node->setNext(front);
		//doubly link nodes
		front->setPrev(node);
		back->setNext(node);
		back = node;	//back is set
	}
	
	queueSize++;	//counter used so destructor can recognize the size
}

/*********************
 **Description: This function is a getter function and returns the queueSize.
*******************/
int LineupQueue::getQueueSize()
{
        return queueSize;
}

/******************
 **Description: This function is a getter function and returns a pointer
 **pointer to a Character type. Gets the Character at the front of the list.
******************/
Character* LineupQueue::getCharacter()
{
	return front->getCharacter();
}

/********************
 **Description: This function will remove the top node of the Queue. It returns
 **a pointer to a Character that is at the top of the Queue and removes 
 **it from the Queue. It will first adjust the Queue so that the front
 **of the Queue is the second node in the Queue. It will then remove the 
 **first node and return a pointer to the Character in the removed node.
***********************/
Character* LineupQueue::dequeue()
{
	if(queueSize > 0)
	{
		ListNode *dequeueNode;	//declare a pointer
		dequeueNode = front;	//set the pointer to the front
		Character *node;	
		node = front->getCharacter();
		front = front->getNext();
		back->setNext(front);
		front->setPrev(back);
	
		delete dequeueNode;
		dequeueNode = nullptr;
	
		queueSize--;

		return node;		//returning popped Character
	}
}

/*******************
 **Description: This function will shift the queue when a winner wins a round 
 **and is moved to the back of the Queue. Thus this function will shift the current
 **top of the Queue to the back of the Queue.
*******************/
void LineupQueue::shiftQueue()
{
	if(queueSize > 0)
	{
		back = front;
		front = front->getNext();
	}
}


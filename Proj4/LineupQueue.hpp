/********************
 **Program Name: LineupQueue.hpp
 **Author: Jeovani Vela
 **Date: 2/28/18
 **Description: This is the specification file for the class LineUpQueue.
 **This class represents a Queue-like ADT for the Character lineups in
 **the tournament. It is serving as a "container" in this program.
 **This LineupQueue will be a doubly-linked circular list
 **as winners in each round will go back into the list at the back while
 **losers will be moved to a LoserStack. It uses the ListNodes as the nodes
 **to traverese the list. Remember, Queues are "First in, First out". FIFO
*********************/

#ifndef LINEUPQUEUE_H
#define LINEUPQUEUE_H

#include "ListNode.hpp"
#include "Character.hpp"

class LineupQueue
{
	protected:
		int queueSize;
		ListNode *front;
		ListNode *back;
	public:
		LineupQueue();
		~LineupQueue();
		void addCharacter(Character *fighter);	//add Char to list
		int getQueueSize();
		Character* getCharacter();	//returns type pointer
		Character* dequeue();
		void shiftQueue();	//rearranges Queue when winner is moved	
};
#endif

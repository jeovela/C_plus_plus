/*******************
 **Program Name: conferenceRoom.hpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the specification file for the 
 **derived class ConferenceRoom.
********************/

#ifndef CONFERENCEROOM_H
#define CONFERENCEROOM_H

class ConferenceRoom : public Space
{
	public:
		ConferenceRoom();	//constructor
		virtual int promptMenu();
};	
#endif 

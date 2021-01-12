/*****************
 **Program Name: Lobby.hpp
 **Author: Jeovani Vela
 **Date: 3/13/18
 **Description: This is the specification file for the
 **derived class Lobby.
*******************/

#ifndef LOBBY_H
#define LOBBY_H

class Lobby : public Space
{
	public: 
		Lobby();	//constructor
		virtual int promptMenu();
};
#endif

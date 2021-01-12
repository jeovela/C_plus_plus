/******************
 **Program Name: Game.hpp
 **Author: Jeovani Vela
 **Date: 3/11/18
 **Description: This is the specification file for class Game.
 **This class will control the game, Die Hard OKC
******************/

#ifndef GAME_H
#define GAME_H

#include "Space.hpp"
#include "McClane.hpp"
#include "parkingGarage.hpp"
#include "smokingArea.hpp"
#include "Lobby.hpp"
#include "landRecords.hpp"
#include "Breakroom.hpp"
#include "conferenceRoom.hpp"
#include "ceoOffice.hpp"
#include "towerRestaurant.hpp"
#include "Helipad.hpp"

#include <iostream>
#include <queue>	//required for Queue STL
#include <string>

using std::queue;
using std::string;

class Game
{
	protected:
		Space *parkingGarage;
		Space *smokingArea;
		Space *lobby;
		Space *landRecords;
		Space *breakroom;
		Space *confRoom;
		Space *ceoOffice;
		Space *towerRestaurant;
		Space *helipad;

		Space *currentLocation;
		McClane *mcclane;

		queue<string> container;	//declare Queue ADT
		bool map;	//used to determine if John has map or not
		int hours;
		static bool code1;
		static bool code2;
		static bool code3;
		static bool anthrax;
		static bool sarin;
		static bool knife;
		static bool dies;
	public:
		Game();		//constructor
		~Game();	//destructor
		void createBuilding();	//set the game up -- links spaces
		void playGame();	//run the game
		
		//these next 3 functions depend on one another
		bool mapAcquired();	
		void displayMap();	
		void setMapBool(bool t);

		void addToContainer(string s);	//add to container

		//these 7 member functions change the static members to True
		void changeCode1(bool temp);
		void changeCode2(bool temp);
		void changeCode3(bool temp);
		void changeAnthrax(bool temp);
		void changeSarin(bool temp);
		void changeKnife(bool temp);
		void changeDies(bool temp);

		bool getKnife();
};
#endif

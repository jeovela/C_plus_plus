/******************
 **Program Name: Game.cpp
 **Author: Jeovani Vela
 **Date: 3/11/18
 **Description: This is the implementation file for class Game.
 **This class will control the game, Die Hard OKC
******************/

#include "Game.hpp"
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
#include <iomanip>	//required for fixed and setprecision
#include <cstdlib>	//required for random
#include <queue>	//required for Queue STL
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;	//required for queue


/***********************
 **Description: These static member variables must be 
 **initialized here and not in the constructor. There
 **values will change when the changeCode()
 **or the changeAnthrax() or changeSarin(), etc. function
 **is called and sets each code to true. Once all are
 **set to true before the game ends, the user/player
 **wins the game.
***************************/
bool Game::code1 = false;
bool Game::code2 = false;
bool Game::code3 = false;
bool Game::anthrax = false;
bool Game::sarin = false;
bool Game::knife = false;
bool Game::dies = false;

/*******************
 **Description: This is the constructor for the class Game.
 **Sets map to false and the hours to 10. 
 **Mosy importantly, it sets each Space * to a new object
 **from each derived class.
 **Additionally, John's currentLoction is set in the parkingGarage.
*********************/
Game::Game()
{
	hours = 15;	
	map = false;	//set map to false has John has not yet acquired map
	parkingGarage = new ParkingGarage();	//create parking garage space
	smokingArea = new SmokingArea();
	lobby = new Lobby();
	landRecords = new LandRecordsOffice();
	breakroom = new Breakroom();
	confRoom = new ConferenceRoom();
	ceoOffice = new CeoOffice();
	towerRestaurant = new TowerRestaurant();
	helipad = new Helipad();

	mcclane = new McClane();	

	currentLocation = parkingGarage;	//Player starts in garage

	container = {};		//make sure container is clear
}

/*******************
 **Description: This function creates the specified links between
 **the spaces of the game to create a connected building.
 **NOTE: I did not fill out every Space pointer for every space
 **if it was not necessary. For example the Land Records office links
************************/
void Game::createBuilding()
{
	//set the links for the parking garage
	parkingGarage->setRightSpace(NULL);
	parkingGarage->setLeftSpace(smokingArea);
	parkingGarage->setUpSpace(lobby);
	parkingGarage->setUp1Space(landRecords);
	parkingGarage->setUp2Space(breakroom);
	parkingGarage->setUp3Space(confRoom);
	parkingGarage->setUp4Space(ceoOffice);
	parkingGarage->setUp5Space(towerRestaurant);
	parkingGarage->setUp6Space(helipad);
	parkingGarage->setDownSpace(NULL);
	
	//set the links for the smoking area
	smokingArea->setRightSpace(parkingGarage);
	smokingArea->setLeftSpace(NULL);
	smokingArea->setUpSpace(lobby);
	smokingArea->setUp1Space(landRecords);
	smokingArea->setUp2Space(breakroom);
	smokingArea->setUp3Space(confRoom);
	smokingArea->setUp4Space(ceoOffice);
	smokingArea->setUp5Space(towerRestaurant);
	smokingArea->setUp6Space(helipad);
	smokingArea->setDownSpace(NULL);

	//set the links for the Lobby
	lobby->setRightSpace(NULL);
	lobby->setLeftSpace(NULL);
	lobby->setUpSpace(landRecords);	
	lobby->setUp1Space(breakroom);
	lobby->setUp2Space(confRoom);
	lobby->setUp3Space(ceoOffice);
	lobby->setUp4Space(towerRestaurant);
	lobby->setUp5Space(helipad);
	lobby->setDownSpace(parkingGarage);
	lobby->setDown1Space(smokingArea);

	//set links for Land Records Office
	landRecords->setRightSpace(breakroom);
	landRecords->setLeftSpace(NULL);
	landRecords->setUpSpace(confRoom);
	landRecords->setUp1Space(ceoOffice);
	landRecords->setUp2Space(towerRestaurant);
	landRecords->setUp3Space(helipad);
	landRecords->setDownSpace(lobby);
	landRecords->setDown1Space(smokingArea);
	landRecords->setDown2Space(parkingGarage);
	//not including down5 - down7
	
	//set links for the Breakroom
	breakroom->setRightSpace(NULL);
	breakroom->setLeftSpace(landRecords);
	breakroom->setUpSpace(ceoOffice);
	breakroom->setUp1Space(confRoom);
	breakroom->setUp2Space(towerRestaurant);
	breakroom->setUp3Space(helipad);
	breakroom->setDownSpace(lobby);
	breakroom->setDown1Space(parkingGarage);
	breakroom->setDown2Space(smokingArea);

	//set links for conference Room
	confRoom->setRightSpace(ceoOffice);	
	confRoom->setLeftSpace(NULL);
	confRoom->setUpSpace(towerRestaurant);
	confRoom->setUp1Space(helipad);
	confRoom->setDownSpace(landRecords);
	confRoom->setDown1Space(breakroom);
	confRoom->setDown2Space(lobby);
	confRoom->setDown3Space(parkingGarage);
	confRoom->setDown4Space(smokingArea);

	//set links for Ceo Office
	ceoOffice->setRightSpace(NULL);
	ceoOffice->setLeftSpace(confRoom);
	ceoOffice->setUpSpace(towerRestaurant);
	ceoOffice->setUp1Space(helipad);
	ceoOffice->setDownSpace(breakroom);
	ceoOffice->setDown1Space(landRecords);
	ceoOffice->setDown2Space(lobby);
	ceoOffice->setDown3Space(parkingGarage);
	ceoOffice->setDown4Space(smokingArea);

	//set links for tower Restaurant
	towerRestaurant->setRightSpace(NULL);
	towerRestaurant->setLeftSpace(NULL);
	towerRestaurant->setUpSpace(helipad);
	towerRestaurant->setDownSpace(ceoOffice);
	towerRestaurant->setDown1Space(confRoom);
	towerRestaurant->setDown2Space(breakroom);
	towerRestaurant->setDown3Space(landRecords);
	towerRestaurant->setDown4Space(lobby);
	towerRestaurant->setDown5Space(parkingGarage);
	towerRestaurant->setDown6Space(smokingArea);

	//set links for helipad
	helipad->setRightSpace(NULL);
	helipad->setLeftSpace(NULL);
	helipad->setDownSpace(towerRestaurant);
	helipad->setDown1Space(ceoOffice);
	helipad->setDown2Space(confRoom);
	helipad->setDown3Space(breakroom);
	helipad->setDown4Space(landRecords);
	helipad->setDown5Space(lobby);
	helipad->setDown6Space(parkingGarage);
	helipad->setDown7Space(smokingArea);
}

/******************
 **Description: This is the destructor for the class Game.
 **
 **NOTE:
 **DO NOT DELETE currentLocation pointer as it will cause ERRORS!
 *********************/
Game::~Game()
{
	delete parkingGarage;
	delete smokingArea;
	delete lobby;
	delete landRecords;
	delete breakroom;
	delete confRoom;
	delete ceoOffice;
	delete towerRestaurant;
	delete helipad;
	delete mcclane;
}

/******************
 **Description: This function manages the game via a for loop. Function
 **will iterate 15 times, once for each hour, and deduct an hour  after
 **each iteration in the game. So player must choose wisely where to search
 **and pay close attention to the clues found in the game. Or not. 
 **If John does not collect all 3 security codes in the alloted time, (ie hours)
 **the game ends as the building explodes. If he does, than the player has 
 **won the game.
 **Most importantly, the virtual void function promptMenu() will return a 
 **number that will match with the correct if statement in order to move
 **John from Space to Space. It sets the Space pointer currentLocation
 **to the new Space.
 **
 **Parking gagrage = 1 | Smoking Area = 2 | Lobby = 3 | 
 **Land Records = 4| Breakroom = 5| Conf Room = 6 | CEO Office = 7
 **Restaurant = 8 | Helipad = 9
 **
 **The game ends when code1, code2 and code3 are all changed to true.
 **Or when John gets killed with sarin gas in the breakroom or anthrax
 **while on the helipad or the terrorist in the conference room or when
 **time expires.
********************/
void Game::playGame()
{
	int num;

	for(int i=0; i<=15; i++)
	{
		if(code1 && code2 && code3)
                {
                        cout << endl;
                        cout << "John collected all 3 security codes in time!\n";
                        cout << "The bomb has been diffused and Devon Tower saved!\n";
                        cout << endl;
			cout << "John McClane -- yippee ki yay mother f*%#$@!\n";
			cout << endl;
			cout << "		____________\n";
			cout << "      		| ~You Won!~|      \n";
                        cout << "		------------\n";
			cout << endl;
                        break;
                }
		if(anthrax)
		{
			cout << endl;
			cout << "_____________\n";
			cout << "|~GAME OVER~|\n";
			cout << "-------------\n";
			cout << endl;
			break;
		}

		if(sarin)
                {
                        cout << endl;
                        cout << "_____________\n";
                        cout << "|~GAME OVER~|\n";
                        cout << "-------------\n";
                        cout << endl;
                        break;
                }

		if(dies)
		{
			cout << endl;
                        cout << "_____________\n";
                        cout << "|~GAME OVER~|\n";
                        cout << "-------------\n";
                        cout << endl;
                        break;
		}

                if(i == 15)
                {
                        cout << endl;
                        cout << "John ran out of time!\n";
                        cout << "Devon Tower exploded!\n";
                        cout << "   _____________\n";
                        cout << "   |~GAME OVER~|\n";
                        cout << "   -------------\n";
                        cout << endl;
                        break;
                }

		cout << "		_______________________\n";
		cout << "		|Time Remaining: " << hours << " hrs|\n";		
		cout << "		-----------------------\n";
		cout << endl;
		cout << "You are currently in the " << currentLocation->getName() << ".\n";

		hours--;
		num = currentLocation->promptMenu();
		
		if(num == 1)
		{
			currentLocation = parkingGarage;
		}
		else if(num == 2)
		{
			currentLocation = smokingArea;
		}

		else if(num == 3)
		{
			currentLocation = lobby;
		}

		else if(num == 4)
		{
			currentLocation = landRecords;
		}
		else if(num == 5)
		{
			currentLocation = breakroom;
		}

		else if(num == 6)
		{
			currentLocation = confRoom;
		}

		else if(num == 7)
		{
			currentLocation = ceoOffice;
		}

		else if(num == 8)
		{
			currentLocation = towerRestaurant;
		}

		else if(num == 9)
		{
			currentLocation = helipad;
		}
	}
}

/***************
 **Description: This function determines if John has acquired
 **the map in the parking garage or not. It returns a bool value.
 **It is set at false when the game begins and changes once 
 **John acquires map.
******************/
bool Game::mapAcquired()
{
	return map;	//returns either T/F
}

/***************
 **Description: Once John acquires the map, he has the option
 **to view this map as he wishes from the prompt menu
 **that is displayed in each Space.
*****************/
void Game::displayMap()
{
	cout << endl;
	cout << "Devon Tower Map:\n";
	cout << endl;
	cout << endl;
	cout << "						  |>   \n";
	cout << "      		[	    HELIPAD           ]   |      -Floor: 52\n";
	cout << "	^-----------------------------------------|---^\n";
	cout << "	| | | | | | | | Tower Restaurant| | | | | | | |  -Floor: 51\n";
	cout << "	|Conference Room|     | |     |  CEO Office | |  -Floor: 50\n";
	cout << "	| | | | | | | | |     |E|     | | | | | | | | |\n";
	cout << "	| | | | | | | | |     |L|     | | | | | | | | |\n";
	cout << "	| | | | | | | | |     |E|     | | | | | | | | |\n";
	cout << "	|  Land Records |     |V|     |  Breakroom  | |  -Floor: 30\n";
	cout << "	| | | | | | | | |     |A|     | | | | | | | | |\n";
	cout << "	| | | | | | | | |     |T|     | | | | | | | | |\n";
	cout << "	| | | | | | | | |     |O|     | | | | | | | | |  -Floor: 15\n";
	cout << "	| | | | | | | | |     |R|     | | | | | | | | |\n";
	cout << "	| | | | | | | | |     | |     | | | | | | | | |\n";
	cout << "	| | | | | | | | |  ~ LOBBY ~  | | | | | | | | |  -Ground Level\n";
	cout << "	|---------------------| |---------------------|\n";
	cout << "	|---------------------| |---------------------|\n";
	cout <<	"	|     Smoking Area    | |  Parking Garage*    |\n";
	cout << "	|---------------------------------------------|\n";
	cout << endl;
}

/**************
 **Description: This function set the member variable, map
 **to True. T is a bool variable carrying a True designation.
 **Assign the True to the Game member variable map.
 **It will cout a statement if map is changed to True correctly
**************/
void Game::setMapBool(bool t)
{
	//map member variable set to True
	map = t;
	if(map == true)
	{
		cout << "John replies, thanks and moves on.\n";
	}
}

/*********************
 **Description: This function when called adds an item to
 **the Queue (i.e. container). Using the queue STL to
 **push an item onto the Queue. It will also add one to 
 **the data member codes. 
*************************/
void Game::addToContainer(string s)
{
	//push onto Queue
	container.push(s);

	if(container.size() > 0)
	{
		cout << endl;
		cout << s << " added to John's pocket!\n";
		cout << endl;
	}
	cout << container.size() << endl;
}

/*******************************
 **Description: When this function is called, it 
 **changes a static member varible from false to
 **true.
*******************************/
void Game::changeCode1(bool temp)
{
	if(temp == true)
	{
		Game::code1 = true;
	}
}

void Game::changeCode2(bool temp)
{
        if(temp == true)
        {
                Game::code2 = true;
        }
}

void Game::changeCode3(bool temp)
{
        if(temp == true)
        {
                Game::code3 = true;
        }
}


/*******************************
 **Description: When this function is called, it 
 **changes a static member varible from false to
 **true.
 *******************************/
void Game::changeAnthrax(bool temp)
{
	if(temp == true)
	{
		Game::anthrax = true;
	}
}

/*******************************
 **Description: When this function is called, it 
 **changes a static member varible from false to
 **true.
 *******************************/
void Game::changeSarin(bool temp)
{
        if(temp == true)
        {
                Game::sarin = true;
        }
}

/*******************************
 **Description: When this function is called, it 
 **changes a static member varible from false to
 **true.
 *******************************/
void Game::changeKnife(bool temp)
{
	if(temp == true)
	{
		Game::knife = true;
	}
}

/********************
 **Description: A getter function that returns the
 **status of the static member variable, knife.
**********************/
bool Game::getKnife()
{
	return knife;
}

/*******************************
 **Description: When this function is called, it 
 **changes a static member varible from false to
 **true.
 *******************************/
void Game::changeDies(bool temp)
{
        if(temp == true)
        {
                Game::dies = true;
        }
}


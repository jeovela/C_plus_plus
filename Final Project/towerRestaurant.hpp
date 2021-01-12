/********************
 **Program Name: towerRestaurant.hpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the specification file for the 
 **derived class TowerRestaurant.
*******************/

#ifndef TOWERRESTAURANT_H
#define TOWERRESTAURANT_H

class TowerRestaurant : public Space
{
	public:
		TowerRestaurant();
		virtual int promptMenu();
};
#endif

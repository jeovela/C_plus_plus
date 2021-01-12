/******************
 **Program Name: parkingGarage.hpp
 **Author: Jeovani Vela
 **Date: 3/11/18
 **Description: This is the specification file for the derived
 **class ParkingGarage.
************************/

#ifndef PARKINGGARAGE_H
#define PARKINGGARAGE_H

class ParkingGarage : public Space
{
	public:
		ParkingGarage();	//constructor
		virtual int promptMenu();
};

	

#endif

 

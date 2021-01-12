/**********************
 **Program Name: landRecords.hpp
 **Author: Jeovani Vela
 **Date: 3/14/18
 **Description: This is the specification file for the 
 **derived class LandRecordsOffice.
*********************/

#ifndef LANDRECORDS_H
#define LANDRECORDS_H

class LandRecordsOffice : public Space
{
	public:
		LandRecordsOffice();	//constructor
		virtual int promptMenu();
};
#endif

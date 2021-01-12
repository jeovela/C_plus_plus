/*******************
 **Program Name: ceoOffice.hpp
 **Author: Jeovani Vela
 **Date: 3/15/18
 **Description: This is the specification file for the 
 **derived class CeoOffice.
 ********************/

#ifndef CEOOFFICE_H
#define CEOOFFICE_H

class CeoOffice : public Space
{
	public:
		CeoOffice();
		virtual int promptMenu();
};
#endif


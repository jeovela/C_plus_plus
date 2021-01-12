/****************
 **Program Name: Penguin.hpp
 **Author: Jeovani Vela
 **Date: 1/25/18
 **Description: This is the specification file for the class Penguin. It is a dervied class from
 **the class Animal.
 ******************/

#ifndef PENGUIN_H
#define PENGUIN_H


class Penguin : public Animal
{
        public:
                Penguin();        //defualt constructor
                Penguin(int age);         //constructor
                Penguin(const Penguin&);    //copy constructor
                void operator=(const Penguin&);   //Overloaded assignment function
                ~Penguin();       //destructor
};
#endif


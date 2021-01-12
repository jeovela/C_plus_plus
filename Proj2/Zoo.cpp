/**********************
 **Program Name: Zoo.cpp
 **Author: Jeovani Vela
 **Date: 1/30/18
 **Description: This is the specification file for the class Zoo. It contains
 **all the functions necessary to play Zoo Tycoon.
**********************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Longhorn.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>	//required for rand()

using std::cout;
using std::cin;
using std::endl;
using std::setw;


/****************
 **Description:
****************/
Zoo::Zoo()
{
	bank = 100000;	//bank set at 100k
	boom = false;
	day = 1;	//acts as counter
}

/****************
 **Description: This function will serve to only print a start screen informing
 **the user of the game and some of the rules invloved. This function does not
 **return anything.
*****************/
void Zoo::printStartScreen()
{
	cout << "          -------Welcome to Zoo Tycoon-------\n";
	cout << endl;	//spacing

	cout << "In this game you will be running your own zoo!\n";
	cout << "You will start with 100K and must purchase 1 or 2 of each animal";
	cout << " the zoo will   carry -- Tigers, Turtles, Penguins and";
	cout << " Longhorns -- to start out with.\n";
	cout << "You must care for and feed these animals, including their babies!\n";
	cout << "The types of feed at your disposal vary. You can choose from:\n";
	//base food cost is $20 aka "Cheap"
	cout << "Cheap = $20, Generic = $40 or Premium = $60\n";
	cout << endl;	//spacing
	cout << "          Mange your zoo wisely and good luck!\n";
	cout << "          ____________________________________\n";
	cout << endl;	//spacing
	cout << endl;
}

/*******************
 **Description: This function displays a menu where the user will choose
 **the number of animals to buy and which ones. At the end of this function
 **there will be a function call to another function where the
 **type of animal will be created and the cost deducted from the 100k 
 **in the bank.	
*****************/
void Zoo::startMenu()
{	
	cout << "Let's begin!\n";
	cout << endl;	//spacing
	
	cout << "How many Tigers would you like to buy, 1 or 2? ($10000 each)\n";
  	cout << "Enter 1 or 2.\n";	
	cin >> numOfTigers;
	
	//input validation
	while(numOfTigers < 1 || numOfTigers > 2)
	{
		cin.clear();
		cin.ignore(500, '\n');
		cout << "You entered an invalid character. Enter 1 or 2.\n";
		cin >> numOfTigers;
	}

	cout << "How many Turtles would you like to buy, 1 or 2? ($1000 each)\n";
  	cout << "Enter 1 or 2.\n";	
	cin >> numOfTurtles;

	//input validation
	 while(numOfTurtles < 1 || numOfTurtles > 2)
        {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "You entered an invalid character. Enter 1 or 2.\n";
                cin >> numOfTurtles;
        }

	cout << "How many Penguins would you like to buy, 1 or 2? ($100 each)\n";
	cout << "Enter 1 or 2.\n";
	cin >> numOfPenguins;

	//input validation
	 while(numOfPenguins < 1 || numOfPenguins > 2)
        {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "You entered an invalid character. Enter 1 or 2.\n";
                cin >> numOfPenguins;
        }

	cout << "How many Longhorns would you like to buy, 1 or 2? ($5000 each)\n";
	cout << "Enter 1 or 2.\n";
	cin >> numOfLonghorns;

	//input validation
	while(numOfLonghorns < 1 || numOfLonghorns > 2)
        {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "You entered an invalid character. Enter 1 or 2.\n";
                cin >> numOfLonghorns;
        }

	cout << endl; //spacing

	//function call to create the number of animals
	createAnimal();
}

/*********************
 **Description: This function will create the animals. Each type and the 
 **number chosen by the user to start with in the startMenu() function. It
 **will also dedcut money from the bank for the purchase of the animals.
 **These aninmals will start at the age of 1.
**********************/
void Zoo::createAnimal()
{
	//animals assigned an array of four Animal pointer objects
	animals = new Animal *[4];

	//dynamicallly allocate an array for each animal type
	//assign values to each pointer obj using subscripts
	animals[0] = new Tiger[numOfTigers];
	animals[1] = new Turtle[numOfTurtles];
	animals[2] = new Penguin[numOfPenguins];
	animals[3] = new Longhorn[numOfLonghorns];

	for(int i=0; i<numOfTigers; i++)
	{
		animals[0][i] = Tiger(1);//setting the age of animals to 1
	}

	for(int i=0; i<numOfTurtles; i++)
	{
		animals[1][i] = Turtle(1);
	}

	for(int i=0; i<numOfPenguins; i++)
	{
		animals[2][i] = Penguin(1);
	}

	for(int i=0; i<numOfLonghorns; i++)
	{
		animals[3][i] = Longhorn(1);
	}

	//deduct the $ from the bank, which was set at 100k 
	bank = bank - (10000 * numOfTigers);
	bank = bank - (100 * numOfTurtles);
	bank = bank - (1000 * numOfPenguins);
	bank = bank - (5000 * numOfLonghorns);
}

/******************
 **Description: This function will simulate a day at the zoo.
******************/
void Zoo::runDay()
{
	//if day arrives when player is out of money,
	//game will end. Controlled with while loop.
	while(bank <= 0)
	{
		cout << endl;	//spacing
		cout << "_____________________\n";
		cout << "You are out of money!\n";
		cout << "The zoo is now bankrupt!\n";
		cout << "-------GAME OVER-------\n";
		break;
	}
	
	cout << endl;	//spacing

	//show day and balance everyday
	cout << "-------------------------------\n";
	cout << "|Day # " << day << endl;
	cout << "|Current Bank Balance $" << bank << endl;
	cout << "-------------------------------\n";
	cout << endl;	//spacing
	//series of function calls are located here to play the game
	//
	animalCount();	//count the number of animals after purchase
	printDailyBudget();	//print budget for day, includes expenses
	feedingTime();	//feed the animals - user will choose feed type
	randomEvent();	//random event after feeding
	daysPayoff();	//displays the days profit, including possible bonus	
	endOfDay();
}

/*****************
 **Description: This function will add one day of age to each animal in the 
 **zoo. It will utilize the member function increaseAge from the Animal class
*****************/
void Zoo::addAge()
{
	for(int i=0; i<numOfTigers; i++)
	{
		animals[0][i].increaseAge();	//dot operator used for access
	}
	for(int i=0; i<numOfTurtles; i++)
	{
		animals[1][i].increaseAge();
	}
	for(int i=0; i<numOfPenguins; i++)
        {
                animals[2][i].increaseAge();
        }
	for(int i=0; i<numOfLonghorns; i++)
        {
                animals[3][i].increaseAge();
        }
}

/*********************
 **Description: This function will count the number of animals currently
 **in the zoo and display it. Function is called after the purchase of 
 **animals, the death of an animal or birth of animal(s).
**********************/
void Zoo::animalCount()
{
	int babyTigers = 0, babyTurtles = 0, babyPenguins = 0, babyLonghorns =0;	
	for(int i=0; i<numOfTigers; i++)
	{
		if(animals[0][i].getAge() <3)
		{
			babyTigers++;
		}
	}

	for(int i=0; i<numOfTurtles; i++)
        {
                if(animals[1][i].getAge() <3)
                {
                        babyTurtles++;
                }
        }

	for(int i=0; i<numOfPenguins; i++)
        {
                if(animals[2][i].getAge() <3)
                {
                        babyPenguins++;
                }
        }

	for(int i=0; i<numOfLonghorns; i++)
        {
                if(animals[3][i].getAge() <3)
                {
                        babyLonghorns++;
                }
        }

	cout << endl;	//spacing
	cout << "_____________________________\n";
	cout << "|Number of animals in the zoo|\n";
	cout << "------------------------------\n";
	cout << "Baby Tigers: " << setw(7) << babyTigers << endl;
	cout << "Total Tigers: " << setw(6) << numOfTigers << endl;
	cout << endl;	//spacing
	cout << "Baby Turtles: " << setw(6) << babyTurtles << endl;
	cout << "Total Turtles: " << setw(5) << numOfTurtles << endl;
	cout << endl;	//spacing
	cout << "Baby Penguins: " << setw(5) << babyPenguins << endl;
	cout << "Total Penguins: " << setw(4) << numOfPenguins << endl;
	cout << endl; //spacing
	cout << "Baby Longhorns: " << setw(4) << babyLonghorns << endl;
	cout << "Total Longhorns: " << setw(3) << numOfLonghorns << endl;
	cout << endl;	//spacing
}

/****************
 **Description: This function will print out the daily budget. Including 
 **the feeding costs and potential payoff. Base food cost is $20 which is cheap
******************/
void Zoo::printDailyBudget()
{
	int totalFoodCosts = 0, earningPotential = 0;

	for(int i=0; i<numOfTigers; i++)
	{
		totalFoodCosts += 20 * 5;	//5 times base food cost
		earningPotential += 2000;
	}
	for(int i=0; i<numOfTurtles; i++)
        {
                totalFoodCosts += 20 / 2;	//half base cost
                earningPotential += 5;
        }
	for(int i=0; i<numOfPenguins; i++)
        {
                totalFoodCosts += 20 * 1;	//cost of food is base cost
                earningPotential += 100;
        }
	for(int i=0; i<numOfLonghorns; i++)
        {
                totalFoodCosts += 20 * 2;	//food cost double base cost
                earningPotential += 1000;
        }

	cout << "Approximate cost of food for the day based on animal count";
	cout << " and cheap feed. $" << totalFoodCosts << endl;
	cout << endl;	//spacing
	cout << "Approximate payoff for the day based on animal count";
 	cout << " and type. $" << earningPotential << endl;
	cout << endl; //spacing	
}

/***************
 **Description: This function is to feed the animals. It allows the user to 
 **choose what type of feed. Base food cost is $10 however. Once user makes
 **a correct selection, feed cost will be determined.
****************/
void Zoo::feedingTime()
{
	cout << endl;	//spacing
	cout << "____________________\n";
	cout << "|It's feeding time!|\n";
	cout << "--------------------\n";
	cout << endl;	//spacing
	cout << "Below are the choices of feed for your zoo animals.\n";
	cout << "All animals will receive the same type of feed selected.\n";
	cout << endl;	//spacing
	cout << "Please enter 1, 2, or 3.\n";
	cout << "1. Cheap Feed - $20\n";
	cout << "2. Generic Feed - $40\n";
	cout << "3. Premium Feed - $60\n";
	cout << endl; //spacing
	cin >> feedType;	//using member variable

	//input validation
	 while(feedType < 1 || feedType > 3)
        {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "You entered an invalid character. Enter 1, 2, or 3.\n";
                cin >> feedType;
        }

	//if user makes correct selection of 1,2, or 3
	if(feedType == 1)
	{
		feedCost = 20;	//using Zoo member variable to hold feedCost
	}
	else if(feedType == 2)
	{
		feedCost = 40;
	}
	else if(feedType == 3)
	{
		feedCost = 60;
	}

	//either make function to calculate food costs or do it here
	
	int foodTotal = 0;

	if(feedCost == 20)	//Cheap Feed aka Base Food type
	{
		for(int i=0; i<numOfTigers; i++)
		{
			animals[0][i];	
			foodTotal += (feedCost * 5);	//times 5 base cost
		}
		for(int i=0; i<numOfTurtles; i++)
                {
                        animals[1][i];
                        foodTotal += (feedCost / 2);	//divided by 2
                }
		 for(int i=0; i<numOfPenguins; i++)
                {
                        animals[2][i];
                        foodTotal += (feedCost * 1);	//same as base cost
                }
		 for(int i=0; i<numOfLonghorns; i++)
                {
                        animals[3][i];
                        foodTotal += (feedCost * 2);	//double cost
                }	
	}

	if(feedCost == 40)	//Generic Feed
        {
                for(int i=0; i<numOfTigers; i++)
                {
                        animals[0][i];
                        foodTotal += (feedCost * 5);    //times 5 base cost
                }
                for(int i=0; i<numOfTurtles; i++)
                {
                        animals[1][i];
                        foodTotal += (feedCost / 2);    //divided by 2
                }
                 for(int i=0; i<numOfPenguins; i++)
                {
                        animals[2][i];
                        foodTotal += (feedCost * 1);    //same as base cost
                }
                 for(int i=0; i<numOfLonghorns; i++)
                {
                        animals[3][i];
                        foodTotal += (feedCost * 2);    //double cost
                }
        }

	if(feedCost == 60)	//Premium Feed
        {
                for(int i=0; i<numOfTigers; i++)
                {
                        animals[0][i];
                        foodTotal += (feedCost * 5);    //times 5 base cost
                }
                for(int i=0; i<numOfTurtles; i++)
                {
                        animals[1][i];
                        foodTotal += (feedCost / 2);    //divided by 2
                }
                 for(int i=0; i<numOfPenguins; i++)
                {
                        animals[2][i];
                        foodTotal += (feedCost * 1);    //same as base cost
                }
                 for(int i=0; i<numOfLonghorns; i++)
                {
                        animals[3][i];
                        foodTotal += (feedCost * 2);    //double cost
                }
        }
	cout << endl;	//spacing
	cout << "_____________________________\n";
	cout << "|The food total is $" << foodTotal << endl;

	//subtract the food total from the bank 
	bank -= foodTotal;

	cout << "|Current Bank Balance $" << bank << endl;
	cout << "-----------------------------\n";
	cout << endl;	//spacing
}

/*******************
 **Description: This function performs a random act on the zoo.Either a sickness **occurs, there is a boom in attendance, or a baby animal is born.
 **Each one of these events will affect the zoo in a positive or negative way.
 **The random event must take place after feeding!
 *********************/
void Zoo::randomEvent()
{
	int rando;	//variable to hold random num

	//https://www.daniweb.com/programming/software-development/threads/1769/c-random-numbers
	//used the srand((unsigned)time(0) so program gives random num
	//after each iteration. W/ just rand(), program shows same random #
	//every iteration

	srand((unsigned)time(0));	//necessary

	if(feedType == 1)
	{
		rando = rand() %10;
	}
	if(feedType == 2)
	{
		rando = rand() %7;
	}
	if(feedType == 3)
	{
		rando = rand() %6;
	}

	//below are outcomes based on random number
	if(rando > 5)
	{
		cout << "A sickness has hit the zoo!\n";
		cout << "An anmial will die.\n";
		sickAnimal();	//function call
	}
	else if(rando == 2 || rando == 4)
	{
		cout << "There has been an attendance boom today!\n";
		boom = true;	//bool switched to true. 
	}

	else if(rando == 1 || rando == 3)
	{
		cout << "A baby animal has been born in the zoo today!\n";
		birth();	//function call
	}
	else if(rando == 0 || rando == 5)
	{
		cout << "Nothing will happen today.\n";
	}
}

/*******************
 **Description: This function will randomly pick an an animal and kill it
 **due to its sickness. The animal will die and the dynamic array will be 
 **resized.
*********************/
void Zoo::sickAnimal()
{
	int random;	//variable to hold random number chosen
	int num;	//variable to hold number of animals in the resize

	srand((unsigned)time(0));	//necessary so rand # appears everytime
	
	random = rand() % 4 + 1;	//random number choosen between 1-4

	if(random == 1)	//Tiger Dies
	{
		if(numOfTigers == 0)
                {
                        cout << "Sorry, there are no more tigers to get sick.\n"
;               }
		
		else
		{
			num = --numOfTigers;	//1 animal dies
			Animal *temp = new Tiger[num];	//resize array
			for(int i=0; i<num; i++)
			{
				temp[i] = animals[0][i];	//stored in subscript 0
			}
			delete [] animals[0];	//deallocate

			animals[0] = temp;	//value assigned from temp to aniamls
					//overload function used automatically
			cout << endl;	//spacing		
			cout << "A tiger died.\n";
	        	cout << "_____\n";
                	cout << "|RIP|\n";
                	cout << "-----\n";
		}
	}

	if(random == 2)	//Turtle Dies
	{
		if(numOfTurtles == 0)
                {
                        cout << "Sorry, there are no more turtles to get sick.\n"
;               }
		else
		{
        	        num = --numOfTurtles;   //1 animal dies
                	Animal *temp = new Turtle[num];  //resize array
                	for(int i=0; i<num; i++)
                	{
                        	temp[i] = animals[1][i];	//stored in subscript 1
                	}
                	delete [] animals[1];   //deallocate

                	animals[1] = temp;      //value assigned from temp to aniamls
                                        //overload function used automatically
         		cout << endl;	//spacing
			cout << " A turtle died.\n";
			cout << "_____\n";
                	cout << "|RIP|\n";
                	cout << "-----\n";
		}

	}

	if(random == 3)	//Penguin Dies
	{
		if(numOfPenguins == 0)
                {
                        cout << "Sorry, there are no more penguins to get sick.\n"
;               }

		else
		{
                	num = --numOfPenguins;   //1 animal dies
                	Animal *temp = new Penguin[num];  //resize array
                	for(int i=0; i<num; i++)
                	{
                        	temp[i] = animals[2][i];	//stored in subscipt 2
                	}
                	delete [] animals[2];   //deallocate

                	animals[2] = temp;      //value assigned from temp to aniamls
                                        //overload function used automatically
                	cout << endl;
          		cout << "A penguin died.\n";
			cout << "_____\n";
                	cout << "|RIP|\n";
                	cout << "-----\n";
		}
	}

	if(random == 4)	//Longhorn Dies
	 {
		if(numOfLonghorns == 0)
                {
                        cout << "Sorry, there are no more longhorns to get sick.\n"
;               }

		else
		{
                	num = --numOfLonghorns;   //1 animal dies
                	Animal *temp = new Longhorn[num];  //resize array
                	for(int i=0; i<num; i++)
                	{
                        	temp[i] = animals[3][i];	//stored in subscript 3
                	}
                	delete [] animals[3];   //deallocate

                	animals[3] = temp;      //value assigned from temp to aniamls
                                        //overload function used automatically
                	cout << endl;
			cout << " A longhorn died.\n";
			cout << "_____\n";
			cout << "|RIP|\n";
			cout << "-----\n";
		}
	}

	//function call - show the animal count
	animalCount();
}

/**********************
 **Description: This function will randomly pick an animal to give birth.
 **It will also check to see if the animal is old enough to give birth. 
 **An animal must be 3>= to give birth. Animal will give birth to the number
 **of animals set by the game. If chosen animal does not have an animal old
 **enough to give birth, it will choose again.
**********************/
void Zoo::birth()
{
	int temp;	//variable used to hold number of chosen animal
	bool status1 = false;	//setting as false
	bool status2 = false;
	bool status3 = false;
	bool status4 = false;

	int count = 0;		//counter

	srand((unsigned)time(0));	//necessary	

	temp = rand() % 4 + 1;		//random num chosen between 1-4

	if(temp == 1)	//Tiger gives birth to 1
	{
		count++;	//counter
		
		//check age to see if animal is old enough
		status1 = checkTigerAge();	//function call - returns T/F
	}
	if(status1)	//if true
	{
		cout << "A tiger will have 1 baby!\n";

		//resize array
		Animal * temp = new Tiger[++numOfTigers];
		for(int i=0; i<numOfTigers-1; i++)
		{
			temp[i] = animals[0][i];
		}
		//deallocate memory
		delete [] animals[0];
			
		//value in temp assigned to subscript 0 = Tiger
		animals[0] = temp;

		//age of zero is assigned
		animals[0][numOfTigers-1] = Tiger(0);	//assigning age to 0
	}		

	if(temp == 2)	//Turtle gives birth to 10
	{
		count++;	//counter
		
		status2 = checkTurtleAge();
	}
       	if(status2)
        {
                cout << "A turtle  will have 10 babies!\n";

		//add 10 turtles to number in zoo
		numOfTurtles +=10;

		Animal * temp = new Turtle[numOfTurtles];
                for(int i=0; i<numOfTurtles-10; i++)
                {
                    temp[i] = animals[1][i];
                }

                delete [] animals[1];

                animals[1] = temp;
            
                for(int i=0; i<10; i++)
                {
                    animals[1][numOfTurtles-10+i] = Turtle(0);
                }
        }
	
	if(temp == 3)	//Penguin gives birth to 5
	{
		count++;	//counter		

		status3 = checkPenguinAge();	//function call
	}
        if(status3)
        {
                cout << "A penguin will have 5 babies!\n";

		//add 5 penguins to number in zoo
		numOfPenguins += 5;

		Animal * temp = new Penguin[numOfPenguins];
                for(int i=0; i<numOfPenguins-5; i++)
                {
			temp[i] = animals[2][i];
                }

                delete [] animals[2];

                animals[2] = temp;
		for(int i=0; i<5; i++)
		{
			animals[2][numOfPenguins-5+i] = Penguin(0);
		}
        }

	if(temp == 4)	//Longhorn gives birth to 1
	{
		count++;	//counter

		status4 = checkLonghornAge();	//function call
	}
        if(status4)
        {
                cout << "A longhorn will have 1 baby!\n";
		Animal * temp = new Longhorn[++numOfLonghorns];
                for(int i=0; i<numOfLonghorns-1; i++)
                {
            		temp[i] = animals[3][i];
                }

                delete [] animals[3];

                animals[3] = temp;

               	animals[3][numOfLonghorns-1] = Longhorn(0);
        }

	//if there is no animal old enough to give birth
	else if(!status1 && !status2 && !status3 && !status4)
	{
		cout << endl;
		cout << "             ~FALSE ALARM!~\n";
		cout << "There is no animal old enough to give birth.\n";
	}
	
	//function call - show animal count
	animalCount();
}

/******************
 **Description: This function will check to see if a tiger is of age to have
 **a baby. It is called in the birth() and will return a T/F value.
*******************/
bool Zoo::checkTigerAge()
{
	for(int i=0; i<numOfTigers; i++)
	{
		if(animals[0][i].getAge() >= 3)
		{
			return true;
		}
	}
	return false;

}

/*********************
 **Description: This function will check if a turtle is of age to have a baby.
 **Function is called in the birth() and will return a T/F
**********************/
bool Zoo::checkTurtleAge()
{
        for(int i=0; i<numOfTurtles; i++)
        {
                if(animals[1][i].getAge() >= 3)
                {
                        return true;
                }
        }
        return false;

}

/*********************
 **Description: This function will check if a penguin is of age to have a baby.
 **Function is called in the birth() and will return a T/F
 ***********************/
bool Zoo::checkPenguinAge()
{
        for(int i=0; i<numOfPenguins; i++)
        {
                if(animals[2][i].getAge() >= 3)
                {
                        return true;
                }
        }
        return false;

}

/*********************
 **Description: This function will check if a longhorn is of age to have a baby.
 **Function is called in the birth() and will return a T/F
 ************************/
bool Zoo::checkLonghornAge()
{
        for(int i=0; i<numOfLonghorns; i++)
        {
                if(animals[3][i].getAge() >= 3)
                {
                        return true;
                }
        }
        return false;

}

/*****************
 **Description: This function will calculate the payoff for the day. It also
 **will determine the Tiger bonus which is determined from the boom in 
 **attendance.
******************/
void Zoo::daysPayoff()
{
	//variable payoff will hold amount then transfer to bank
	int payoff = 0;
	int bonus = 0;

	for(int i=0; i<numOfTigers; i++)
	{
		payoff += 2000;		//$2000 for each tiger
	}	
	
	
	//include the bonus if boom in attendance occurs
	//random num between 250 - 500 will be bonus per tiger
	if(boom)	
	{
		srand((unsigned)time(0));
		bonus = (rand() % 250) + 250;	//generate random # 250-500

		payoff += numOfTigers * bonus;
	}
		
	for(int i=0; i<numOfTurtles; i++)
	{
		payoff += 5;		//$5 for each turtle
	}

	for(int i=0; i<numOfPenguins; i++)
	{
		payoff += 100;		//$100 for each penguin
	}

	for(int i=0; i<numOfLonghorns; i++)
	{
		payoff += 1000;		//$100 for each longhorn
	}

	cout << endl;	//spacing
	cout << "_________________________\n";
	cout << "|Today's payoff: " << setw(2) << "$" << payoff << endl;
	cout << "--------------------------\n";
	if(boom)
	{
		cout << "This includes the bonus from a boom in attendance!\n";
		cout << "_______________________\n";
		cout << "|Bonus Per Tiger: " << setw(2) << "$" << bonus << endl;
		cout << "------------------------\n";

		//reset boom back to false to prevent it from showing everytime
		boom = !boom;
	}

	//add money to the bank
	bank += payoff;
	

	cout << "_______________________________\n";
	cout << "|Current Bank Balance $" << bank << endl;
	cout << "-------------------------------\n";
	cout << endl;	//spacing
}

/******************
 **Description: This function is the end of day. It will ask the user if they
 **would like to buy an animal first, before asking if they want to continue
 **playing.
******************/
void Zoo::endOfDay()
{
	char choice, choice1;

	cout << endl;	//spacing
	cout << "____________________________________\n";
	cout << "|The zoo had a successful day today!|\n";
	cout << "------------------------------------\n";
	cout << endl;	//spacing
		
	addAge();	//function call to add age to animals

	cout << "Would you like to buy another animal?\n";
	cout << "Enter 'Y' for Yes or 'N' for No.\n";
	cout << endl;	//spacing
	cin >> choice;

	//input validation
	while(!(toupper(choice) == 'Y' || toupper(choice) == 'N'))
	{
		cin.clear();
		cin.ignore(500, '\n');
		cout << "You entered an incorrect charcter.\n";
		cout << "Enter 'Y' for Yes or 'N' for No.\n";
		cout << endl;	//spacing
		cin >> choice;
	}

	if(toupper(choice) == 'Y')
	{
		//function call
		buyAnimal();
	}
	
	cout << endl;	//spacing
	cout << "Would you like to continue playing or quit?\n";
	cout << "Enter 'Y' to continue playing or 'N' to quit.\n";
	cout << endl;	//spacing
	cin >> choice1;
	
	//input validation
	while(!(toupper(choice1) == 'Y' || toupper(choice1) == 'N'))
        {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "You entered an incorrect charcter.\n";
                cout << "Enter 'Y' to continue playing or 'N' to quit.\n";
		cout << endl;
                cin >> choice1;
        }

	if(toupper(choice1) == 'Y')	//call runDay() function again
	{
		day++;	//add day to counter before it is run again
		runDay();
	}

	else if(toupper(choice1) == 'N')	//game ends
	{
		cout << endl;	//spacing
		cout << "____________________\n";
		cout << "|Thanks for playing!|" << endl;
		cout << "---------------------\n";
		cout << endl;	//spacing
	}
}

/********************
 **Description: This function will ask user if they want to buy an animal
 **and then deduct the cost from the bank and add the animal. Finally after
 **executing you return back to the original function call where user will
 **be prompted to continue playing or not.
********************/
void Zoo::buyAnimal()
{
	int select;

	cout << endl;	//spacing
	cout << "Which animal do you want to buy? Choose 1-4.\n";
	cout << endl;	//spacing
	cout << "____________________\n";
	cout << "|1. Tiger ($10000)  |\n";
	cout << "|2. Turtle ($100)   |\n";
	cout << "|3. Penguin ($1000) |\n";
	cout << "|4. Longhorn ($5000)|\n";
	cout << "---------------------\n";
	cout << endl;
	cin >> select;

	//input vlaidation
	while(select < 1 || select > 4)
	{
		cin.clear();
		cin.ignore(500, '\n');
		cout << "You entered an incorrect character. Enter 1, 2, 3, or 4.\n";
		cin >> select;
	}

	if(select == 1)		//if Tiger is chosen
	{
		Animal *temp = new Tiger[++numOfTigers]; //add 1 tiger to new 
		for(int i=0; i<numOfTigers-1; i++)
		{
			temp[i] = animals[0][i];	//read into pointer
		}

		delete [] animals[0];	//deallocate

		animals[0] = temp;	//assigning values

		animals[0][numOfTigers-1] = Tiger(3);	//assigning age 3

		bank -= 10000;	//deduct 10k from bank for purchase
	}

	if(select == 2)		//if Turtle
        {
                Animal *temp = new Turtle[++numOfTurtles];
                for(int i=0; i<numOfTurtles-1; i++)
                {
                        temp[i] = animals[1][i];
                }

                delete [] animals[1];

                animals[1] = temp;

                animals[1][numOfTurtles-1] = Turtle(3);

		bank -= 100;	//deduct $100 from bank for purchase
        }

	if(select == 3)		//if Penguin
        {
                Animal *temp = new Penguin[++numOfPenguins];
                for(int i=0; i<numOfPenguins-1; i++)
                {
                        temp[i] = animals[2][i];
                }

                delete [] animals[2];

                animals[2] = temp;

                animals[2][numOfPenguins-1] = Penguin(3);

		bank -= 1000;	//deduct 1K from bank for purchase
        }

	if(select == 4)		//if longhorn choosen
        {
                Animal *temp = new Longhorn[++numOfLonghorns];
                for(int i=0; i<numOfLonghorns-1; i++)
                {
                        temp[i] = animals[3][i];
                }

                delete [] animals[3];

                animals[3] = temp;

                animals[3][numOfLonghorns-1] = Longhorn(3);

		bank -= 5000;	//deduct 5K from bank for purchase
        }



}

/******************
 **Description: This is the destructor. It will delete any dynamically
 **allocated memory. Namely the double pointer animal.
******************/
Zoo::~Zoo()
{
	for(int i=0; i<4; i++)
	{
		delete [] animals[i];
	}

	delete [] animals;
	animals = NULL;
}












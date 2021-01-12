#Program Name: makefile
#Author: Jeovani Vela
#Date: 3/11/18
#Description: This is the makefile for my final project, Die Hard OKC

CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11

OKC:	Main.cpp Game.hpp Game.o Space.hpp Space.o McClane.hpp McClane.o parkingGarage.hpp parkingGarage.o smokingArea.hpp smokingArea.o Lobby.hpp Lobby.o landRecords.hpp landRecords.o Breakroom.hpp Breakroom.o conferenceRoom.hpp conferenceRoom.o ceoOffice.hpp ceoOffice.o towerRestaurant.hpp towerRestaurant.o Helipad.hpp Helipad.o
	g++ -g -std=c++11 Main.cpp Game.cpp Space.cpp parkingGarage.cpp smokingArea.cpp Lobby.cpp landRecords.cpp Breakroom.cpp conferenceRoom.cpp ceoOffice.cpp towerRestaurant.cpp Helipad.cpp McClane.cpp -o OKC

clean:
	rm *.o OKC

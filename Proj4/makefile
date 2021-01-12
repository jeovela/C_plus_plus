#Program Name: makefile
#Author: Jeovani Vela
#Date: 2/27/18
#Description: This is the makefile for Proj4


CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11

FAN: Main.cpp Menu.hpp Menu.o Game.hpp Game.o Character.hpp Character.o Barbarian.hpp Barbarian.o Vampire.hpp Vampire.o blueMen.hpp blueMen.o Medusa.hpp Medusa.o HarryPotter.hpp HarryPotter.o ListNode.hpp ListNode.o Tourney.hpp Tourney.o LineupQueue.hpp LineupQueue.o LoserStack.hpp LoserStack.o
	g++ -g -std=c++11 Main.cpp Menu.cpp Game.cpp Character.cpp Barbarian.cpp Vampire.cpp blueMen.cpp Medusa.cpp HarryPotter.cpp ListNode.cpp Tourney.cpp LineupQueue.cpp LoserStack.cpp -o FAN

clean:
	 rm *.o FAN

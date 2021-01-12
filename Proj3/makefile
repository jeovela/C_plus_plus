#Program Name: makefile
#Author: Jeovani Vela
#Date: 2/7/18
#Description: This is the makefile for Proj3


CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11

FAN: Main.cpp Menu.hpp Menu.o Game.hpp Game.o Character.hpp Character.o Barbarian.hpp Barbarian.o Vampire.hpp Vampire.o blueMen.hpp blueMen.o Medusa.hpp Medusa.o HarryPotter.hpp HarryPotter.o
	g++ -g -std=c++11 Main.cpp Menu.cpp Game.cpp Character.cpp Barbarian.cpp Vampire.cpp blueMen.cpp Medusa.cpp HarryPotter.cpp -o FAN

clean:
	 rm *.o FAN

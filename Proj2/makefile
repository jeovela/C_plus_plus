#Program Name: makefile
#Author: Jeovani Vela
#Date:  1/25/18
#Description: This is the makefile for Proj2


CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11

MAM: Main.o Animal.hpp Animal.o Tiger.hpp Tiger.o Turtle.hpp Turtle.o Penguin.hpp Penguin.o Longhorn.hpp Longhorn.o Zoo.hpp Zoo.o
	g++ -g -std=c++11 Main.cpp Animal.cpp Tiger.cpp Turtle.cpp Penguin.cpp Longhorn.cpp Zoo.cpp -o MAM

clean:
	rm *.o MAM

#ifndef ACTIVIST_H
#define ACTIVIST_H
/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: activist.h
Purpose: Definitions of the Activist Class
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "town.h"
using namespace std;

class Activist
{
private:
  float toxicity;
  int dignity;
  int row, column;
  char symbol;
  int normal, cool, gone;
  int direction;
  int townsize;
  string activistName;
public:
  //Default constructor of Activist
  //PreCondition: None
  //PostCondition: Defaults object position in Town 2D array to (-1,-1)
  // set name of object, defaults and set object's toxicity to 0.05,
  // dignity to 100, and symbol to 'A'
  Activist(const string name);
  //Places Activist object in center of given Town 2D array 
  //PreCondition: Town Class parameter and 2D array data exists
  //PostCondition: Sets activist object in center and places their
  //symbol, 'A', by default
  void placeMeInMiddle(Town& townname);
  //Randomly chooses a direction to move and go one space in that direction
  //PreCondition: 2D Town array exists and should not have another object
  //in given direction
  //PostCondition: Moves object symbol one space in random direction,
  //replaces the space with symbol and previous location with space.
  void randMove(Town& townname);
  //Outputs the current state of the object's symbol
  //PreCondition: None
  //PostCondition: Activist Object's Symbol is returned
  friend ostream& operator << (ostream& out, const Activist& rhs);
};

#endif
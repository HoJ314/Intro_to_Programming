#ifndef POLLUTER_H
#define POLLUTER_H

/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: polluter.h
Purpose: Definitions of the Polluter Class
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "town.h"
using namespace std;

class Polluter
{
private:
  string objectname;
  char polluterSymbol;
  int rowPos, columnPos;
  int direction;
  int townsize;
public:
  //Default constructor of Polluter
  //PreCondition: None
  //PostCondition: Defaults object position in Town 2D array to (-1,-1)
  // set name of object, and represent object with character 'P'
  Polluter(const string name);
  //Places Polluter object randomly in given Town 2D array where it does not
  //overlap with any other objects
  //PreCondition: Town Class parameter and 2D array data exists
  //PostCondition: Sets a random position for object represented by object
  //symbol 'P' in an empty space
  void placeMe(Town& townname);
  //Randomly chooses a direction to move and go one space in that direction
  //PreCondition: 2D Town array exists and should not have another object
  //in given direction
  //PostCondition: Moves object symbol one space in random direction,
  //replaces the space with symbol and previous location with space.
  void randMove(Town& townname);
};

#endif
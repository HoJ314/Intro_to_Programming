#ifndef ROOT_H
#define ROOT_H

/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: root.h
Purpose: Definitions of the Root Class
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "town.h"
using namespace std;

const float MIN_NEG = -0.10; // Effect intervals
const float MAX_NEG = -0.001;
const float MIN_PLUS = 0.05;
const float MAX_PLUS = 0.10;

class Root
{
private:
  string description;
  float effect;
  int townsize;
  int countRoot;
public:
  //Default constructor of Root
  //PreCondition: random number generator seeded
  //PostCondition: Object description is set depending on randomly generated
  //effect inbetween intervals
  Root();
  //Gets effect from private variable
  //Post: Returns the effect value
  float getEffect();

};

#endif
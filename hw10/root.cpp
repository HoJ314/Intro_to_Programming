/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: activist.cpp
Purpose: Implementations of the Activist Class
*/

#include "root.h"

Root::Root()
{
  int signResult;
  signResult = rand() % POS_NEG; //0 or 1
  if (signResult == 0) // Positive
  {
    effect = MIN_PLUS + static_cast <float> (rand()) /
      (static_cast <float> (RAND_MAX / (MAX_PLUS - MIN_PLUS)));
    description = "truffle";
  }
  else // Negative
  {
    effect = MIN_NEG + static_cast <float> (rand()) / 
      (static_cast <float> (RAND_MAX / (MAX_NEG - MIN_NEG)));
    description = "square";
  }
}

float Root::getEffect()
{
  return effect;
}
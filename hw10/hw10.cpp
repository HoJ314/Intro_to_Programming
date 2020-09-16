/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: hw9.cpp
Purpose: Use given driver to make a town and move objects
polluter and activist in town using three classes.
*/




#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "town.h"
#include "activist.h"
#include "polluter.h"
#include "root.h"
#include "functionHeader.h"
using namespace std;

int main()
{
  int townSize, numRoot, numCops, numDays, DignityLoss_bump, DignityLoss_cop;
  int exitCount = 0;
  int overdoseCount = 0;
  int winCount = 0;
  int dignityCount = 0;
  double exitPercent, overdosePercent, winPercent, dignityPercent;
  float toxicCount;
  ifstream fin("config.dat");
  fin >> townSize;
  fin >> numRoot;
  fin >> numCops;
  fin >> numDays;
  fin >> DignityLoss_bump;
  fin >> DignityLoss_cop;
  fin.close();

  // Seed the random number generator
  srand(time(NULL));


  for (int i = 1; i <= FIRST_OUTPUT; i++) // Outputs the first two 
  {
    outputsimulation(toxicCount, dignityCount, exitCount, overdoseCount,
      winCount, townSize, numRoot, numCops, DignityLoss_bump, DignityLoss_cop);
  }


  for (int j = 1; j <= numDays - FIRST_OUTPUT; j++) 
    // Has to be within numDays or Active else stop
  {
    simulation(toxicCount, dignityCount, exitCount, overdoseCount,
      winCount, townSize, numRoot, numCops, DignityLoss_bump, DignityLoss_cop);
  }

  exitPercent = (double)(exitCount) / (double)(numDays);
  overdosePercent = (double)(overdoseCount) / (double)(numDays);
  winPercent = (double)(winCount) / (double)(numDays);
  dignityPercent = (double)(dignityCount) / (double)(numDays);

  exitPercent *= HUNDRED_PERCENT;
  overdosePercent *= HUNDRED_PERCENT;
  winPercent *= HUNDRED_PERCENT;
  dignityPercent *= HUNDRED_PERCENT;

  cout << "Percentage of Exits: " << exitPercent <<
    "%" << endl;
  cout << "Percentage of overdosing on roots: " <<
    overdosePercent << "%" << endl;
  cout << "Percentage of catching polluter: " << 
    winPercent << "%" << endl;
  cout << "Percentage of death by Dignity: " << 
    dignityPercent << "%" << endl;
  cout << "Average Toxicity is " << toxicCount / numDays 
    << endl;

  return 0;
}


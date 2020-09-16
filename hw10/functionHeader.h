#ifndef HW10_H
#define HW10_H

/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: activist.h
Purpose: Definitions of the simulation function
*/

#include "town.h"
#include "root.h"
#include "polluter.h"
#include "activist.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int WIN_OUTCOME = 1;
const int OVERDOSE_OUTCOME = 2;
const int EXIT_OUTCOME = 3;
const int DIGNITY_OUTCOME = 4;
const float HUNDRED_PERCENT = 100.0;

//Post: Returns a simulation of symbols moving within a changing 2D array
// Variables used to count activist inactivity reason
//Simulates Lisa chasing Homer while dealing with Roots, Dignity, and Cops
void simulation(float& toxicCount, int& dignityCount, int& exiCount, 
  int& overdoseCount, int& winCount, const int gridSize, const int numRoot,
  const int numCops, const int DignityLoss_bump, const int DignityLoss_cop);

void outputsimulation(float& toxicCount, int& dignityCount, int& exiCountt,
  int& overdoseCount, int& winCount, const int gridSize, const int numRoot, 
  const int numCops, const int DignityLoss_bump, const int DignityLoss_cop);




#endif
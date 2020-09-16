/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: activist.h
Purpose: Definitions of the simulation function
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "functionHeader.h"

using namespace std;

void simulation(float& toxicCount, int& dignityCount, int& exiCount,
  int& overdoseCount, int& winCount, const int gridSize, const int numRoot,
  const int numCops, const int DignityLoss_bump, const int DignityLoss_cop)
{
  bool isActive = true;
  bool dignityResult;
  bool exitResult;
  bool winResult;
  bool overdoseResult;

  Town springfield(gridSize, numRoot, numCops);
  Activist lisa("Lisa", 'L', DignityLoss_bump, DignityLoss_cop, numRoot);
  lisa.placeMeInMiddle(springfield);
  Polluter homer("Homer", 'H');
  homer.placeMe(springfield);
  lisa.getEffects(numRoot); // Gets root effect inside member array

  for (int i = 1; isActive == true; i++) // Outputs the first one
  {
    homer.randMove(springfield);
    lisa.Move(springfield, homer);
    lisa.checkStatus();
    isActive = lisa.isActive();
  }
  dignityResult = lisa.getDignity();
  exitResult = lisa.getExit();
  overdoseResult = lisa.getOverdose();
  winResult = lisa.getWin();

  if (dignityResult == true)
  {
    dignityCount++;
  }
  if (exitResult == true)
  {
    exiCount++;
  }
  if (overdoseResult == true)
  {
    overdoseCount++;
  }
  if (winResult == true)
  {
    winCount++;
  }
  toxicCount += lisa.getToxicity();

  return;
}

void outputsimulation(float& toxicCount, int& dignityCount, int& exiCount, 
  int& overdoseCount, int& winCount, const int gridSize, const int numRoot,
  const int numCops, const int DignityLoss_bump, const int DignityLoss_cop)
{
  bool isActive = true;
  bool dignityResult;
  bool exitResult;
  bool winResult;
  bool overdoseResult;

  Town springfield(gridSize, numRoot, numCops);
  Activist lisa("Lisa", 'L', DignityLoss_bump, DignityLoss_cop, numRoot);
  lisa.placeMeInMiddle(springfield);
  Polluter homer("Homer", 'H');
  homer.placeMe(springfield);
  lisa.getEffects(numRoot); // Gets root effect inside member array

  for (int i = 1; isActive == true; i++) // Outputs the first two 
  {
    homer.randMove(springfield);
    lisa.Move(springfield, homer);
    lisa.checkStatus();
    isActive = lisa.isActive();
    cout << springfield << endl;
  }
  dignityResult = lisa.getDignity();
  exitResult = lisa.getExit();
  overdoseResult = lisa.getOverdose();
  winResult = lisa.getWin();

  if (dignityResult == true)
  {
    dignityCount++;
  }
  if (exitResult == true)
  {
    exiCount++;
  }
  if (overdoseResult == true)
  {
    overdoseCount++;
  }
  if (winResult == true)
  {
    winCount++;
  }
  toxicCount += lisa.getToxicity();

  return;


}
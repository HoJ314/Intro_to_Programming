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
#include "polluter.h"
using namespace std;

const float NORMAL_TOXICITY = 0.05;
const float COOL_TOXICITY = 0.08;
const float GONE_TOXICITY = 0.25;
const int SUPREME_INDIGNITY = 0;

class Activist
{
private:
  float toxicity;
  int dignity;
  int row, column;
  char symbol;
  int normal;
  int cool;
  int gone;
  int status;
  int direction;
  int townsize;
  string activistName;
  int bumpLoss;
  int copLoss;
  bool replaceCop;
  bool active;
  int numRoots;
  bool exitOutcome; // Becomes true depending on 
                    //outcome and added to stats
  bool overdoseOutcome;
  bool winOutcome;
  bool dignityOutcome;
  int steps;
  float roots[MAX_ROOTS];
  int rootcount;
public:
  //Default constructor of Activist
  //PreCondition: None
  //PostCondition: Defaults object position in Town 2D array to (-1,-1)
  // set name of object, defaults and set object's toxicity to 0.05,
  // dignity to 100, and symbol to 'A'
  Activist(const string name, const char symbol, const int bumpLoss,
    const int copLoss, const int roots);
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
  void Move(Town& townname, Polluter& pollutername);
  //Outputs the current state of the object's symbol
  //PreCondition: None
  //PostCondition: Activist Object's Symbol is returned
  friend ostream& operator << (ostream& out, const Activist& rhs);
  bool isActive();
  
  //Declares Root Array and store it in private member
  //PreCondition: None
  //PostCondition: Root Array is returned
  void getEffects(const int numRoot);
  //Checks if activist is active or not by Root, or Dignity
  //PreCondition: None
  //PostCondition: Returns whether activist is active or not
  void checkStatus();
  
  //Moves the Object Symbol by one cell in a direction
  //PreCondition: None
  //PostCondition: Checks location symbol is headed and returns value
  //according to the condition
  void moveUp(Town& townname, Polluter& pollutername);
  void moveDown(Town& townname, Polluter& pollutername);
  void moveRight(Town& townname, Polluter& pollutername);
  void moveLeft(Town& townname, Polluter& pollutername);
  //Checks if Activist goes through exit
  //Post: Returns true if went through exit
  bool getExit();
  //Checks if Activist goes through exit
  //Post: Returns true if went through exit
  bool getOverdose();
  //Checks if Activist captures polluter object
  //Post: Returns true if activist position overlaps polluter's
  bool getWin();
  //Checks if Activist dies from dignity loss
  //Post: Returns true if dignity is less than 100
  bool getDignity();
  //Gets the current toxicity of activist
  //Post: Returns toxicity value in private member
  float getToxicity();
  /*
  float operator+ (const Activist& rhs);
  */
};



#endif
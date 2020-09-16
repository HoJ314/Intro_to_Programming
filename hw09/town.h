#ifndef TOWN_H
#define TOWN_H

/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: town.h
Purpose: Definitions of the Town Class
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int FIRST_ROW_COLUMN = 0;
const char WALL = 'W'; // Wall character for array
const char EXIT = 'E'; // Exit character for array
const int MIDDLE = 2; // Dividing value by half
const char EMPTY = ' '; // Space character
const int MAX = 25; // Max Town Size
const char DEFAULT_ACTIVIST = 'A'; // A represents Activist by default
const float DEFAULT_TOXICITY = .05; // Activist starts with .05 toxicity
const int DEFAULT_DIGNITY = 100; // and 100 dignity
const int DEFAULT_POS = -1; // Object defaults to (-1,-1)
const char DEFAULT_POLLUTER_SYM = 'P';
const int NORTH = 0;
const int EAST = 1;  // Used in random number generator to determine direction
const int SOUTH = 2;
const int WEST = 3;
const int NUM_DIRECTIONS = 3; // Includes 0, totaling 4 for directions
const int MOVE_SPACE = 1; // How far an object moves

class Town
{
private:
  int townsize;
  //Clears the data in the 2D array by replacing them with spaces
  //PreCondition: None
  //PostCondition: 2D array appears empty
  void clearGrid();
  //The town size, walls, and exits are generated depending on townsize
  //PreCondition: townsize must be <= MAX
  //PostCondition: A 2D array with walls and exits in middle are generated
  void buildGrid();
public:
  char town[MAX][MAX];
  //Gets the size of the town
  //PreCondition: None
  //PostCondition: Returns townsize value
  short getSize();
  //Default constructor for Town
  //PreCondition: None
  //PostCondition: townsize is set to a value less than or equal to 25
  // and 
  Town(const int size);
  //Allows the ability to output the 2D array and show the town
  //PreCondition: 2D array's data is inputted
  //PostCondition: Returns 2D array of townsize
  friend ostream& operator << (ostream& out, const Town& rhs);

};

#endif
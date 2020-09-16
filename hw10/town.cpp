/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: town.cpp
Purpose: Implementations of the Town Class
*/
#include <stdio.h>
#include <cstring>
#include "town.h"

void Town::buildGrid()
{
  for (int i = 0; i < townsize; i++) // Builds wall until reached town size
  {
    town[i][FIRST_ROW_COLUMN] = WALL;
    town[i][townsize - 1] = WALL;
    town[FIRST_ROW_COLUMN][i] = WALL;
    town[townsize - 1][i] = WALL;
    town[FIRST_ROW_COLUMN][townsize / MIDDLE] = EXIT;
    town[townsize / MIDDLE][FIRST_ROW_COLUMN] = EXIT;
    town[townsize - 1][townsize / MIDDLE] = EXIT;
    town[townsize / MIDDLE][townsize - 1] = EXIT;
  }
}

void Town::clearGrid()
{
  memset(town, EMPTY, sizeof(town)); //Sets all data in array to spaces
}

Town::Town(const int size, const int roots, const int cops)
{
  clearGrid();
  if (size <= MAX)
    townsize = size;
  else
    townsize = MAX; //Defaults to 25 if parameter value over 25
  buildGrid();
  placeObject(roots, ROOT_SYMBOL);
  placeObject(cops, COP_SYMBOL);
}

short Town::getSize()
{
  return townsize;
}

ostream& operator << (ostream& out, const Town& rhs)
{
  for (int row = 0; row <= rhs.townsize; row++)
  {
    out << endl; // Moves to next row once filled out
    for (int column = 0; column <= rhs.townsize; column++)
    {
      out << rhs.town[row][column] << " ";; // Outputs array
    }
  }
  return(out);
}

void Town::placeObject(const int& numroot, const int& symbol)
{
  int rowPos, columnPos;
  for(int i = 0; i < numroot; i++)
  {
    do
    {
      rowPos = rand() % townsize;
      columnPos = rand() % townsize;
    } while (town[rowPos][columnPos] != EMPTY); // Repeats position
                                                         //until cell is empty

    town[rowPos][columnPos] = symbol; // Sets new position 
  }                                        //of root
}
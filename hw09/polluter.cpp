/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: polluter.cpp
Purpose: Implementations of the Polluter Class
*/

#include "polluter.h"

Polluter::Polluter(const string name)
{
  objectname = name;
  polluterSymbol = DEFAULT_POLLUTER_SYM;
  rowPos = DEFAULT_POS;
  columnPos = DEFAULT_POS;
}

void Polluter::placeMe(Town& townname)
{
  townsize = townname.getSize();
  do
  {
    rowPos = rand() % townsize;
    columnPos = rand() % townsize;
  } while (townname.town[rowPos][columnPos] != EMPTY); // Repeats position
                                                       //until cell is empty

  townname.town[rowPos][columnPos] = polluterSymbol; // Sets new position 
                                                     //of polluter
}

void Polluter::randMove(Town& townname)
{
  direction = rand() % NUM_DIRECTIONS;

  if (direction == NORTH)
  {
    if (townname.town[rowPos][columnPos + MOVE_SPACE] == EMPTY) // Checks for 
                                                                //Empty Space
    {
      townname.town[rowPos][columnPos] = EMPTY; // Erases previous location
      townname.town[rowPos][columnPos + MOVE_SPACE] = polluterSymbol; 
      // Moves activist a space
      columnPos += MOVE_SPACE; // Updates 
    }
  }

  if (direction == EAST)
  {
    if (townname.town[rowPos + MOVE_SPACE][columnPos] == EMPTY) 
    {
      townname.town[rowPos][columnPos] = EMPTY;
      townname.town[rowPos + MOVE_SPACE][columnPos] = polluterSymbol; 
      rowPos += MOVE_SPACE;
    }
  }

  if (direction == SOUTH)
  {
    if (townname.town[rowPos][columnPos - MOVE_SPACE] == EMPTY)
    {
      townname.town[rowPos][columnPos] = EMPTY; 
      townname.town[rowPos][columnPos - MOVE_SPACE] = polluterSymbol;
      columnPos -= MOVE_SPACE;
    }
  }

  if (direction == WEST)
  {
    if (townname.town[rowPos - MOVE_SPACE][columnPos] == EMPTY) 
    {
      townname.town[rowPos][columnPos] = EMPTY;
      townname.town[rowPos - MOVE_SPACE][columnPos] = polluterSymbol; 
      rowPos -= MOVE_SPACE;
    }
  }

}
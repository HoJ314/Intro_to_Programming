/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: activist.cpp
Purpose: Implementations of the Activist Class
*/

#include "activist.h"

Activist::Activist(const string name)
{
  activistName = name;
  symbol = DEFAULT_ACTIVIST;
  toxicity = DEFAULT_TOXICITY;
  dignity = DEFAULT_DIGNITY;
  row = DEFAULT_POS;
  column = DEFAULT_POS;
}

void Activist::placeMeInMiddle(Town& townname)
{
  townsize = townname.getSize();
  row = townsize / MIDDLE;
  column = townsize / MIDDLE;
  townname.town[row][column] = symbol;
}

void Activist::randMove(Town& townname)
{
  direction = rand() % NUM_DIRECTIONS;

  if (direction == NORTH)
  {
    if (townname.town[row][column + MOVE_SPACE] == EMPTY)
    {
      townname.town[row][column] = EMPTY; 
      townname.town[row][column + MOVE_SPACE] = symbol; 
      column += MOVE_SPACE;
    }
  }

  if (direction == EAST)
  {
    if (townname.town[row + MOVE_SPACE][column] == EMPTY) 
    {
      townname.town[row][column] = EMPTY;
      townname.town[row + MOVE_SPACE][column] = symbol;
      row += MOVE_SPACE;
    }
  }

  if (direction == SOUTH)
  {
    if (townname.town[row][column - MOVE_SPACE] == EMPTY) 
    {
      townname.town[row][column] = EMPTY; 
      townname.town[row][column - MOVE_SPACE] = symbol; 
      column -= MOVE_SPACE;
    }
  }

  if (direction == WEST)
  {
    if (townname.town[row - MOVE_SPACE][column] == EMPTY) 
    {
      townname.town[row][column] = EMPTY;
      townname.town[row - MOVE_SPACE][column] = symbol;
      row -= MOVE_SPACE;
    }
  }
}

ostream& operator << (ostream& out, const Activist& rhs)
{
  out << rhs.symbol << endl;
  return(out);
}
/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: polluter.cpp
Purpose: Implementations of the Polluter Class
*/

#include "polluter.h"

Polluter::Polluter(const string name, const char inputSymbol)
{
  objectname = name;
  polluterSymbol = inputSymbol;
  rowPos = DEFAULT_POS;
  columnPos = DEFAULT_POS;
  replaceRoot = false;
  caught = false;
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
    switch (townname.town[rowPos][columnPos + MOVE_SPACE])
    {
      case EMPTY:
      {
        if (replaceRoot == true)
        {
          townname.town[rowPos][columnPos] = ROOT_SYMBOL;
          replaceRoot = false;
        }
        else
        {
          townname.town[rowPos][columnPos] = EMPTY;
        }
        townname.town[rowPos][columnPos + MOVE_SPACE] = polluterSymbol;
        columnPos += MOVE_SPACE;
        break;
      }
      case ROOT_SYMBOL:
      {
        if (replaceRoot == true)
        {
          townname.town[rowPos][columnPos] = ROOT_SYMBOL;
          replaceRoot = false;
        }
        else
        {
          townname.town[rowPos][columnPos] = EMPTY;
        }
        replaceRoot = true;
        townname.town[rowPos][columnPos + MOVE_SPACE] = polluterSymbol;
        columnPos += MOVE_SPACE;
        break;
      }
      case COP_SYMBOL:
      {
        if (replaceRoot == true)
        {
          townname.town[rowPos][columnPos] = ROOT_SYMBOL;
          replaceRoot = false;
        }
        else
        {
          townname.town[rowPos][columnPos] = EMPTY;
        }
        townname.town[rowPos][columnPos + MOVE_SPACE] = polluterSymbol;
        columnPos += MOVE_SPACE;
        caught = true;
        break;
      }
      default:
      {
        break;
      }
    }
  }
    
  if (direction == SOUTH)
  {
    switch (townname.town[rowPos][columnPos - MOVE_SPACE])
    {
      case EMPTY:
      {
        if (replaceRoot == true)
        {
          townname.town[rowPos][columnPos] = ROOT_SYMBOL;
          replaceRoot = false;
        }
        else
        {
          townname.town[rowPos][columnPos] = EMPTY;
        }
        townname.town[rowPos][columnPos - MOVE_SPACE] = polluterSymbol;
        columnPos -= MOVE_SPACE;
        break;
      }
      case ROOT_SYMBOL:
      {
        if (replaceRoot == true)
        {
          townname.town[rowPos][columnPos] = ROOT_SYMBOL;
          replaceRoot = false;
        }
        else
        {
          townname.town[rowPos][columnPos] = EMPTY;
        }
        replaceRoot = true;
        townname.town[rowPos][columnPos - MOVE_SPACE] = polluterSymbol;
        columnPos -= MOVE_SPACE;
        break;
      }
      case COP_SYMBOL:
      {
        if (replaceRoot == true)
        {
          townname.town[rowPos][columnPos] = ROOT_SYMBOL;
          replaceRoot = false;
        }
        else
        {
          townname.town[rowPos][columnPos] = EMPTY;
        }
        townname.town[rowPos][columnPos + MOVE_SPACE] = polluterSymbol;
        columnPos -= MOVE_SPACE;
        caught = true;
        break;
      }
      default:
      {
        break;
      }
    }
  }

  if (direction == WEST)
  {
    switch (townname.town[rowPos - MOVE_SPACE][columnPos])
    {
    case EMPTY:
    {
      if (replaceRoot == true)
      {
        townname.town[rowPos][columnPos] = ROOT_SYMBOL;
        replaceRoot = false;
      }
      else
      {
        townname.town[rowPos][columnPos] = EMPTY;
      }
      townname.town[rowPos - MOVE_SPACE][columnPos] = polluterSymbol;
      rowPos -= MOVE_SPACE;
      break;
    }
    case ROOT_SYMBOL:
    {
      if (replaceRoot == true)
      {
        townname.town[rowPos][columnPos] = ROOT_SYMBOL;
        replaceRoot = false;
      }
      else
      {
        townname.town[rowPos][columnPos] = EMPTY;
      }
      replaceRoot = true;
      townname.town[rowPos - MOVE_SPACE][columnPos] = polluterSymbol;
      rowPos -= MOVE_SPACE;
      break;
    }
    case COP_SYMBOL:
    {
      if (replaceRoot == true)
      {
        townname.town[rowPos][columnPos] = ROOT_SYMBOL;
        replaceRoot = false;
      }
      else
      {
        townname.town[rowPos][columnPos] = EMPTY;
      }
      townname.town[rowPos - MOVE_SPACE][columnPos] = polluterSymbol;
      rowPos -= MOVE_SPACE;
      caught = true;
      break;
    }
    default:
    {
      break;
    }
    }
  }

  if (direction == EAST)
  {
    switch (townname.town[rowPos + MOVE_SPACE][columnPos])
    {
    case EMPTY:
    {
      if (replaceRoot == true)
      {
        townname.town[rowPos][columnPos] = ROOT_SYMBOL;
        replaceRoot = false;
      }
      else
      {
        townname.town[rowPos][columnPos] = EMPTY;
      }
      townname.town[rowPos + MOVE_SPACE][columnPos] = polluterSymbol;
      rowPos += MOVE_SPACE;
      break;
    }
    case ROOT_SYMBOL:
    {
      if (replaceRoot == true)
      {
        townname.town[rowPos][columnPos] = ROOT_SYMBOL;
        replaceRoot = false;
      }
      else
      {
        townname.town[rowPos][columnPos] = EMPTY;
      }
      replaceRoot = true;
      townname.town[rowPos + MOVE_SPACE][columnPos] = polluterSymbol;
      rowPos += MOVE_SPACE;
      break;
    }
    case COP_SYMBOL:
    {
      if (replaceRoot == true)
      {
        townname.town[rowPos][columnPos] = ROOT_SYMBOL;
        replaceRoot = false;
      }
      else
      {
        townname.town[rowPos][columnPos] = EMPTY;
      }
      townname.town[rowPos + MOVE_SPACE][columnPos] = polluterSymbol;
      rowPos += MOVE_SPACE;
      caught = true;
      break;
    }
    default:
    {
      break;
    }
    }
  }

  



}

short Polluter::getRow()
{
  return rowPos;
}

short Polluter::getColumn()
{
  return columnPos;
}

char Polluter::getSymbol()
{
  return polluterSymbol;
}
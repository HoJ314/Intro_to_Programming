/*
Programmer: Jeremy Ho     Date: 11/17/2016
Section : 1J              Instructor : Nathan Jarus
File: activist.cpp
Purpose: Implementations of the Activist Class
*/

#include "activist.h"
#include "root.h"

Activist::Activist(const string name, const char inputSymbol,
  const int DignityBump, const int DignityCop, const int rootnum)
{
  activistName = name;
  symbol = inputSymbol;
  toxicity = DEFAULT_TOXICITY;
  dignity = DEFAULT_DIGNITY;
  row = DEFAULT_POS;
  column = DEFAULT_POS;
  bumpLoss = DignityBump;
  copLoss = DignityCop;
  numRoots = rootnum;
  active = true;
  exitOutcome = false;
  overdoseOutcome = false;
  winOutcome = false;
  dignityOutcome = false;
  normal = 1;
  cool = 2;
  gone = 3;
  replaceCop = false;
  rootcount = 1;
}

void Activist::placeMeInMiddle(Town& townname)
{
  townsize = townname.getSize();
  row = townsize / MIDDLE;
  column = townsize / MIDDLE;
  townname.town[row][column] = symbol;
}

void Activist::Move(Town& townname, Polluter& pollutername)
{
  short polluterRow = pollutername.getRow();
  short polluterColumn = pollutername.getColumn();
  char polluterSymbol = pollutername.getSymbol();
  int direction = rand() % NUM_DIRECTIONS;
  if(townname.town[row][column] != polluterSymbol)
  {
    steps++; // Counts number of steps

    if (status == normal) // Chases polluter if activist state is normal
    {
      if (column < polluterColumn)
      {
        moveUp(townname, pollutername);
      }
      else
      {
        if (column > polluterColumn)
        {
          moveDown(townname, pollutername);
        }
        else
        {
          if (row < polluterRow)
          {
            moveRight(townname, pollutername);
          }
          else
          {
            if (row > polluterRow)
            {
              moveLeft(townname, pollutername);
            }
          }
        }
      }
    }
    else // Random direction if activist is in cool state
    {
      if (direction == NORTH)
      {
        moveUp(townname, pollutername);
      }

      if (direction == EAST)
      {
        moveRight(townname, pollutername);
      }

      if (direction == SOUTH)
      {
        moveDown(townname, pollutername);
      }

      if (direction == WEST)
      {
        moveLeft(townname, pollutername);
      }
    }
  }
  else
  {
    active = false;
    winOutcome = true;
  }
}


bool Activist::isActive()
{
  return active;
}

void Activist::getEffects(const int numRoot)
{
  for (int countRoot = 1; countRoot <= numRoot; countRoot++)
  {
    Root();
    roots[countRoot] = Root().getEffect();
  }
}

void Activist::checkStatus()
{
  if (toxicity < COOL_TOXICITY)
  {
    status = normal;
  }
  else
  {
    if(toxicity < GONE_TOXICITY)
    {
      status = cool;
    }
    else
    {
      status = gone;
      overdoseOutcome = true;
      active = false;
    }
  }

  if (dignity <= SUPREME_INDIGNITY)
  {
    dignityOutcome = true;
    active = false;
  }
}

void Activist::moveUp(Town& townname, Polluter& pollutername)
{
  char polluterSymbol = pollutername.getSymbol();
  switch (townname.town[row][column + MOVE_SPACE])
  {
    case COP_SYMBOL:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      dignity -= copLoss;
      replaceCop = true;
      townname.town[row][column] = EMPTY;
      townname.town[row][column + MOVE_SPACE] = symbol;
      column += MOVE_SPACE;
      break;
    }
    case ROOT_SYMBOL:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      toxicity += roots[numRoots - rootcount];
      rootcount++;
      townname.town[row][column + MOVE_SPACE] = symbol;
      column += MOVE_SPACE;
      break;
    }
    case WALL:
    {
      dignity -= bumpLoss;
      break;
    }
    case EMPTY:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      townname.town[row][column + MOVE_SPACE] = symbol;
      column += MOVE_SPACE;
      break;
    }
    case EXIT:
    {
      exitOutcome = true;
      active = false;
      break;
    }
    default: // Assumes Polluter is caught options invalid
    {
      if (townname.town[row][column + MOVE_SPACE] == polluterSymbol)
      {
        if (replaceCop == true)
        {
          townname.town[row][column] = COP_SYMBOL;
          replaceCop = false; // Resets until Cop Symbol is hit again
        }
        else
        {
          townname.town[row][column] = EMPTY;
        }
        column += MOVE_SPACE;
        townname.town[row][column + MOVE_SPACE] = symbol;
        winOutcome = true;
        active = false;
      }
      break;
    }
  }
}

void Activist::moveDown(Town& townname, Polluter& pollutername)
{
  char polluterSymbol = pollutername.getSymbol();
  switch (townname.town[row][column - MOVE_SPACE])
  {
    case COP_SYMBOL:
    {
      dignity -= copLoss;
      replaceCop = true;
      townname.town[row][column] = EMPTY;
      townname.town[row][column - MOVE_SPACE] = symbol;
      column += MOVE_SPACE;
      break;
    }
    case ROOT_SYMBOL:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      toxicity += roots[numRoots - rootcount];
      rootcount++;
      townname.town[row][column - MOVE_SPACE] = symbol;
      column += MOVE_SPACE;
      break;
    }
    case WALL:
    {
      dignity -= bumpLoss;
      break;
    }
    case EMPTY:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      townname.town[row][column - MOVE_SPACE] = symbol;
      column -= MOVE_SPACE;
      break;
    }
    case EXIT:
    {
      exitOutcome = true;
      active = false;
      break;
    }
    default: // Assumes Polluter is caught options invalid
    {
      if (townname.town[row][column - MOVE_SPACE] == polluterSymbol)
      {
        if (replaceCop == true)
        {
          townname.town[row][column] = COP_SYMBOL;
          replaceCop = false; // Resets until Cop Symbol is hit again
        }
        else
        {
          townname.town[row][column] = EMPTY;
        }
        townname.town[row][column - MOVE_SPACE] = symbol;
        winOutcome = true;
        active = false;
      }
      break;
    }
  }
}

void Activist::moveRight(Town& townname, Polluter& pollutername)
{
  char polluterSymbol = pollutername.getSymbol();
  switch (townname.town[row + MOVE_SPACE][column])
  {
    case COP_SYMBOL:
    {
      dignity -= copLoss;
      replaceCop = true;
      townname.town[row][column] = EMPTY;
      townname.town[row + MOVE_SPACE][column] = symbol;
      row += MOVE_SPACE;
      break;
    }
    case ROOT_SYMBOL:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      toxicity += roots[numRoots - rootcount];
      rootcount++;
      townname.town[row + MOVE_SPACE][column] = symbol;
      row += MOVE_SPACE;
      break;
    }
    case WALL:
    {
      dignity -= bumpLoss;
      break;
    }
    case EMPTY:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      townname.town[row + MOVE_SPACE][column] = symbol;
      row += MOVE_SPACE;
      break;
    }
    case EXIT:
    {
      exitOutcome = true;
      active = false;
      break;
    }
    default: // Assumes Polluter is caught options invalid
    {
      if (townname.town[row + MOVE_SPACE][column] == polluterSymbol)
      {
        if (replaceCop == true)
        {
          townname.town[row][column] = COP_SYMBOL;
          replaceCop = false; // Resets until Cop Symbol is hit again
        }
        else
        {
          townname.town[row][column] = EMPTY;
        }
        townname.town[row + MOVE_SPACE][column] = symbol;
        row += MOVE_SPACE;
        winOutcome = true;
        active = false;
      }
      break;
    }
  }
}

void Activist::moveLeft(Town& townname, Polluter& pollutername)
{
  char polluterSymbol = pollutername.getSymbol();
  switch (townname.town[row + MOVE_SPACE][column])
  {
    case COP_SYMBOL:
    {
      dignity -= copLoss;
      replaceCop = true;
      townname.town[row][column] = EMPTY;
      townname.town[row - MOVE_SPACE][column] = symbol;
      row -= MOVE_SPACE;
      break;
    }
    case ROOT_SYMBOL:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      toxicity += roots[numRoots - rootcount];
      rootcount++;
      townname.town[row - MOVE_SPACE][column] = symbol;
      row -= MOVE_SPACE;
      break;
    }
    case WALL:
    {
      dignity -= bumpLoss;
      break;
    }
    case EMPTY:
    {
      if (replaceCop == true)
      {
        townname.town[row][column] = COP_SYMBOL;
        replaceCop = false; // Resets until Cop Symbol is hit again
      }
      else
      {
        townname.town[row][column] = EMPTY;
      }
      townname.town[row - MOVE_SPACE][column] = symbol;
      row -= MOVE_SPACE;
      break;
    }
    case EXIT:
    {
      exitOutcome = true;
      active = false;
      break;
    }
    default: // Assumes Polluter is caught options invalid
    {
      if (townname.town[row - MOVE_SPACE][column] == polluterSymbol)
      {
        if (replaceCop == true)
        {
          townname.town[row][column] = COP_SYMBOL;
          replaceCop = false; // Resets until Cop Symbol is hit again
        }
        else
        {
          townname.town[row][column] = EMPTY;
        }
        townname.town[row - MOVE_SPACE][column] = symbol;
        row -= MOVE_SPACE;
        winOutcome = true;
        active = false;
      }
      break;
    }
  }
}

bool Activist::getExit()
{
  return exitOutcome;
}
bool Activist::getOverdose()
{
  return overdoseOutcome;
}
bool Activist::getWin()
{
  return winOutcome;
}
bool Activist::getDignity()
{
  return dignityOutcome;
}


float Activist::getToxicity()
{
  return toxicity;
}




/*
float operator+ (const Activist& rhs)
{
  float toxicity = rhs.getToxicity;
  toxicity = toxicity + rhs.roots[rhs.rootcount];
  return toxicity;
}
*/
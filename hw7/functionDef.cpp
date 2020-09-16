/*
Programmer: Jeremy Ho     Date: 10/25/2016
Section : 1J              Instructor : Nathan Jarus
File: functionDef.cpp
Purpose: Function definition used to create a
database of each sector and trash pile weight
as well as people's name and their guilt value
randomnized
*/

#include "functionHeader.h"

int NumSector()
{
  int sector;
  sector = (rand() % (MAX_SECTOR_NUM)+MIN_SECTOR_NUM);
  return sector;
}

int trashweight()
{
  int weight;
  weight = (rand() % (MAX_TRASH_AMOUNT)+MIN_TRASH_AMOUNT);
  return weight;
}

int guiltvalue()
{
  int value;
  value = (rand() % (MAX_GUILT_AMOUNT)+MIN_GUILT_AMOUNT);
  return value;
}


wiggums makeRandomtrash()
{
  wiggums w;

  w.numsector = NumSector();
  w.trashweight = trashweight();
  return(w);
}

lisa makeRandomguilt(const int count)
{
  lisa l;

  l.name = OFFENDER_NAMES[count];
  l.guilt = guiltvalue();
  return(l);
}

void printWiggums(const wiggums w)
{
  cout << "Sector : " << w.numsector << " , " << w.trashweight << " pounds" << endl;
  return;
}

void printLisa(const lisa l)
{
  cout << l.name << " , Guilt = " << l.guilt << endl;
  return;
}

void sortArray(wiggums w[])
{
  int max;
  wiggums temp, maxValue;

  for (int i = 0; i < DATABASE_COUNT - 1; i++)
  {
    // Assume max from position i to end of array
    // is the patient at position i
    maxValue = w[i];
    max = i;

    // See if you can find a patient with a lexigraphically
    // larger name from position i+1 to the end of the array
    for (int j = i + 1; j < DATABASE_COUNT; j++)
    {
      if (w[j].trashweight > maxValue.trashweight)
      {
        maxValue = w[j];
        max = j;
      }
    }

    // Swap the patient at positionOfMax with the
    // patient at position i
    temp = w[i];
    w[i] = maxValue;
    w[max] = temp;
  }

  return;
}

void sortArray(lisa l[])
{
  int max;
  lisa temp, maxValue;

  for (int i = 0; i < DATABASE_COUNT - 1; i++)
  {
    // Assume max from position i to end of array
    // is the patient at position i
    maxValue = l[i];
    max = i;

    // See if you can find a patient with a lexigraphically
    // larger name from position i+1 to the end of the array
    for (int j = i + 1; j < DATABASE_COUNT; j++)
    {
      if (l[j].guilt > maxValue.guilt)
      {
        maxValue = l[j];
        max = j;
      }
    }

    // Swap the guilt value at positionOfMax with the
    // patient at position i
    temp = l[i];
    l[i] = maxValue;
    l[max] = temp;
  }

  return;
}

void findTopGuilty(const lisa l[])
{
  cout << "Top two guiltiest offender are : \n\n";
  cout << l[0].name << " with guilt value of " << l[0].guilt << endl;
  cout << l[1].name << " with guilt value of " << l[1].guilt << endl;
  return;
}

void findTrashOffender(const wiggums w[],const lisa l[])
{
  int index = 0;
  int value = 0;
  int totaltrashvalue = 0;
  float fiftypercent;
  
  for (int i = 0; i < DATABASE_COUNT; i++)
  {
    totaltrashvalue += w[i].trashweight;
  }

  fiftypercent = totaltrashvalue / FIFTY_PERCENT;

  for (int j = 0; value <= fiftypercent; j++)
  {
    value += w[j].trashweight;
    index = j;
  }

  cout << "The following " << index << " contributed to at least 50% of the trash pile : \n";
 
  for (int k = 0; (k < index); k++)
  {
    printLisa(l[k]);
  }

  return;
}

void totalSectortrash(const wiggums w[], const int sectornum)
{
  int total = 0; // total trash weight in each sector
  
  cout << "\nSector " << sectornum << ": " << endl;
  
  for (int i = 0; i < DATABASE_COUNT; i++)
  {
    if (w[i].numsector == sectornum)
    {
      cout << w[i].trashweight << " pounds" << endl;
      total += w[i].trashweight;
    }
  }
  cout << "Sector " << sectornum << " has a total trash weight of " << total << " pounds" << endl;
  return;
}

void findOffender(const wiggums w[], const lisa l[])
{
  int userinput;
  do
  {
    cout << "\nTrash Pile Identification (Quit by inputting 0)\n";
    cout << "Please input a particular trash pile you wish to inquire about: ";

    cin >> userinput;

    for (int i = 1; i < DATABASE_COUNT; i++)
    {
      if (userinput == w[i].trashweight)
      {
        cout << "The culprit is " << l[i].name << endl;
      }
      else
      {
        if (userinput < w[i].trashweight && userinput > w[i + 1].trashweight)
        {
          cout << "The culprit is probably " << l[i].name << endl;
        }
      }
    }

  } while (userinput != QUIT);
  return;
}

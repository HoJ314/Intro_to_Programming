/*
Programmer: Jeremy Ho     Date: 10/25/2016
Section : 1J              Instructor : Nathan Jarus
File: hw7.cpp
Purpose: Sort and create a database of each sector and 
trash pile weight as well as people's name and their 
guilt value randomnized. Find perp
*/

#include "functionHeader.h"

int main()
{
  wiggums WiggumsDatabase[DATABASE_COUNT]; // List of sector trash weight
  lisa LisaDatabase[DATABASE_COUNT]; // List of person's guilt value


  cout << "Welcome to the Dirty Crime Finder" << endl; // Greet user
  
  srand(time(NULL)); // Seeds random number generator

  for (int i = 0; i < DATABASE_COUNT; i++)
  {
    WiggumsDatabase[i] = makeRandomtrash();
  }

  sortArray(WiggumsDatabase); 

  for (int k = 0; k < DATABASE_COUNT; k++)
  {
    printWiggums(WiggumsDatabase[k]); 
  }
  
  cout << "------------------------" << endl;
 
  for (int j = 0; j < DATABASE_COUNT; j++)
  {
    LisaDatabase[j] = makeRandomguilt(j);
  }

  sortArray(LisaDatabase);

  for (int p = 0; p < DATABASE_COUNT; p++)
  {
    printLisa(LisaDatabase[p]);
  }
  cout << "-------------------------" << endl;

  findTopGuilty(LisaDatabase);

  cout << "-------------------------" << endl;
  findTrashOffender(WiggumsDatabase,LisaDatabase);
  cout << "-------------------------" << endl;

  totalSectortrash(WiggumsDatabase, SECTOR1); // Lists individual sector
  totalSectortrash(WiggumsDatabase, SECTOR2); // trash pile weight
  totalSectortrash(WiggumsDatabase, SECTOR3); // and totals them
  totalSectortrash(WiggumsDatabase, SECTOR4);
  totalSectortrash(WiggumsDatabase, SECTOR5);
  totalSectortrash(WiggumsDatabase, SECTOR6);
  totalSectortrash(WiggumsDatabase, SECTOR7);

  findOffender(WiggumsDatabase, LisaDatabase);

  return 0;
}
  

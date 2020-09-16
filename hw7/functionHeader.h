#ifndef HW7_H
#define HW7_H

/*
Programmer: Jeremy Ho     Date: 10/25/2016
Section : 1J              Instructor : Nathan Jarus
File: functionHeader.h
Purpose: Function prototypes used to create a
database of each sector and trash pile weight
as well as people's name and their guilt value
randomnized
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const string OFFENDER_NAMES[] = { "Homer", "Maggie", "Bart", "Moe", "Barney",
"Marge","Cletus", "Snake", "Mr.Burns", "Dr.Nick", "Krusty the Clown", 
"Chief Wiggum","Ralph Wiggum", "Skinner", "Lenny" };

const int MIN_GUILT_AMOUNT = 100;
const int MAX_GUILT_AMOUNT = 10000;
const int MIN_TRASH_AMOUNT = 25;
const int MAX_TRASH_AMOUNT = 500;
const int MIN_SECTOR_NUM = 1;
const int MAX_SECTOR_NUM = 7;
const int DATABASE_COUNT = 15;
const int FIFTY_PERCENT = 2;
const int QUIT = 0;
const int SECTOR1 = 1;
const int SECTOR2 = 2;
const int SECTOR3 = 3;
const int SECTOR4 = 4;
const int SECTOR5 = 5;
const int SECTOR6 = 6;
const int SECTOR7 = 7;

struct wiggums
{
  int numsector; 
  int trashweight; 
};

struct lisa
{
  string name;
  int guilt;
};

// Randomly choose a sector number
// Preconditions: None.
// Postconditions: A randomly chosen sector value
// is returned.
int NumSector();

// Randomly choose a trash weight amount.
// Preconditions: None.
// Postconditions: A randomly chosen trash pile weight amount between
// MIN_TRASH_AMOUNT and MAX_TRASH_AMOUNT is returned.
int trashweight();

// Randomly choose a guilt amount.
// Preconditions: None.
// Postconditions: A randomly chosen guilt value amount between
// MIN_GUILT and MAX_GUILT is returned.
int guiltvalue();

// Create a database with randomly chosen sector, and
// weight of trash pile.
// Preconditions: None.
// Postconditions: A patient with a chosen sector and trash weight returned
wiggums makeRandomtrash();

// Create a database with chosen name and randomly chosen guilt value
// Preconditions: None.
// Postconditions: A chosen name and guilt value returned
lisa makeRandomguilt(const int count);

// Output information about a sector's trash pile
// Preconditions: Parameter 'w' contains Wiggum's data.
// Postconditions: The information for the sector
// has been output to the screen.
void printWiggums(const wiggums w);

// Output information about a person's guilt value
// Preconditions: Parameter 'l' contains Lisa's data.
// Postconditions: The information for the person
// has been output to the screen.
void printLisa(const lisa l);

// Sort the contents of the array into descending order by trash weight.
// Preconditions: parameter 'w' should contain data in DATABASE_COUNT
// Postconditions: w[0] and w[DATABASE_COUNT - 1] are in descending order
// of trash weight
void sortArray(wiggums w[]);

// Sort the contents of the array into descending order by guilt value.
// Preconditions: parameter 'l' should contain data in DATABASE_COUNT
// Postconditions: l[0] and l[DATABASE_COUNT - 1] are in descending order
// of guilt value
void sortArray(lisa l[]);

//Finds the names of those that contributed to at least 50% of the
//trash pile weight related to guilt value
// Precondition: parameter 'w' and 'l' should contain data in DATABASE_COUNT
// Postcondition: The names that contributed to 50% of the trash 
// is outputted to screen
void findTrashOffender(const wiggums w[], const lisa l[]);

//Totals the weight of each trash pile in each sector
//Precondition: parameter 'w' contain data in DATABASE_COUNT
//Postcondition: Total trash weight in each sector is outputted to screen
void totalSectortrash(const wiggums w[], const int sectornum);

//Finds the most likely offender based on weight of trash pile related to guilt
//Precondition: parameter 'w' contain data in DATABASE_COUNT
//Postcondition: Total trash weight in each sector is outputted to screen
void findOffender(const wiggums w[], const lisa l[]);

//Finds the names of the top two guilt value
// Precondition: parameter 'l' should contain data in DATABASE_COUNT
// Postcondition: The names that have the highest two guilt value is outputted
void findTopGuilty(const lisa l[]);

#endif

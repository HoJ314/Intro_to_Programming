/*
Programmer: Jeremy Ho     Date: 12/09/2016
Section : 1J              Instructor : Nathan Jarus
File: Problem2.cpp
Purpose: Using given sequence, find which starting number,
under one million, produce the longest chain
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000000;
const int THREE = 3;
const int TWO = 2;
const int ONE = 1;


int main()
{
  int length_highest = 0; // Highest Length Storage
  int startNum;
  int lengthCount;

  for (int i = 1; i < MAX_NUMBER; i++)
  {
    lengthCount = 0; // Reset and initializes length to 1 until MAX_NUMBER
    startNum = i;
    do
    {
      if (startNum % 2 != 0) // Checks if Odd
      {
        startNum = startNum * THREE + ONE;
      }
      else
      {
        startNum /= TWO;
      }
      lengthCount++;
    } while (startNum != 1);

    if (lengthCount > length_highest)
    {
      length_highest = lengthCount;
      startNum = i;
    }
  }

  cout << "The starting number that produces the longest chain of sequence is :  " << startNum << endl;
  return 0;
}


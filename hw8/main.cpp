/*
Programmer: Jeremy Ho     Date: 11/08/2016
Section : 1J              Instructor : Nathan Jarus
File: main.cpp
Purpose: Simulation of a political
debate between two candidates and randomize their speech
as well as score them to determine who wins
*/

#include "functionHeader.h"


int main()
{
  int numcharacters;
  int candidate1score = 0;
  int candidate2score = 0;
  int candidate = 1;
  string prefix;
  string answer;
  srand(time(NULL)); //Seeds a random number generator


  for (int i = 1; i <= MAX_QUESTIONS; i++)
  {
    numcharacters = userquestions(candidate);
    
    answer = prefixanswer(candidate);
    cout << answer << endl;

    candidateanswer(candidate);

    if (candidate == 1) // Changes between candidate 1 and 2
      candidate = 2;
    else
      candidate = 1;

    cout << interjection(candidate) << endl;
  }

  return 0;
}


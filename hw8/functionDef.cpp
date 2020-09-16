/*
Programmer: Jeremy Ho     Date: 11/06/2016
Section : 1J              Instructor : Nathan Jarus
File: functionHeader.cpp
Purpose: Function definitions used to simulate a political
debate between two candidates and randomize their speech
as well as score them to determine who wins
*/

#include "functionHeader.h"

int userquestions(const int& candidate)
{
  char question[MAX_LENGTH];
  int numcharacters = 0;

  cout << "Question for candidate " << candidate << ": ";
  cin.getline(question, MAX_LENGTH);
  
  for (int i = 0; question[i] != '\0' ; i++)
  {
    if (question[i] != ' ')
    {
      numcharacters++;
    }
  }


  return(numcharacters);
}

char changepunctuation()
{
  int x = rand() % HUNDRED_PERCENT;
  if (x <= FORTY_PERCENT) // Within 40%
    return '.';
  else
  {
    if (x <= (FORTY_PERCENT + THIRTY_PERCENT)) //Within 30%
      return '?';
    else
    {
      return '!'; //Within the other 30%
    }
  }
}

string prefixanswer(const int& candidate)
{
  int x = rand() % HUNDRED_PERCENT;
  int y;
  int j = 0;
  int numberoflines = 0;
  char sentences[MAX_LENGTH];
  string prefix;
  ifstream fin;
  if (x <= 50)
  {
    fin.clear();
    fin.open("prefix_expressions.dat");

    while (getline(fin, prefix))
    {
      numberoflines++;
    }

    fin.close();
    fin.open("prefix_expressions.dat");

    y = rand() % numberoflines;

    for (int i = 0; i < y; i++)
    {
      getline(fin, prefix);
    }

    return prefix;
  }
  else
    return "";
}

void candidateanswer(const int& candidate)
{
  ifstream fin;
  int numofparts = (rand() % (MAX_RANDOM - MIN_RANDOM + EXCLUDE_ZERO)) + 
    MIN_RANDOM;
  int numentries;
  int words = 0;
  string randsentence[MAX_LENGTH];
  char answer[MAX_LENGTH];
  string sentence[MAX_RANDOM];
  char tempstring[MAX_LENGTH];
  int charactercount1 = 0;
  int charactercount2 = 0;
  int charactercount3 = 0;
  int spacecount = 0;
  int occurance = 0;
  string x;
  cout << "--------------------" << endl;
  cout << numofparts << endl;
  cout << "--------------------" << endl;
  fin.clear();
  if (candidate == 1)
  {
    fin.open("candidate1_sentences.dat");
  }
  else
  {
    fin.open("candidate2_sentences.dat");
  }
 
  if (!fin.good())
    cout << "FILE OPENING ERROR!!" << endl;

  fin >> numentries;
  
  for (int i = 0; i < numentries; i++)
  {
    getline(fin, randsentence[i]);
  }

  for (int j = 0; j < numofparts; j++)
  {
    sentence[j] = randsentence[rand() % numentries];
    strncpy_s(tempstring, sentence[j].c_str(), sizeof(tempstring));
    tempstring[sizeof(tempstring) - 1] = 0;
    cout << tempstring[j] << endl;

  }


  return;
}

string interjection(const int& candidate)
{
  int x = rand() % HUNDRED_PERCENT;
  int numentries;
  int y;
  string randsentence[MAX_LENGTH];
  ifstream fin;
  string interjectionsentence;
  if (x <= TWENTYFIVE_PERCENT)
  {
    if (candidate == 1)
    {
      fin.open("candidate1_interjections.dat");
    }
    else
    {
      fin.open("candidate2_interjections.dat");
    }

    fin >> numentries;

    for (int i = 0; i < numentries; i++)
    {
      getline(fin, randsentence[i]);
    }
    y = rand() % numentries;
    interjectionsentence = randsentence[y];
  }

  return interjectionsentence;
}

int getMultiplier()
{
  int multiplier = 0;
  int random = 0;

  random = rand() % HUNDRED_PERCENT;

  if (random <= 5) 
    multiplier = 2;
  else
  {
    if (random > 5 && random <= 7)
      multiplier = 3;
    else
      multiplier = 1;
  }
  return multiplier;
}

int letterValue(const char letter)
{
  int value = 0;
  for (int j = 0; j < strlen(ONE_POINT_LETTERS); j++)
  if (letter == ONE_POINT_LETTERS[j])
    value += ONEPOINT;
  else if (letter == TWO_POINT_LETTERS[j])
    value += TWOPOINT;
  else if (letter == THREE_POINT_LETTERS[j])
    value += THREEPOINT;
  else if (letter == FOUR_POINT_LETTERS[j])
    value += FOURPOINT;
  else if (letter == FIVE_POINT_LETTERS[j])
    value += FIVEPOINT;
  else if (letter == EIGHT_POINT_LETTERS[j])
    value += EIGHTPOINT;
  else if (letter == TEN_POINT_LETTERS[j])
    value += TENPOINT;
  else
    value += 0;

  return value;
}

int totalScore(char answer[])
{
  int total = 0;
  int length = strlen(answer);
  int multiplier;
  int j = 0;
  int wordScore[MAX_LENGTH];
  int wordCount = 0;

  for (int i = 0; i < length; i++)
  {

    if (answer[i] == ' ') //checks for space
    {
      multiplier = getMultiplier(); //determines which multiplier % chance
      wordScore[j] *= multiplier; 
      j++; //creates new wordScore
      wordCount++; //keeps a running total of all the words
    }
    else if (answer[i] == '.') //checks for ending
      wordScore[j] += 0;
    else
    {
      multiplier = getMultiplier();
      wordScore[j] += letterValue(answer[i]) * multiplier;
    }
  }

  for (j = 0; j <= wordCount; j++)
    total += wordScore[j]; //computes total for each answer

  return total;
}
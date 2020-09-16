#ifndef FUNCTION_H
#define FUNCTION_H

/*
Programmer: Jeremy Ho     Date: 11/06/2016
Section : 1J              Instructor : Nathan Jarus
File: functionHeader.cpp
Purpose: Function declaration used to simulate a political
debate between two candidates and randomize their speech
as well as score them to determine who wins
*/


#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_QUESTIONS = 8;
const int MAX_LENGTH = 200;
const int HUNDRED_PERCENT = 100;
const int THIRTY_PERCENT = 30;
const int FORTY_PERCENT = 40;
const int TWO_PERCENT = 2;
const int THREE_PERCENT = 3;
const int TWENTYFIVE_PERCENT = 25;
const int MIN_RANDOM = 2;
const int MAX_RANDOM = 4;
const int EXCLUDE_ZERO = 1;
const char ONE_POINT_LETTERS[] = {'e','a','i','o','n','r','t','l','s','u','E', 
'A','I','O','N','R','T','L','S','U'};
const char TWO_POINT_LETTERS[] = {'d','g','D','G'};
const char THREE_POINT_LETTERS[] = { 'b','c','m','p','B','C','M','P' };
const char FOUR_POINT_LETTERS[] = {'f','h','v','w','y','F','H','V','W','Y'};
const char FIVE_POINT_LETTERS[] = { 'k','K' };
const char EIGHT_POINT_LETTERS[] = { 'j','x','J','X' };
const char TEN_POINT_LETTERS[] = { 'q','z','Q','Z' };
const int ONEPOINT = 1, TWOPOINT = 2, THREEPOINT = 3, FOURPOINT = 4, 
FIVEPOINT = 5, EIGHTPOINT = 8, TENPOINT = 10;
const string SPACE = " ";

//User asks the candidate a question and counts the number of characters in it
//Precondition: None
//Postcondition: Returns a int value of how many characters are in the question
int userquestions(const int& candidate);
//Determines which punctuation the answer sentence should end in.
//Precondition: None
//Postcondition: Returns a punctuation character
char changepunctuation();
//Sentence that is generated and randomly spouted onto screen
//Precondition: None
//Postcondition: Returns and generates an array generated for user
void candidateanswer(const int& candidate);
//Sentence that appears before each answer with a chance
//Precondition: None
//Postcondition: Returns an array generated for user
string prefixanswer(const int& candidate);
//Sentence that appears with a 25% after the other candidates answer
//Precondition: None
//Postcondition: Returns an array generated for user
string interjection(const int& candidate);
//Determines if the letter or word gets a multiplier
//Precondition: None
//Postcondition: Returns a multiplier value of 1,2 or 3.
int getMultiplier();
//Grabs the value of the letter and outputs it
//Precondition: None
//Postcondition: Returns a value for the letter inputted
int letterValue(char letter);
//Computes final score for each answer
//Precondition: Word count is changed in the function, and answer array is brought in
//Postcondition: Total score is computed and returned
int totalScore(char answer[]);

#endif
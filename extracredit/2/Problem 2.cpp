/*
Programmer: Jeremy Ho     Date: 12/09/2016
Section : 1J              Instructor : Nathan Jarus
File: Problem2.cpp
Purpose: Find the sum of all even number fibonacci number
under four million
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

const int MAX_NUMBER = 4000000;

int main()
{
  int a = 1; // Term One starting at one
  int b = 1; // Term Two starting at one
  int result = 1; // Result from adding int a and b, initializes at zero
  int sum = 0; // Total sum of even numbers

  do // Keeps below 4 million
  {
    cout << result << " "; // Used to help me check if in fibonacci sequence
    result = a + b;
    b = a; // Moves the 2nd largest number to B.
    a = result; // Moves new term in sequence to A.
    if (result % 2 == 0) // Checks even
    {
      sum += result;
    }
  } while (result < MAX_NUMBER);

  cout << "\nThe sum of Even Fibonacci numbers is : " << sum << endl;

    return 0;
}


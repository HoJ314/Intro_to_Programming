/*
Programmer: Jeremy Ho
File: hw3.cpp
Section : 1J
Instructor : Nathan Jarus
Date: 09/13/2016
Purpose: Create a musical compositon, output sound,
determine amount of food for each animal, and compute
the next note to be played
*/

#include <iostream>
using namespace std;

const int imin = 10; // Minimum Inspiration Number
const int imax = 100; // Maximum Inspiration Number

int main()
{
  // Variable Declarations
  int inum; // Inspiration Number
  int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, H = 0; // Music Notes and starts at 0

                                                       // Greeting and Input
  cout << "Welcome to the Music Composition Generator for Animals!" << endl;
  cout << endl;

  do // Do-While loop to make sure integer is in between min and max
  {
    cout << "Please input a positive integer between 10 and 100 : ";
    cin >> inum;
    cout << endl;
    if ((inum < imin) || (inum > imax))
    {
      cout << "Invalid Entry, Try Again" << endl;
      cout << endl;
    }
  } while ((inum < imin) || (inum > imax));

  while (inum != 1) // Continues loop until inspiration number is 1
  {
    if (inum % 2 == 0) // Checks if even
    {
      inum /= 2; // Divides Inspiration number by two if even
    }
    else
    {
      inum = inum * 3 + 1; // Inspiration number times 3 plus one if odd
    }

    // Calculation to determine which note is played
    if (inum % 7 == 0) // 0 is A note
    {
      A++; // Adds one to total tally of A
      cout << "wah ";
    }
    if (inum % 7 == 1) // 1 is Bb note
    {
      B++;
      cout << "bleep ";
    }
    if (inum % 7 == 2) // 2 is C++ note
    {
      C++;
      cout << "do-wah ";
    }
    if (inum % 7 == 3) // 3 is D- note
    {
      D++;
      cout << "ding ";
    }
    if (inum % 7 == 4) // 4 is E# note
    {
      E++;
      cout << "honk ";
    }
    if (inum % 7 == 5) // 5 is Fb note
    {
      F++;
      cout << "wapp ";
    }
    if (inum % 7 == 6) // 6 is H note
    {
      H++;
      cout << "DOH! ";
    }
  }

  // Results
  cout << endl;
  cout << endl;
  cout << endl;
  cout << "The amount of food each animal should get is :" << endl;
  cout << "Animal             Amount of Food" << endl;
  // Number of Food given to each animal through assigned note
  cout << endl;
  cout << "El Chupacabra             " << A << endl;
  cout << "Buck Toothed Slug         " << B << endl;
  cout << "Freaky Fish               " << C << endl;
  cout << "3-legged snakes           " << D << endl;
  cout << "Trash Bears               " << E << endl;
  cout << "Hans                      " << F << endl;
  cout << "Cletus                    " << H << endl;
  cout << endl;
  cout << "The Music Composition Generator for Animals" << endl;
  cout << "Thank you for using the program! Have a nice day!" << endl;
  return 0;
}


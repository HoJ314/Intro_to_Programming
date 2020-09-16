/*
Programmer: Jeremy Ho     Date: 10/11/2016
Section : 1J              Instructor : Nathan Jarus
File: hw6.cpp
Purpose: Create a store menu, calculate price and quanitity
of each item using functions and random number generator.
*/

#include "hw6.h"

int main()
{
  bool quit = 0;
  int choice;
  int invroot1 = stockroot1; // Present Inventory amount
  int invroot2 = stockroot2;
  int invroot3 = stockroot3;
  int invroot4 = stockroot4;
  int invroot5 = stockroot5;
  int numroot1 = 0, numroot2 = 0, numroot3 = 0, numroot4 = 0, numroot5 = 0;
  float subtotal = 0, total; // Outputs

  // Out of Stock Status String
  string oos1 = "", oos2 = "", oos3 = "", oos4 = "", oos5 = "";

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  greeting();

  srand(time(NULL)); // Seed random number generator

  while (quit == 0) //Repeats menu until quit option selected
  {
   
    cout << "\nRoots 'n Stuff\n-------------\n";
    cout << "1. " << choice1 << " ($" << price1 << ") " << oos1 << endl;
    cout << "2. " << choice2 << " ($" << price2 << ") " << oos2 << endl;
    cout << "3. " << choice3 << " ($" << price3 << ") " << oos3 << endl;
    cout << "4. " << choice4 << " ($" << price4 << ") " << oos4 << endl;
    cout << "5. " << choice5 << " ($" << price5 << ") " << oos5 << endl;
    cout << "6. " << choice6 << endl << endl;
    choice = randchoice();

    switch (choice)
    {
    case 1:
      purchase(numroot1, stockroot1, invroot1, price1, subtotal);
      oos1 = outofstock(numroot1, stockroot1);
      break;
    case 2:
      purchase(numroot2, stockroot2, invroot2, price2, subtotal);
      oos2 = outofstock(numroot2, stockroot2);
      break;
    case 3:
      purchase(numroot3, stockroot3, invroot3, price3, subtotal);
      oos3 = outofstock(numroot3, stockroot3);
      break;
    case 4:
      purchase(numroot4, stockroot4, invroot4, price4, subtotal);
      oos4 = outofstock(numroot4, stockroot4);
      break;
    case 5:
      purchase(numroot5, stockroot5, invroot5, price5, subtotal);
      oos5 = outofstock(numroot5, stockroot5);
      break;
    case 6:
      quit = 1;
      break;
    default:
      cout << "\nTry again, I didn't understand you. \n" << endl;
      break;
    }
  }

  total = totalcost(subtotal);
  payment(total);

  signoff();
  return 0;
}


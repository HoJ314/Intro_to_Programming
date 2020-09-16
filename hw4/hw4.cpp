/*
Programmer: Jeremy Ho     Date: 09/25/2016
Section : 1J              Instructor : Nathan Jarus
File: hw4.cpp
Purpose: Create a store menu, calculate price and quanitity
of each item.
*/

#include <iostream>
using namespace std;

const string oos = "OUT OF STOCK";
const string choice1 = "Ginko Root";
const string choice2 = "Mandrake Root";
const string choice3 = "Ginseng Root";
const string choice4 = "Square Root";
const string choice5 = "Viratamin R Root";
const string choice6 = "Quit";
const int sroot1 = 5; // Starting Inventory Stock
const int sroot2 = 4;
const int sroot3 = 9;
const int sroot4 = 11;
const int sroot5 = 8;
const float price1 = 4.50; // Price for roots
const float price2 = 1.23;
const float price3 = 2.39;
const float price4 = 99.98;
const float price5 = 0.78;
const float tax = 0.16; // Tax Rate and Rounding
const float rounding = 0.5;

int main()
{
  string fname;
  bool quit = 0;
  int choice;
  int buynum;
  int invroot1 = sroot1; // Present Inventory amount
  int invroot2 = sroot2;
  int invroot3 = sroot3;
  int invroot4 = sroot4;
  int invroot5 = sroot5;
  int numroot1 = 0, numroot2 = 0, numroot3 = 0, numroot4 = 0, numroot5 = 0;
  float subtotal = 0, taxtotal, total, usercash, change; // Outputs

  // Out of Stock Status String
  string oos1 = "", oos2 = "",oos3 = "",oos4 = "",oos5 = "";

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "Welcome to Roots 'n Stuff!" << endl;
  cout << "What's your first name? ";
  cin >> fname;
  cout << "Hello, " << fname << "! Take a look at our wares." << endl;
  
  while (quit == 0) //Repeats menu until quit option selected
  {
    cout << "\nRoots 'n Stuff\n-------------\n";
    cout << "1. " << choice1 << " ($" << price1 << ") " << oos1 << endl;
    cout << "2. " << choice2 << " ($" << price2 << ") " << oos2 << endl;
    cout << "3. " << choice3 << " ($" << price3 << ") " << oos3 << endl;
    cout << "4. " << choice4 << " ($" << price4 << ") " << oos4 << endl;
    cout << "5. " << choice5 << " ($" << price5 << ") " << oos5 << endl;
    cout << "6. " << choice6 << endl;
    cout << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      if (numroot1 < sroot1) // Checks if there are roots present
      {
        cout << "\nHow many do you want to buy? ";
        cin >> buynum;
        invroot1 -= buynum;
        numroot1 += buynum;
        if (numroot1 >= sroot1)
          oos1 = oos; // Shows out of stock if out of inventory
        if (numroot1 > sroot1)
        { //Keeps number of roots bought to amount in stock
          numroot1 = sroot1; 
          cout << "Sorry, we are out of stock" << endl;
          cout << "We can only give you " << sroot1 << endl;
        }
        subtotal += price1 * numroot1; // Adds to subtotal
      }
      else
      {
        cout << "Stop trying to buy an item out of stock!" << endl;
      }
      break;

    case 2:
      if (numroot2 < sroot2)
      {
        cout << "\nHow many do you want to buy? ";
        cin >> buynum;
        invroot2 -= buynum;
        numroot2 += buynum;
        if (numroot2 >= sroot2)
          oos2 = oos;
        if (numroot2 > sroot2)
        {
          numroot2 = sroot2;
          cout << "Sorry, we are out of stock" << endl;
          cout << "We can only give you " << sroot2 << endl;
        }
        subtotal += (price2 * numroot2);
      }
      else
      {
        cout << "Stop trying to buy an item out of stock!" << endl;
      }
      break;
    case 3:
      if (numroot3 < sroot3)
      {
        cout << "\nHow many do you want to buy? ";
        cin >> buynum;
        invroot3 -= buynum;
        numroot3 += buynum;
        if (numroot3 >= sroot3)
          oos3 = oos;
        if (numroot3 > sroot3)
        {
          numroot3 = sroot3;
          cout << "Sorry, we are out of stock" << endl;
          cout << "We can only give you " << sroot3 << endl;
        }
        subtotal += price3 * numroot3;
      }
      else
      {
        cout << "Stop trying to buy an item out of stock!" << endl;
      }
      break;
    case 4:
      if (numroot4 < sroot4)
      {
        cout << "\nHow many do you want to buy? ";
        cin >> buynum;
        invroot4 -= buynum;
        numroot4 += buynum;
        if (numroot4 >= sroot4)
          oos4 = oos;
        if (numroot4 > sroot4)
        {
          numroot4 = sroot4;
          cout << "Sorry, we are out of stock" << endl;
          cout << "We can only give you " << sroot4 << endl;
        }
        subtotal += price4 * numroot4;
      }
      else
      {
        cout << "Stop trying to buy an item out of stock!" << endl;
      }
      break;
    case 5:
      if (numroot5 < sroot5)
      {
        cout << "\nHow many do you want to buy? ";
        cin >> buynum;
        invroot5 -= buynum;
        numroot5 += buynum;
        if (numroot5 >= sroot5)
          oos5 = oos;
        if (numroot5 > sroot5)
        {
          numroot5 = sroot5;
          cout << "Sorry, we are out of stock" << endl;
          cout << "We can only give you " << sroot5 << endl;
        }
        subtotal += price5 * numroot5;
      }
      else
      {
        cout << "Stop trying to buy an item out of stock!" << endl;
      }
      break;
    case 6:
      quit = 1;
      break;
    default:
      cout << "\nPlease enter a valid option. \n" << endl;
      break;
    }
  }
  taxtotal = (tax * subtotal) + rounding; // Calculates tax
  total = taxtotal + subtotal; // Adds tax to subtotal
  cout << "Subtotal : " << subtotal << endl;
  cout << "Tax : " << taxtotal << endl;
  cout << "Total : " << total << endl;
  do
  {
    cout << "\nWhat amount of cash will you be giving? ";
    cin >> usercash;
    if (usercash < total)
    {
      cout << "\nYou don't have enough.. Give me a bigger amount." << endl;
    }
  } while (usercash < total); // Repeats until given more than total
  change = usercash - total; // Calculates total change
  cout << "Your change comes to a total of " << change << endl;
  cout << "\nThank you for shopping at Roots 'n Stuff!" << endl;
  cout << "Please come again, " << fname << "!" << endl;
  
  return 0;
}


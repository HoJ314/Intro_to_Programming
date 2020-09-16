/*
Programmer: Jeremy Ho     Date: 10/11/2016
Section : 1J              Instructor : Nathan Jarus
File: RootFunction.cpp
Purpose: Function definition used to create a
store menu to buy items with random outputs
*/
#include "hw6.h"

void greeting()
{
  string fname;
  cout << "Welcome to Roots 'n Stuff!" << endl;
  cout << "What's your first name? ";
  cin >> fname;
  cout << "Hello, " << fname << "! Take a look at our wares." << endl;
  return;
}

void signoff()
{
  cout << "\nThank you for shopping at Roots 'n Stuff!" << endl;
  cout << "Please come again!" << endl;
  return;
}

string outofstock(int& numroot, const int& stockroot)
{
  if (numroot >= stockroot)
    return oos; // Shows out of stock if out of inventory
  else
    return instock;
}

int purchase(int& numroot, const int& stockroot, int& invroot,
  const float& price, float& subtotal)
{
  int buynum;
  int buyrand;
  int doublednum;
  if (numroot < stockroot) // Checks if there are roots present
  {
    cout << "How many do you want to buy? ";
    cin >> buynum;
    if (buynum < 0)
      cout << "Invalid Entry" << endl;
    else
    {
      doublednum = buynum * multiplybuy; 
      // Doubles user input for max limit for random number generator
      buyrand = randomnumber(1, doublednum);

      if (buyrand == buynum) // Determines appropriate message to say
        cout << equalbuynum << buyrand << endl;
      else
      {
        if (buyrand < buynum)
          cout << lessbuynum << buyrand << endl;
        else
        {
          if (buyrand > buynum)
            cout << morebuynum << buyrand << endl;
        }
      }

      if (buyrand > invroot)
      { //Keeps number of roots bought to amount in stock
        buyrand = invroot;
        cout << "Darn, we are out of stock" << endl;
        cout << "Too bad, you can only get " << invroot << endl;
      }
      invroot -= buyrand;
      numroot += buyrand;
      subtotal += (price * buyrand); // Adds to subtotal
    }
  }
  else
  {
    cout << "This is out of stock!" << endl;
  }
  return (invroot, numroot, subtotal);
}

float totalcost(float subtotal)
{
  float taxtotal;
  float total;
  float tax;

  if (subtotal < mintaxlimit) // Determines tax rate depending on subtotal
    tax = tax1;
  else
  {
    if (subtotal >= mintaxlimit || subtotal <= maxtaxlimit)
      tax = tax2;
    else
    {
      if (subtotal > maxtaxlimit)
        tax = tax3;
    }
  }

  taxtotal = (tax * subtotal) + rounding; // Calculates tax
  total = taxtotal + subtotal; // Adds tax to subtotal
  cout << "Subtotal : " << subtotal << endl;
  cout << "Tax : " << taxtotal << endl;
  cout << "Total : " << total << endl;
  return total;
}

void payment(float total)
{
  float usercash;
  float change;
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
  return;
}

int randomnumber(int min, int max)
{
  int val;
  val = ((rand() % max) + min);
  return val;
}



int randchoice()
{
  int userchoice;
  int randomchoice;
  int message;
  string randitem;
  do
  {
    cin >> userchoice;
    if (userchoice <= 0 || userchoice >= 7)
      cout << "Please input a valid choice" << endl;
  } while (userchoice <= 0 || userchoice >= 7);
  randomchoice = randomnumber(1, 7); // Set random choice between 1-7

  if (randomchoice == userchoice)
  {
    cout << msg0 << endl; //Message if random number is same as user choice
  }
  else
  { // Determine what choice the random generator chose
    if (randomchoice == 1)
      randitem = choice1;
    else
    {
      if (randomchoice == 2)
        randitem = choice2;
      else
      {
        if (randomchoice == 3)
          randitem = choice3;
        else
        {
          if (randomchoice == 4)
            randitem = choice4;
          else
          {
            if (randomchoice == 5)
              randitem = choice5;
            else
            {
              if (randomchoice == 6)
                randitem = choice6;
              else
              {
                if (randomchoice == 7)
                  randitem = choice7;
              }
            }
          }
        }
      }
    }

    message = randomnumber(1, 7); // Random message
    switch (message)
    { // Select a random message depending on value returned
    case 1:
      cout << msg1 << randitem << endl;
      break;
    case 2:
      cout << msg2 << randitem << endl;
      break;
    case 3:
      cout << msg3 << randitem << endl;
      break;
    case 4:
      cout << msg4 << randitem << endl;
      break;
    case 5:
      cout << msg5 << randitem << endl;
      break;
    case 6:
      cout << msg6 << randitem << endl;
      break;
    case 7:
      cout << msg7 << randitem << endl;
      break;
    }
  }
  return randomchoice;
}

#ifndef ROOT_H
#define ROOH_H

/*
Programmer: Jeremy Ho     Date: 10/11/2016
Section : 1J              Instructor : Nathan Jarus
File: hw6.h
Purpose: Function prototypes used to create a
store menu to buy items with random outputs
*/

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

const string oos = "OUT OF STOCK";
const string instock = "";
const string choice1 = "Ginko Root";
const string choice2 = "Mandrake Root";
const string choice3 = "Ginseng Root";
const string choice4 = "Square Root";
const string choice5 = "Vitamin R Root";
const string choice6 = "Quit";
const string choice7 = "Nothing";
const int stockroot1 = 5; // Starting Inventory Stock
const int stockroot2 = 12;
const int stockroot3 = 12;
const int stockroot4 = 12;
const int stockroot5 = 12;
const float price1 = 4.50; // Price for roots
const float price2 = 1.23;
const float price3 = 2.39;
const float price4 = 99.98;
const float price5 = 0.78;
const float tax1 = 0.50; // Tax Rate depending on subtotal
const float tax2 = 0.27;
const float tax3 = 0.02;
const int maxtaxlimit = 300;
const int mintaxlimit = 100;
const float rounding = 0.005;
// Random message for random item choice
const string msg0 = "Fine!... but you're gonna be sorry.";
const string msg1 = "No, you really want ";
const string msg2 = "As my uncle Hal would say,\"I can\'t do that for "
"you, Dave. You want ";
const string msg3 = "Only a loooooser would want THAT. "
"Try this instead: ";
const string msg4 = "WRONG! I'm sure you meant to pick ";
const string msg5 = "PPpfffffttt. I think you need ";
const string msg6 = "Only idiots choose that. Better to have some ";
const string msg7 = "Tss, you must be Homer! Only Homer would want that. "
"Lisa's preference is ";
const int multiplybuy = 2;
//Message choice depending if random number is less, equal, or more than input
const string lessbuynum = "That's waayyy too much for you. You want ";
const string morebuynum = "Naw naw naw, you need ";
const string equalbuynum = "I can do that ... ";

//Pre: None
//Post: A message output to the screen
//Description: Greeting message to user
void greeting();

//Pre: None
//Post: A message output to the screen
//Description: Good bye message to user
void signoff();

//Pre: Random number generator has been seeded
//Post: Value of subtotal, number of roots left, and number user has returned
//Description: Calculates and adds on to subtotal of given bought quantity
int purchase(int& numroot, const int& stockroot, int& invroot, 
  const float& price, float& subtotal);

//Pre: 
//Post: 
//Description: 
string outofstock(int& numroot, const int& stockroot);

//Pre: 
//Post: 
//Description: 
float totalcost(float subtotal);

//Pre: None
//Post: Subtotal, tax, and total cost outputted to screen
//Description: Displays subtotal, tax, and total cost to user
void payment(float total);

//Pre: Random number generator has been seeded
//Post: Random choice and message is returned
//Description: Prompt for user choice and randomly assign another choice
// to replace the user's choice if different, returning a snarky message
int randchoice();

//Pre: Random Number Generator has been seeded
//Post: Returns a random value between max and min
//Description: Generate a number between max and min limit
int randomnumber(int min, int max);

#endif

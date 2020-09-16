/*
Programmer: Jeremy Ho
File: hw5.cpp
Section : 1J
Instructor : Nathan Jarus
Date: 10/03/2016
Purpose: Calculate GUILT value from four different functions
asking for user inputs.
*/

#include <iostream>
using namespace std;

//Description : Greeting message output to screen
//Pre : None
//Post : Greeting message output to screen void
void greeting();

//Description : Signoff message output on the screen
//Pre : None
//Post : Signoff message output on screen void
void signoff();

//Description : Reads user input for foodwaste
//Pre : Positive value between 0 and 100
//Post : Food Waste value returned float
float foodwaste();

//Description : Reads user input of transit use and mileage if true
//Pre : Positive miles between 1 and 250 if bool statement true, else 0
//Post : Returns miles value as int if bool statement is true else 0
int transit();

//Description : Reads if user input is Mr Burns or related, or asks for age
//Pre : None
//Post : Value returned as int
int industrial_complicity();

//Description : Reads user input for pig eaten and calculate methane produce
//Pre : Pig eaten is between 1 and 10
//Post : Returns methane value as float
float methane_production(float foodvalue);

//Description : Modifies referenced value into its new value
//Pre : None
//Post : Returns new value as a float
float valuemodifier(float& value,const float& multiplier,const float& offset);

const string option1 = "Wasteful (food) Consumption";
const string option2 = "Public Transit Usage";
const string option3 = "Industrial Complicity";
const string option4 = "Farm-related Methane Production";
const string option5 = "Compute GUILT value";
const int Burns_Coefficient = 570;
const int half = 2;
const int methane_times = 3;
const int methane_add = 5;
const float food_times = 1.5;
const float food_add = 6.0;
const float transit_times = -2.0;
const float transit_add = 1.0;

int main()
{
  short choice; // User Menu Choice
  float foodvalue; // Function Result Output
  float transitvalue;
  int industryvalue;
  float methanevalue;
  float GUILT; // Final Result Output
  bool picked1 = 0; 
  bool picked2 = 0;
  bool picked3 = 0;
  bool picked4 = 0;
  bool picked5 = 0;

  greeting();

  while (picked5 == 0) // Repeats menu until compute GUILT option chosen
  {
    cout << " \n Carbon Footprint Survey\n--------------------------" << endl;
    cout << "1. " << option1 << endl;
    cout << "2. " << option2 << endl;
    cout << "3. " << option3 << endl;
    cout << "4. " << option4 << endl;
    cout << "5. " << option5 << endl << endl;
    cin >> choice; // User Input Choice
    switch (choice)
    {
    case 1:
      if (picked1 == 0) // Checks if chosen before
      {
        picked1 = 1; // Change value to show it's been chosen before
        foodvalue = foodwaste(); // Calls function
      }
      else // Tells user they already did this option
      {
        cout << "You can't choose this option again" << endl;
      }
      break;

    case 2:
      if (picked2 == 0)
      {
        picked2 = 1;
        transitvalue = transit();
      }
      else
      {
        cout << "You can't choose this option again" << endl;
      }
      break;

    case 3:
      if (picked3 == 0)
      {
        picked3 = 1;
        industryvalue = industrial_complicity();
      }
      else
      {
        cout << "You can't choose this option again" << endl;
      }
      break;

    case 4:
      if (picked4 == 0)
      {
        if (picked1 == 1)
        {
          picked4 = 1;
          methanevalue = methane_production(foodvalue);
        }
        else
        {
          cout << "Please complete option one before option four" << endl;
        }
      }
      else
      {
        cout << "You can't choose this option again" << endl;
      }
      break;

    case 5:
      if (picked1 == 1 && picked2 == 1 && picked3 == 1 && picked4 == 1)
      {
        picked5 = 1;
      }
      else
        cout << "Please complete all four options first" << endl;
    }
  }
 // Calculate new food waste and transit value
  foodvalue = valuemodifier(foodvalue, food_times, food_add);
  transitvalue = valuemodifier(transitvalue, transit_times, transit_add);
 // Adds the result from all 5 functions
  GUILT = foodvalue + transitvalue + industryvalue + methanevalue; 
  cout << "Oh wow! Your GUILT value is " << GUILT << "..." << endl << endl;

  signoff();
 
  return 0;
}


void greeting()
{
  cout << "Welcome to the GUILT calculator\n"
    << "This survey will calculate your carbon footprint amount" << endl;
  return;
}


float foodwaste()
{
  float userfood;
  do
  {
    cout << "How many pounds of food is prepared but not eaten?"
      << " (Between 0 and 100) : ";
    cin >> userfood;
    if (userfood <= 0 || userfood >= 100)
    {
      cout << "Please input a valid value" << endl;
    }
  } while (userfood <= 0 || userfood >= 100);
  return userfood;
}

int transit()
{
  bool use_transit;
  int miles;
  cout << "Do you use any kind of public transit? (1 - Yes, 0 - No) : ";
  cin >> use_transit;
  if (use_transit == 1) // Reads mile input if user uses public transit
  {
    do
    {
      cout << "How many miles do you travel each day? (Between 1 - 250) : ";
      cin >> miles;
      if (miles < 1 || miles > 250)
      {
        cout << "Please input a valid value" << endl;
      }
    } while (miles < 1 || miles > 250);
    return miles;
  }
  else
    return 0;
}

int industrial_complicity()
{
  bool Mr_Burns;
  bool Burns_Related;
  int destruction_coefficient;
  int userage;
  cout << "Are you Mr. Burns? (1 - Yes, 0 - No) : ";
  cin >> Mr_Burns;
  if (Mr_Burns == 1)
  {
    destruction_coefficient = Burns_Coefficient;
    cout << destruction_coefficient << endl;
    return destruction_coefficient;
  }
  else
  {
    cout << "Are you related to Mr. Burns? (1 - Yes, 0 - No) : ";
    cin >> Burns_Related;
    if (Burns_Related == 1)
    {
      destruction_coefficient = Burns_Coefficient / half;
      return destruction_coefficient;
    }
    else
    {
      do
      {
        cout << "How old are you? : ";
        cin >> userage;
        if (userage < 10 || userage > 100)
        {
          cout << "Please enter a valid age" << endl;
        }
      } while (userage < 10 || userage > 100);
      return userage;
    }
  }
}

float methane_production(float foodvalue)
{
  float value;
  int pignum;
  do
  {
    cout << "How many whole pigs have you eaten? (Between 1 and 10) : ";
    cin >> pignum;
    if (pignum < 1 || pignum > 10)
    {
      cout << "Please enter a valid amount" << endl;
    }
  } while (pignum < 1 || pignum > 10);
  value = (foodvalue*pignum*pignum)+(methane_times*pignum)+methane_add;
  return value;
}

float valuemodifier(float& value, const float& multiplier, const float& offset)
{
  float newvalue;
  newvalue = (value * multiplier) + offset;
  return newvalue;
}



void signoff()
{
  cout << "Thank you for using the GUILT Calculator\nHave a nice day!" << endl;
  return;
}
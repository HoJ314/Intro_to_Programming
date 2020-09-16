/*
Programmer: Jeremy Ho
File: hw2.cpp
Section : 1J
Date: 09/06/2016
Purpose: Create a tank based on given length and determine
volume of tank and water, dimensions, number of fishes, and
 mass of nuclear waste to keep fish alive
*/

#include <iostream>
using namespace std;

int main()
{
  // Variable Declarations
  int length;
  bool spfish; // Presense of special fish
  float width;
  float height;
  float tankvol; // Tank Cap
  float watervol; // Amount of water in tank
  float volc = 7.48; // Tank Volume Constant
  float fish; // Number of fish that can be in tank
  int LIFE = 11; // Constant given to keep special fish alive
  float waste;

  //Greetings and Introduction
  cout << "Welcome to Fish Tank Building Simulator 2016" << endl;
  cout << endl;

  // User Inputs
  cout << "Please enter desired length (ft) :  ";
  cin >> length;
  cout << "Are there any fishes with more than two eyes? (1-yes,0-no): ";
  cin >> spfish;

  // Calculations
  height =static_cast<int>(length * 2.0/3.0); 
  width = static_cast<int>(length * .25);
  tankvol = length * width * height * volc;
  watervol = tankvol - (2.0*spfish); // Subtract 2 from tank from bool
  fish = static_cast<int>(watervol/25.0); // Determines fish number from water volume
  waste = LIFE/(height*12.0);

  //Results and Output
  cout << endl;
  cout << "The specification of your tank are : " << endl;
  cout << endl;
  cout << "Length =   " << length << " feet " << endl;
  cout << "Height =   " << height << " feet" << endl;
  cout << "Width =   " << width << " feet" << endl;
  cout << "Total Tank Volume =   " << tankvol << " gallons" << endl;
  cout << "Water =   " << watervol << " gallons" << endl;
  cout << endl;
  cout << "This tank can hold " << fish << " fishes" << endl;
  cout << "The fishes needs " << waste << " rads of nuclear waste." << endl;
  cout << endl;
  cout << "Thank you for using the Fish Tank Building Simulator" << endl;
  cout << "Have a nice day!" << endl;
  return 0;
}

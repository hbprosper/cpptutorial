//----------------------------------------------------------------------------
// C++ Tutorial
// 08_functions
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <fstream>    // for ofstream and ifstream
#include <sstream>    // for stringstream
#include <string>
#include <cmath>      // math functions
#include <stdlib.h>
#include <stdio.h>    // for sprintf
#include <time.h>     // ctime etc.
#include "colors.h"
//----------------------------------------------------------------------------
using namespace std;


// Variables and functions defined at this level are visible to all functions 
// in this file. The variables and functions are said to be in global scope.

// Functions
//
// syntax:
// type name( arguments )

// Scope:
// Variables defined within a function are local to that function; that is,
// they are in local scope.


// 1. function with 1 argument
//    Variable message is passed by value (that is, a copy is made of the 
//    variable).

void error(string message)
{
  cout << "** " << message << endl;
  exit(0);
}

// 2. function with a default argument. If no value is given when this
// function is called the variable len will be set equal to 24.

string getTime(int len=24)
{
  cout << "getTime len = " << len << endl;
  time_t tt = time(0);
  string ct(ctime(&tt)); 
  return ct.substr(0,len);
}

// 3. overloaded functions
// x is by value 
// n is by reference
// y is by pointer
// d is defaulted

void compute(float x, int& n, float* y, int d=2)
{
  *y = pow(x, n)/d;
  n++;
  x = 4.2;
  cout << "Jill" << endl;
}

float compute(float x, int n, int d=2)
{
  float y = pow(x, n);
  cout << "Fred" << endl;
  return y;
}

//----------------------------------------------------------------------------
int main()
{
  // get date and time

  string datetime = getTime();
  cout << GREEN << datetime << RESET_COLOR << endl;
  cout << datetime.size() << endl;
  //exit(0);

  int n = 3;
  float x = 2.0;
  float y = 0;

  cout << BLUE << "overloaded functions" << RESET_COLOR << endl;

  cout << "before compute (1)" << endl;
  cout << "\tn = " << n << endl;
  cout << "\tx = " << x << endl;
  cout << "\ty = " << y << endl;

  // Get pointer to variable y and call first version
  // of compute

  float* yptr = &y; 
  compute(x, n, yptr);

  cout << "after compute (1)" << endl;
  cout << "\tn = " << n << endl;
  cout << "\tx = " << x << endl;
  cout << "\ty = " << y << endl;

  y = 0;
  y = compute(x, n);

  cout << "after compute (2)" << endl;
  cout << "\tn = " << n << endl;
  cout << "\tx = " << x << endl;
  cout << "\ty = " << y << endl;

  return 0;
}


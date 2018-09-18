//----------------------------------------------------------------------------
// C++ Tutorial
// 10_class1: simple class
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include "Particle.h"
//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
int main()
{
  Particle p1(20,2,3,4);
  Particle p2(20,2,3,4);

  Particle p = p1 + p2;

  cout << p << endl;
}


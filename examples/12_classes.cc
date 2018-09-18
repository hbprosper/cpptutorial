//----------------------------------------------------------------------------x
// C++ Tutorial
// 12_class: STL vector
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Particle.h"
//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
int main()
{
  Particle p1(100,2,6,50);
  Particle p2(200,1,3,40);
  Particle p3(250,12,3,40);
  Particle p4(500,0.5,3,40);

  Particle p = p1 + p2;

  vector<Particle> vp;
  vp.push_back(p1);
  vp.push_back(p2);
  vp.push_back(p3);
  vp.push_back(p4);

  for (unsigned i=0; i < vp.size(); i++)
    cout << i << "\t" << vp[i] << endl;

  sort(vp.end(), vp.begin());

  cout << endl;

  for (unsigned i=0; i < vp.size(); i++)
    cout << i << "\t" << vp[i] << endl;
}


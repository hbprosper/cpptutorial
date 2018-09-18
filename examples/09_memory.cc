//----------------------------------------------------------------------------
// C++ Tutorial
// 09_memory: dynamic memory
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include "colors.h"
//----------------------------------------------------------------------------
using namespace std;

//----------------------------------------------------------------------------

struct A
{
  int I;
  int K;
};

int main()
{

  // new

  cout << RED << "new" << RESET_COLOR << endl;

  // allocate memory for an int array of size 4

  int* I = new int[4];
  I[0] = 1;
  I[1] = 2;
  I[2] = 3;
  I[3] = 4;
  //I[4] = 5; // bug!

  //cout << I[4] << endl;
  //exit(0);

  // allocate memory for a vector<int>

  vector<int>* J = new vector<int>();
  J->push_back(1);
  J->push_back(2);
  J->push_back(3);
  J->push_back(4);

  for(int i=0; i < 4; i++)
    cout << i << "\t" << I[i] << " " << I+i << "\t" << J->at(i) << "\t" << (*J)[i] << endl;

  cout << BLUE << "delete" << RESET_COLOR << endl;


  vector<int> JJ;
  JJ.push_back(1);
  JJ.push_back(2);
  JJ.push_back(3);
  JJ.push_back(4);

  delete[] I;
  delete J;

  return 0;
}


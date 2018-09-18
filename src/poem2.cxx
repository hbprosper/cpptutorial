//----------------------------------------------------------------------------
// C++ Tutorial
// This is to be compiled into a dynamic shared object
//----------------------------------------------------------------------------
#include <iostream>
#include "poem.h"
#include "colors.h"

using namespace std;

namespace famous {
  void poem()
  {
    cout << BLUE <<
      "The time has come the walrus said\n"
      "To speak of many things\n"
      "Of shoes and ships and sealing wax\n"
      "Of cabbages and kings\n"
      "Of why the sea is boiling hot\n"
      "And whether pigs have wings\n"
	 << RESET_COLOR << endl;
  }
}








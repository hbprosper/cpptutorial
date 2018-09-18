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
    cout << RED << 
      "Good people all of every sort\n"
      "Give ear unto my song\n"
      "For if you find it wondrous short\n"
      "It cannot hold you long\n"
	     << RESET_COLOR << endl;
  }
}






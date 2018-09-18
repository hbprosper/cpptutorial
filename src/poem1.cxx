//----------------------------------------------------------------------------
// C++ Tutorial
// This is to be compiled into a dynamic shared object
//----------------------------------------------------------------------------
#include <iostream>
#include "poem.h"

using namespace std;

namespace famous {
  void poem()
  {
    cout << 
      "To be or not to be, that is the question\n"
      "Whether tis nobler in the mind\n"
      "to suffer the slings and arrows of outrageous fortune\n"
      "Or to take up arms against a sea of troubles\n"
      "And in so doing defeat them?\n"
	 << endl;
  }
}






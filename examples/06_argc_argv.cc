//----------------------------------------------------------------------------
// C++ Tutorial
// 05_argc_argv: parsing of command line using getopt and switch statement
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include "colors.h"
//----------------------------------------------------------------------------
using namespace std;

// argc = number of entries in array of character arrays argv
// first character array is argv[0], 2nd is argv[1], etc.

int main(int argc, char** argv)
{
  char optchar=0;        // single-character command line option

  // Loop until there are no more entries in argv

  // ab:c: means that this program recognizes the following options
  // -a    without a value
  // -b=X  with value X
  // -c=Y  with value Y

  while ( (optchar = getopt(argc, argv, "ab:c:")) != -1)
    {
      switch (optchar)
	{
	case 'a':
	  { 
	    cout << "option: " << optchar << endl;
	    break;
	  }
	case 'b':
	case 'c':
	  {
	    // optarg is the value of the option
	    cout << "switch: " << optchar << "\tvalue: " << optarg << endl;
	    break;
	  }
	default:
	  {
	    cout << "bad option" << endl;
	    exit(0);
	  }
	}
    }

  return 0;
}





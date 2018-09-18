//----------------------------------------------------------------------------
// C++ Tutorial
// example 4: control structures
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <getopt.h>
//#include <stdlib.h>
#include "colors.h"
//----------------------------------------------------------------------------
using namespace std;

int main()
{
  int X = 2;
  int Y = 3;

  // if statement

  cout << RED << "\nif statement\n" << RESET_COLOR << endl;

  if ( Y > X )
    cout << "Y > X" << endl;

  else if ( Y == X )
    cout << "Y == X" << endl;

  else
    {
      cout << "Y <= X" << endl;
      cout << "compound statements must be enclosed in braces" << endl;
    }

  // while statement
  // this statement terminates when the count variable reaches 10
  
  cout << BLUE << "\nwhile \n" << RESET_COLOR << endl;

  int sum = 0;
  int count = 0;
  while ( count < 10 )
    {
      count++;
      sum += count;
      cout << count << "\t" << sum << endl;
    }

  // do while statement
  // this statement terminates when the count variable reaches 10
  
  cout << GREEN << "\ndo ... while \n" << RESET_COLOR << endl;

  int fact = 1;
  count = 0;
  do
    {
      count++;
      fact *= count;
      cout << count << "\t" << fact << endl;
    } while  ( count < 10 );

  // for statement
  // n is incremented at the end of the loop

  cout << YELLOW << "\nfor \n" << RESET_COLOR << endl;

  int p2 = 1;
  for (int n=0; n < 10; n++)
    {
      p2 *= 2;
      cout << n+1 << "\t" << p2 << endl;
    }


  // switch statement

  cout << MAGENTA << "\nswitch \n" << RESET_COLOR << endl;

  for (int n=1; n <= 5; n++)
    {
      switch (n)
	{
	case 1:
	  {
	    cout << n << "\tGood people all, of every sort" << endl;
	    break;
	  }
	case 2:
	  {
	    cout << n << "\tGive ear unto my song" << endl;
	    break;
	  }
	case 3:
	  {
	    cout << n << "\tAnd if you find it wondrous short" << endl;
	    break;
	  }
	case 4:
	  {
	    cout << n << "\tIt cannot hold you long" << endl;
	    break;
	  }
	default:
	  {
	    cout << "\t\tfrom An Elegy On The Death Of A Mad Dog" << endl;
	    cout << "\t\t\tby Oliver Goldsmith (1730-1774)" << endl;
	  }
	}
    }

  return 0;
}





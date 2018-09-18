//----------------------------------------------------------------------------
// C++ Tutorial
// example 5: basic I/O
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <fstream>    // for ofstream and ifstream
#include <sstream>    // for stringstream
#include <string>
#include <stdlib.h>
#include <stdio.h>    // for sprintf
#include "colors.h"
//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
int main()
{
  // get name of output file

  // write prompt to screen, without an "endl"

  cout << "\n07_io" << endl;
  cout << GREEN << "\toutput file name> " << RESET_COLOR;

  // get name entered by user

  string outfile;
  cin >> outfile;

  // ofstream

  cout << RED << "\nofstream \n" << RESET_COLOR << endl;

  // open output file. Note: somewhat annoyingly, ofstream needs a 
  // character array rather than a string.

  ofstream fout(outfile.c_str());
  if ( ! fout.good() )
    { 
      cout << "unable to create file " << outfile << endl;
      exit(0);
    }

  // Write a table of data to file
  // use C function sprintf to get precise control of format

  // Write out header: each column heading is given a 10-character field

  char record[256];
  sprintf(record, "%10s %10s %10s%10s", "n", "sum", "2**n", "n!");
  fout << record << endl;
  cout << record << endl;

  int sum = 0;
  int fact= 1;
  int p2  = 1;
  for (int n=1; n <= 10; n++)
    {
      sum  += n;
      fact *= n;
      p2   *= 2;

      if ( n % 2 == 0 )
	sprintf(record, "%10d %10d %10d%10d", n, sum, p2, fact);
      else
	sprintf(record, "%10d %10d     %10d      %10d", n, sum, p2, fact);

      fout << record << endl;
      cout << record << endl;
    }
  fout.close();
  //exit(0);

  // ifstream

  // Read back file and extract n!

  cout << BLUE << "\nifstream \n" << RESET_COLOR << endl;

  ifstream fin(outfile.c_str());
  if ( ! fin.good() )
    { 
      cout << "unable to open file " << outfile << endl;
      exit(0);
    }
  // use getline to read an entire line delimited by a newline character (\n)
  // the while terminates if there are no more lines to read (end of file)

  string line;
  
  // read header
  getline(fin, line);

  // then read data
  while ( getline(fin, line) )
    {
      // istringstream is first given the string "line"
      // containing the line that has just been read in
      istringstream iin(line);

      // then it used just like cin
      int n, sum, p2, fact;
      iin >> n >> sum >> p2 >> fact;
      cout << fact << endl;
    }
  fin.close();

  return 0;
}


//----------------------------------------------------------------------------
// C++ Tutorial
// example 2: C++ types
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include "colors.h"

using namespace std;

// An example of an enumerated type

enum Color
  {
    KRED = 42,
    KORANGE,
    KYELLOW,
    KGREEN = 60,
    KBLUE,
    KINDIGO,
    KVIOLET
  };

// An example of s simple struct

struct FourVector
{
  float px;
  float py;
  float pz;
  float energy;
};

//----------------------------------------------------------------------------
int main()
{
  // Basic types

  cout << RED << "\nbasic types\n" << RESET_COLOR << endl;

  double c = 1.2e130;        // 8 bytes on a 32-bit machine
  long   e = 1234556791;     // 8 bytes ::
  float  b = 3.1415926536;   // 4 bytes ::
  int    a = 42;             // 4 bytes ::
  int    aa= 0;
  short  d = 0xFF;           // 2 bytes ::
  char   f = 'A';            // 1 byte
  bool   g = true;           // 1 byte

  cout << "double\tsize = " << sizeof(c) << " bytes" << endl;
  cout << "long\tsize = " << sizeof(e) << " bytes" << endl;
  cout << "float\tsize = " << sizeof(b) << " bytes" << endl;
  cout << "int\tsize = " << sizeof(a) << " bytes" << endl;
  cout << "short\tsize = " << sizeof(d) << " bytes" << endl;
  cout << "char\tsize = " << sizeof(f) << " byte" << endl;
  cout << "bool\tsize = " << sizeof(g) << " byte" << endl;
  cout << "FourVector\tsize = " << sizeof(FourVector) << " byte" << endl;


  // enum (enumerated type)

  int icolor = KRED;
  cout << "int icolor = " << icolor << endl;

  Color  color = KORANGE;
  cout << "\ncolor code = " << color << endl;

  int jcolor = KVIOLET;
  cout << "int jcolor = " << jcolor << endl;

  // struct

  FourVector p;

  p.px = 42.0;
  p.py =-2.0;
  p.pz = 12.3;
  p.energy = 250.0;

  //---------------------------------------------------------
  // strings
  //---------------------------------------------------------

  cout << BLUE << "\nstrings\n" << RESET_COLOR << endl;

  string record("Thou lump");
  cout << record << endl;

  // string attributes

  // size
  cout << record << " contains " << record.size() << " characters " << endl;
  
  // concatenation
  record = record + " of foul deformity";
  cout << record << endl;

  // searching
  int start = record.find("foul");       // search from left (rfind seaches 
                                         // from right)
  cout << "substring foul starts at position " << start << endl;

  // sub-strings
  string str = record.substr(start, 4);  // extract 4-character sub-string
  cout << str << endl;

  // replace 4-character sub-string at "start" with specified string
  record.replace(start, 4, "wasted");

  // find "ity" and replace with "ed"
  start = record.rfind("ity");           // find "ity"
  record.replace(start, 3, "ed");        // replace "ity" with "ed"
  record = record + " space";            // append " space"

  cout << record << endl;

  // Some programs (e.g., Root) still use C character arrays. Therefore,
  // the attribute c_str() has been added to string to allow for the
  // return of an array of characters (terminated with a null character)

  cout << record.c_str() << endl;

  //---------------------------------------------------------
  // vectors
  //---------------------------------------------------------

  cout << GREEN << "\nvectors\n" << RESET_COLOR << endl;
  
  vector<int> vint(5,0); // create a vector of 5 integers, initialized to zero

  // Set each value of vector<int>
  vint[0] = 5;
  vint[1] = 4;
  vint[2] = 3;
  vint[3] = 2;
  vint[4] = 1;

  vector<FourVector> v4vec;  // create an empty vector of FourVector structs

  // Append a couple of FourVector struct to the end of v4vec
  v4vec.push_back(FourVector());
  v4vec.push_back(FourVector());

  cout << "number of entries in v4vec = " << v4vec.size() << endl;

  // Set attributes of first entry
  v4vec.front().px = 2.0;  // same as v4vec[0].px or v4vec.at(0).px
  v4vec.front().py = 4.0;
  v4vec.front().pz = 6.0;
  v4vec.front().energy =99.0;

  // Set attributes of last entry
  v4vec.back().px = 4.0;
  v4vec.back().py = 2.0;
  v4vec.back().pz = 3.0;
  v4vec.back().energy =88.0;

  // Clear vector vint;
  vint.clear();

  cout << "number of entries in vint = " << vint.size() << endl;

  //---------------------------------------------------------
  // pointers
  //---------------------------------------------------------

  cout << MAGENTA << "\npointers\n" << RESET_COLOR << endl;

  // A pointer is a variable that contains an address.
  // One can create a pointer to any variable, function or object.
  // The following is a pointer to an int

  int* IamApointer = 0;

  // The variable "a" is declared above as an int. Its value is currently
  // equal to 42. We can use the pointer IamApointer to manipulate the
  // variable "a". First we initialize the pointer with the address of
  // variable "a" using the reference operator &

  IamApointer = &a;
  cout << "IamAPointer = " << IamApointer << endl;
  IamApointer++;
  cout << "IamAPointer = " << IamApointer << endl;
  //exit(0);

  //IamApointer = &vint;

  cout << "address of int a = " << IamApointer << endl;
  cout << "a = " << a << " before assignment via pointer " 
       << MAGENTA << "IamApointer " << RESET_COLOR << endl;

  // The variable pointed to by the pointer can be accessed using the
  // dereference operator *

  *IamApointer = 24;
  cout << "a = " << a << " after assignment via pointer " 
       << MAGENTA << "IamApointer " << RESET_COLOR << endl;

 cout << "aa = " << aa << " after assignment via pointer " 
       << MAGENTA << "IamApointer " << RESET_COLOR << endl;

  return 0;
}





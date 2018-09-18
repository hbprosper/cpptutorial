//----------------------------------------------------------------------------
// C++ Tutorial
// 04_operators
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>   // Needed for std::hex
#include <cmath>
#include "colors.h"

using namespace std;
//----------------------------------------------------------------------------
int main()
{
  // arithmetic

  cout << RED << "\narithmetic\n" << RESET_COLOR << endl;

  int I = 42;
  int J = 5;
  float F = M_PI; // from cmath
  float A = 2.0;

  cout << "I = " << I << endl;
  cout << "J = " << J << endl;
  cout << "F = " << F << endl;

  float B;
  B = F + A;
  B = F - A;
  B = F * A;
  B = F / A;

  int K;
  K = I % J;
  cout << "I % J = " << K << endl;

  B -= 2.1;
  B += 3.5;
  B /= 1.6;
  
  // Contrast

  cout << endl << "J = " << J << endl;

  K = ++J;
  cout << "K = ++J, K = " << K << ", J = " << J << endl;

  // with
  K = J++;
  cout << "K = J++, K = " << K << ", J = " << J << endl;

  K = --J;
  cout << "K = --J, K = " << K << ", J = " << J << endl;

  // with
  K = J--;
  cout << "K = J--, K = " << K << ", J = " << J << endl;

  // relational

  cout << BLUE << "\nrelational\n" << RESET_COLOR << endl;

  cout << "K = " << K << ", J = " << J << endl;
  cout << "K == J, truth value = " << (K == J) << endl;
  cout << "K != J, truth value = " << (K != J) << endl;
  cout << "K > J,  truth value = " << (K >  J) << endl;
  cout << "K < J,  truth value = " << (K <  J) << endl;
  cout << "K >= J, truth value = " << (K >= J) << endl;
  cout << "K <= J, truth value = " << (K <= J) << endl;

  cout << GREEN << "\nlogical\n" << RESET_COLOR << endl;

  cout << "!(K != J), truth value = " << !(K != J) << endl;

  cout << "(K != J) && (K < J), truth value = " 
       << ((K != J) && (K < J)) << endl;

  cout << "(K != J) || (K < J), truth value = " 
       << ((K != J) || (K < J)) << endl;

  cout << YELLOW << "\nbitwise\n" << RESET_COLOR << endl;

  unsigned short X = 0xF0;
  unsigned short Y = 0x0F;

  cout << "X = " << std::setw(2) << std::hex << X << endl; 
  cout << "Y = " << std::setw(2) << std::hex << Y << endl;


  // Hex output is still in force

  cout << "X & Y  = " << std::setw(2) << (X & Y) << endl;
  cout << "X | Y  = " << std::setw(2) << (X | Y) << endl;
  cout << "X ^ Y  = " << std::setw(2) << (X ^ Y) << endl;
  cout << "Y << 2 = " << std::setw(2) << (Y << 2) << endl;
  cout << "X >> 1 = " << std::setw(2) << (X >> 1) << endl;

  cout << MAGENTA << "\nconditional\n" << RESET_COLOR << endl;

  int result = (X != Y) ?  42 : 24;

  cout << std::dec; // Reset to decimal
  cout << "(X != Y) ? 42 : 24 = " << result << endl;

  return 0;
}





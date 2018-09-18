//----------------------------------------------------------------------------
// C++ Tutorial
// 11_class2: copy and assignment 
// Summer 2008, Harrison B. Prosper
//----------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;
//----------------------------------------------------------------------------
void say(const char* s){cout << s << endl;}


class A
{
public:
  A() : _a(42) { say("\tconstruct A"); }

  // Copy rhs object to this object (*this <- rhs)

  A(const A& other) : _a(other._a) { say("\tcopy"); }

  ~A(){ say("\tdelete A"); }
 
  // Assign right-hand-side object to this object (*this = rhs) 
  A& operator=(const A& rhs)
  {
    say("\tassign A");
    if ( this == &rhs ) return *this;
    _a = rhs._a;
    return *this;
  }

  void set(int a){_a = a;}

  int  get() const {return _a;}

private:
  int _a;
};

A dummy;

A&   ref1() {return dummy;}

A    ref2() {A a; a.set(123); return a;}
//----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  say("Copy and Assignment\n");
  say("A a");
  A a;
  say("----------------");

  // say("A* pa");
  // A* pa = new A();
  // say("----------------");
  // delete pa;
  
  say("A b=a");
  A b=a;
  say("----------------");


  say("A c=ref1()");
  A c=ref1();
  say("----------------");

  say("A& e=ref1();");
  A& e=ref1();
  say("----------------");

  say("A d=ref2()");
  A d=ref2();
  cout << d.get() << endl;
  say("----------------");

  say("e = b");
  e = b;
  say("----------------");
}





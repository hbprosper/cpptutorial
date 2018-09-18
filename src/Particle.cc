#include <stdio.h>
#include "Particle.h"
using namespace std;

Particle::Particle()
  : _e(0),
    _px(0),
    _py(0),
    _pz(0),
    _pt(0)
{}


Particle::Particle(float e, float px, float py, float pz)
  : _e(e),
    _px(px),
    _py(py),
    _pz(pz),
    _pt(sqrt(px*px+py*py))
{
  cout << "constructor" << endl;
}

Particle::Particle(const Particle& other)
  : _e(other._e),
    _px(other._px),
    _py(other._py),
    _pz(other._pz),
    _pt(other._pt)
{
  cout << "copy constructor" << endl;
}

Particle&
Particle::operator=(const Particle& rhs)
{
  cout << "assignment" << endl;
  if ( this == &rhs ) return *this;

  // The code below is fine, so long as it
  // cannot trigger an exception (a failure)
  _e  = rhs._e;
  _px = rhs._px;
  _py = rhs._py;
  _pz = rhs._pz;
  _pt = rhs._pt;
  return *this;
}

Particle::~Particle()
{
  cout << "destructor" << endl;
}

void Particle::setEPxPyPZ(float e, float px, float py, float pz)
{
 _e  = e;
 _px = px; 
 _py = py;
 _pz = pz;
 _pt = sqrt(px*px+py*py);
}

std::ostream& operator<<(std::ostream& os, Particle& p)
{
  char record[80];
  sprintf(record, "%10.3f  %10.3e%10.3e%10.3e%10.3e", 
	  p.pt(), p.e(),p.px(),p.py(),p.pz());
  os << record;
  return os;	  
}

#ifndef PARTICLE_H
#define PARTICLE_H
#include <cmath>
#include <iostream>

class Particle
{
 public:
  // Default constructor
  Particle();

  // Constructor
  Particle(float e, float px, float py, float pz);

  // Copy constructor    (*this <- rhs)
  Particle(const Particle& other);

  // Assignment operator (*this = rhs)
  Particle& operator=(const Particle& rhs);    

  // Destructor
  ~Particle();

  // Because these functions have been declared "const" the compiler
  // will not allow them to alter the attributes of the object.
  // Consequently, a const function can only call const functions of the
  // object.
  float    e()  const {return _e;}
  float    px() const {return _px;}
  float    py() const {return _py;}
  float    pz() const {return _pz;}
  float    pt() const {return _pt;}

  void setEPxPyPZ(float e, float px, float py, float pz);

  bool     operator<(const Particle& p) const;
  Particle operator+(const Particle& p);
  Particle operator-(const Particle& p);
  Particle operator*(float a);
  float    operator*(const Particle& p);

 private:
  float _e;
  float _px;
  float _py;
  float _pz;
  float _pt;
};

inline 
bool 
Particle::operator<(const Particle& p) const
{
  return this->pt() > p.pt();
}

inline 
Particle 
Particle::operator + (const Particle& p)
{
  return Particle(this->e() + p.e(),
		  this->px()+ p.px(),
		  this->py()+ p.py(),
		  this->pz()+ p.pz());
}


inline 
Particle 
Particle::operator - (const Particle& p)
{
  return Particle(this->e() - p.e(),
		  this->px()- p.px(),
		  this->py()- p.py(),
		  this->pz()- p.pz());
}



inline 
Particle 
Particle::operator * (float a)
{
  return Particle(a*e(),
		  a*px(),
		  a*py(),
		  a*pz());
}


inline 
float
Particle::operator * (const Particle& p)
{
  return this->e()*p.e() 
    - (this->px()*p.px()+
       this->py()*p.py()+
       this->pz()*p.pz());
}

std::ostream& operator<<(std::ostream& os, Particle& p);

#endif

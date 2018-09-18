//----------------------------------------------------------------------------
// Example of polymorphic behavior
// 13_class: STL vector
// HBP April 2013
//----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "colors.h"
//----------------------------------------------------------------------------
using namespace std;

class Animal
{
public: 
  Animal() {cout << endl << "create animal" << endl;}
  
  // virtual destructor needed to force call to destructor of daughter classes
  
  virtual
  ~Animal() {cout << "bye bye Animal" << endl << endl;}
  
  virtual 
  void speak()=0; // This makes Animal an abstract class
  
  virtual 
  void print() {cout << "I'm an animal" << endl;}
};

class Duck : public Animal
{
public:
  Duck () : Animal() {cout << "create duck" << endl;}
  
  // virtual destructor needed to force call to this destructor
  ~Duck() {cout << "bye bye Duck" << endl;}
  void speak() {cout << "Quack" << RESET_COLOR << endl;}
};

class Cat : public Animal
{
public:
  Cat () : Animal() {cout << "create cat" << endl;}
  ~Cat() {cout << "bye bye Cat" << endl;}
  void speak() {cout << "Meow" << RESET_COLOR << endl;}
};

class Dog : public Animal
{
public:
  Dog () : Animal() {cout << "create dog" << endl;}
  ~Dog() {cout << "bye bye Dog" << endl;}
  void speak() {cout << "Woof" << RESET_COLOR << endl;}
  void print() {cout << "I'm a dog" << endl;}
};

class Shepherd : public Dog
{
public:
  Shepherd () : Dog() {cout << "create shepherd" << endl;}
  ~Shepherd() {cout << "bye bye Shepherd" << endl;}
  void speak() {cout << "Woof Woof" << RESET_COLOR << endl;}
  void print() {cout << "I'm a Shepherd" << endl;}
};

class PetShop
{
public:
  PetShop()
    : pet(std::vector<Animal*>()) {}

  // We assume that the pet shop owns the animals and so is responsible
  // for deleting them
  ~PetShop() { for(unsigned int i=0; i < pet.size(); i++) delete pet[i]; }

  void add(Animal* animal) 
  {
    pet.push_back(animal);
  }

  void speak()
  {
    cout << CYAN << "Pet Shop Chatter" << RESET_COLOR << endl;

    vector<string> color;
    color.push_back(RED);
    color.push_back(YELLOW);
    color.push_back(GREEN);
    color.push_back(BLUE);
    color.push_back(MAGENTA);
    color.push_back(CYAN);

    int j=0;
    for(unsigned int i=0; i < pet.size(); i++)
      {
	cout << color[j] << i << endl;
	pet[i]->print();
	pet[i]->speak();

	// wraparound
	j++;
	if ( j >= static_cast<int>(color.size()) ) j = 0;
      }
    cout << endl;
  }

private:
  std::vector<Animal*> pet;
};

//-------------------
int main()
{
  PetShop shop;

  Dog* dog = new Dog();

  shop.add(dog);
  shop.add(new Cat());
  shop.add(new Duck());
  shop.add(new Shepherd());

  cout << endl;
  shop.speak();

  cout << endl;

  //if ( !dog ) delete dog;

  return 0;
}


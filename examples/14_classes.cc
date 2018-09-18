// Example of polymorphic behavior that works with ACLIC
// HBP April 2013
#include <iostream>
#include <vector>
#include "colors.h"

using namespace std;

class Animal
{
public:
  Animal() {cout << endl << "create animal" << endl;}
  
  // virtual destructor needed to force call to destructor of daughter classes
  
  virtual
  ~Animal() {cout << "ciao Animal" << endl << endl;}
  
  virtual 
  void speak() {} 
  
  virtual 
  void print() {cout << "I'm an animal" << endl;}
};

class Duck : public Animal
{
public:
  string name;
  Duck(string name_) : Animal(), name(name_) {cout << "create duck" << endl;}
  
  // virtual destructor needed to force call to this destructor
  ~Duck() {cout << "bye bye Duck" << endl;}
  void speak() {cout << "Quack" << RESET_COLOR << endl;}
  void print() {cout << "I'm a duck called " << name << endl;}
};

class Cat : public Animal
{
public:
  string name;
  Cat(string name_) : Animal(), name(name_) {cout << "create cat" << endl;}
  ~Cat() {cout << "bye bye Cat" << endl;}
  void speak() {cout << "Meow" << RESET_COLOR << endl;}
  void print() {cout << "I'm a cat called " << name << endl;}
};

class Dog : public Animal
{
public:
  string name;
  Dog(string name_) : Animal(), name(name_) {cout << "create dog" << endl;}
  ~Dog() {cout << "bye bye Dog" << endl;}
  void speak() {cout << "Woof" << RESET_COLOR << endl;}
  void print() {cout << "I'm a dog called " << name << endl;}
};

class GoldenRetriever : public Dog
{
public:
  GoldenRetriever (string name) : Dog(name)
  {cout << "create German Shepherd" << endl;}
  ~GoldenRetriever() {cout << "bye bye Golden Retriever" << endl;}
  void speak() {cout << "Woof Woof" << RESET_COLOR << endl;}
  void print() {cout << "I'm a Golden Retriever called " << name << endl;}
};

class PetShelter
{
public:
  PetShelter()
    : pet(std::vector<Animal*>()) {}

  // The pet shop does not own the animals, so can't euthanize them!
    ~PetShelter() {}

  void add(Animal& animal) 
  {
    pet.push_back(&animal);
  }

  void speak()
  {
    cout << CYAN << "Pet Shelter Chatter" << RESET_COLOR << endl;

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
	cout << color[j] << endl;
	pet[i]->print();
	pet[i]->speak();
	cout << RESET_COLOR << endl;
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
  PetShelter shelter;

  Dog dog("Sadie");  shelter.add(dog);
  Cat cat("Sunshine");  shelter.add(cat);
  Duck duck("Donald");     shelter.add(duck);
  GoldenRetriever dog2("Riley"); shelter.add(dog2);

  cout << endl;
  shelter.speak();

  cout << endl;

  return 0;
}


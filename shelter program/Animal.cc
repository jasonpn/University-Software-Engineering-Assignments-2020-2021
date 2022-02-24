#include <iostream>
using namespace std;
#include <string>

#include "Animal.h"

int Animal::nextId = 1001;

Animal::Animal(SpeciesType s,  string b,  string c, string n,string g,int y, int m)
  :Identifiable("A", nextId){
  name = n;
  breed = b;
  gender = g;
  colour = c;
  species = s;
  age = (y * 12) + m;
  nextId++;
}

string Animal::getName(){
  return name;
}

string Animal::getColour(){
  return colour;
}

string Animal::getBreed(){
  return breed;
}

string Animal::getGender(){
  return gender;
}

int Animal::getAge(){
  return age;
}

string Animal::getSpecies(){
  string sp;
  if (species == C_DOG){
    sp = "Dog";
  }
  else if (species == C_BIRD){
    sp = "Bird";
  }
  else if (species == C_CAT){
    sp = "Cat";
  }
  else if (species == C_RABBIT){
    sp = "Rabbit";
  }
  else if (species == C_OTHER){
    sp = "Other";
  }
  return sp;
}

void Animal::print(){
  cout << this->getId() << " "<< this->getSpecies() << "; " << name << "; "
       << breed << "; " << age << "; "
       << gender << "; " << colour << endl;
}

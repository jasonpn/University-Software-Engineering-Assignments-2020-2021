#ifndef ANIMAL_H
#define ANIMAL_H

#include "Identifiable.h"
#include "defs.h"

/*
Animal class creates animals with name, breed, gender, colour, species type, and age. 
*/

class Animal: public Identifiable{
 public:
  Animal(SpeciesType,  string = "breed",  string = "colour", string = "name", string = "gender", int = 2000, int = 0);
  string getName();
  string getBreed();
  string getGender();
  string getColour();
  string getSpecies();
  int getAge();
  void print();
 private:
  static int nextId;
  string name, breed, gender, colour;
  SpeciesType species;
  int age;
};

#endif

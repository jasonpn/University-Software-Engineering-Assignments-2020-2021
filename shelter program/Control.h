#ifndef CONTROL_H
#define CONTROL_H


#include "Shelter.h"

#include "View.h"

/*
Control class launches the program, displays the menu getting the user input, initializes animals, clients and shelter.
*/

class Control
{
  public:
  Control();
  ~Control();
  void initShelter();
  void initClients();
  void initAnimals();
  void launch();
  
  private:
  View view;
  Shelter* shelter;

};

#endif

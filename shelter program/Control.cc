#include <iostream>
using namespace std;
#include <string>
#include <time.h>
#include <cstdlib>

#include "Control.h"
#include "MatchListByScore.h"
#include "MatchListByClient.h"
#include "MatchList.h"
#include "Animal.h"
#include "Client.h"

Control::Control(){
  shelter = new Shelter("Shelter");

}

Control::~Control(){
  delete shelter;
}


void Control::launch(){
  int choice;
  initShelter();
  
  while (1){
    view.showMenu(choice);

    if(choice == 0){
      break;
    }

    if(choice == 1){
      MatchListByScore* mls = new MatchListByScore();
      MatchListByClient* mlc = new MatchListByClient();
      shelter->computeMatches(*mls,*mlc);
      cout<<"MATCH BY SCORE:"<<endl;
      mls->print();
      cout<<"MATCH BY CLIENT:"<<endl;
      mlc->print();
      mls->cleanup();
      mlc->cleanup();
    }

    if(choice == 2){
      shelter->printAnimals();
    }

    if(choice == 3){
      shelter->printClients();
    }

  }
}

void Control::initShelter()
{
  initAnimals();
  initClients();
}

void Control::initClients()
{
  Client*   c;

  c  = new Client("Lee");
  c->addCriteria(new Criteria("Species", "Dog"));
  c->addCriteria(new Criteria("Gender", "F", 8));
  c->addCriteria(new Criteria("Age", "4", 2));
  shelter->add(c);

  c = new Client("Kara");
  c->addCriteria(new Criteria("Species", "Other"));
  c->addCriteria(new Criteria("Breed", "Guinea Pig", 9));
  c->addCriteria(new Criteria("Age", "2", 1));
  shelter->add(c);

  c = new Client("Laura");
  c->addCriteria(new Criteria("Species", "Cat"));
  c->addCriteria(new Criteria("Breed", "Domestic Short Hair", 2));
  c->addCriteria(new Criteria("Gender", "M", 3));
  c->addCriteria(new Criteria("Age", "1", 5));
  shelter->add(c);
}

void Control::initAnimals()
{
  shelter->add(new Animal(C_DOG, "Poodle", "White", "Betsy", "F", 5));
  shelter->add(new Animal(C_DOG, "Labradoodle", "Tan", "Killer", "F", 3));
  shelter->add(new Animal(C_DOG, "German Shepard", "Black/Tan", "Fluffy", "M", 2));
  shelter->add(new Animal(C_DOG, "Pug", "Tan", "Leon", "M", 4));
  shelter->add(new Animal(C_DOG, "Pug", "Tan", "Lily", "F", 1));
  shelter->add(new Animal(C_CAT, "Domestic Short Hair", "Grey", "Lady", "F", 11));
  shelter->add(new Animal(C_CAT, "Domestic Short Hair", "Grey", "Shadow", "M", 5));
  shelter->add(new Animal(C_CAT, "Domestic Long Hair", "Grey", "Luka", "M", 7));
  shelter->add(new Animal(C_CAT, "Domestic Short Hair", "Grey tabby", "Fiona", "F", 8));
  shelter->add(new Animal(C_CAT, "Domestic Short Hair", "Brown tabby", "Ruby", "F", 5));
  shelter->add(new Animal(C_RABBIT, "Lionhead", "Black", "Ziggy", "F", 3));
  shelter->add(new Animal(C_OTHER, "Guinea Pig", "Black", "Quark", "M", 9));
  shelter->add(new Animal(C_OTHER, "Guinea Pig", "Brown", "Quasar", "M", 1, 4));
  shelter->add(new Animal(C_OTHER, "Mouse", "Tan", "Pecorino", "M", 0, 3));
  shelter->add(new Animal(C_OTHER, "Mouse", "Tan", "Gruyere", "M", 0, 3));
  shelter->add(new Animal(C_OTHER, "Mouse", "Tan", "Limburger", "M", 0, 3));
}


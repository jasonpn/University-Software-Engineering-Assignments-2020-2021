#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Agenda.h"

Agenda::Agenda(string n){
  name = n;
  numCal = 0;
}

Agenda::~Agenda(){
  for (int i = 0; i < numCal; i++){
    delete calendars[i];
  }
}

bool Agenda::add(Calendar* c){
  if(numCal < MAX_CAL){
    calendars[numCal] = c;
    numCal++;
    return true;
  }
  else{
    return false;
  }
}

bool Agenda::find(string n, Calendar** c){
  for (int i = 0; i < numCal; i++){
    if (calendars[i]->getName() == n){
      *c = calendars[i];
      return true;
    }
  }
  cout<<"invalid calendar "<< n <<endl;
  return false;
}

bool Agenda::add(Date* d, string n){

  Calendar newc = Calendar("name");
  Calendar *c = &newc;

  this->find(n,&c);

  if(c->getName() == n){
    c->add(d);
    return true;
  }
  else{
    delete d;
    return false;
  }
}

void Agenda::print(){
  Calendar newc = Calendar(this->name);
  Calendar *c = &newc;

  for (int i = 0; i<numCal; i++){
    c->merge(calendars[i]);
  }

  cout<<"AGENDA " << name << endl;
  c->print();
}

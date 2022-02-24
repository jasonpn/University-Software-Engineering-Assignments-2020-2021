#include <iostream>
using namespace std;

#include "Reservation.h"

Reservation::Reservation(Guest* gu, Room* ro, Date* d, int s){
  g = gu;
  r = ro;
  arrive = d;
  stay = s;
  charge = (r->getCost() * stay);
}

Reservation::~Reservation(){
}

Date* Reservation::getArrive(){
  return arrive;
}
int Reservation::getDays(){
  return stay;
}

Guest* Reservation::getGuest(){
  return g;
}

Room* Reservation::getRoom(){
  return r;
}

float Reservation::getCharge(){
  return charge;
}

bool Reservation::lessThan(Reservation* r){
  if (this->arrive->lessThan(*r->arrive)){
    return true;
  }
  return false;
}

void Reservation::print(){
  cout<< "-- Guest: " << g->getName() << "; Room: "
      << r->getRoomNum() << "; Arrival: ";
  arrive->print();
  cout  << "; Stay: " << stay << "; Charge:  $" << charge <<endl;
}

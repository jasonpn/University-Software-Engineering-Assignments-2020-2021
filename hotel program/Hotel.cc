#include <iostream>
using namespace std;
#include <string>

#include "Hotel.h"

Hotel::Hotel(string n, ResManager* r){
  name = n;
  manager = r;
  numGuests = 0;
  rarr = new RoomArray();
}
Hotel::~Hotel(){
  for(int i = 0; i<numGuests; i++){
    delete guests[i];
  }
  delete rarr;
}

RoomArray& Hotel::getRooms(){
  return *rarr;
}

void Hotel::addGuest(Guest* g){
  guests[numGuests] = g;
  numGuests++;
}

void Hotel::addRoom(Room* r){
  rarr->add(r);
}

void Hotel::printGuests(){
  for(int i = 0; i<numGuests;i++){
    guests[i]->print();
  }
}

void Hotel::printRooms(){
  rarr->print();
}

bool Hotel::findGuest(string n, Guest** g){
  for(int i = 0; i<numGuests; i++){
    if(guests[i]->getName() == n){
      *g = guests[i];
      return true;
    }
  }
  return false;
}

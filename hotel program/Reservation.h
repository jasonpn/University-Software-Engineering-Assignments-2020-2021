#ifndef RESERVATION_H
#define RESERVATION_H

#include "Guest.h"
#include "Room.h"
#include "Date.h"

/*
Class for reservations, including guest, room, date, charge for stay and length of stay
*/

class Reservation{
 public:
  Reservation(Guest* = NULL, Room* = NULL, Date* = NULL, int = 0);
  ~Reservation();
  Date* getArrive();
  int getDays();
  Guest* getGuest();
  Room* getRoom();
  float getCharge();
  bool lessThan(Reservation*);
  void print();
 private:
  Guest* g;
  Date* arrive;
  int stay;
  Room* r;
  float charge;

};

#endif

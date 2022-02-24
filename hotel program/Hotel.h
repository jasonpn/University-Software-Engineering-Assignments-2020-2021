#ifndef HOTEL_H
#define HOTEL_H

#define MAX_ARR 256

#include "Guest.h"
#include "RoomArray.h"
#include "ResManager.h"

/*
Hotel class to create a hotel, adding guests and rooms
*/

class Hotel{
 public:
  Hotel(string = "name", ResManager* = NULL);
  ~Hotel();
  RoomArray& getRooms();
  void addGuest(Guest*);
  void addRoom(Room*);
  void printGuests();
  void printRooms();
  bool findGuest(string n, Guest** g);
 private:
  string name;
  Guest* guests[MAX_ARR];
  int numGuests;
  RoomArray* rarr;
  ResManager* manager;
  
};

#endif

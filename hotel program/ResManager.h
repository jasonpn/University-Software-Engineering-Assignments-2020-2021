#ifndef RESMANAGER_H
#define RESMANAGER_H

#include "defs.h"

#include "Reservation.h"
#include "Recorder.h"

/*
Class for manager of hotel to keep track of hotel records and add reservations to hotel

Has forward declaration to Hotel class
addReservation adds reservation to array of reservations
subscribe adds recorders to vector of recorders

*/
class Hotel; 

class ResManager{
 public:
  ResManager(Hotel*);
  ~ResManager();
  void setHotel(Hotel*);
  void addReservation(string n, int y, int m, int d, int stay, ReqRoomType req);
  void subscribe(Recorder*);
  void print();
  void printRecords();
  
 private:
  Hotel* hotel;
  Reservation* reserves[MAX_ARR];
  int numReserves;
  vector<Recorder*> recorders;
  void notify(Reservation*);
  bool findDate(Date*);
  bool add(Reservation*);

  
};

#endif

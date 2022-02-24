#ifndef RECORDER_H
#define RECORDER_H
#include <vector>
#include <string>

#include "Reservation.h"

/*
Recorder abstract class, has derived classes that update the recorder with hotel reservations
*/

class Recorder{
 public:
  Recorder(string = "name");
  void printRecords();
  virtual void update(Reservation*) = 0;
  
  
 protected:
  string name;
  vector<string> records;
 

};

//Guest recorder class derives from recorder abstract class and implements update to check premium offers for non premium guests

class GuestRecorder: public Recorder{
 public:
  GuestRecorder(string = "name");
  virtual void update(Reservation*);
};

//Stay recorder class derives from recorder abstract class and implements update to check if guests length of stay is longer than 3
class StayRecorder: public Recorder{
 public:
  StayRecorder(string = "name");
  virtual void update(Reservation*);
};

//Upgrade recorder class derives from recorder abstract class and implements update to check for guests spending more than 1500$
class UpgradeRecorder: public Recorder{
 public:
  UpgradeRecorder(string = "name");
  virtual void update(Reservation*);
};

#endif

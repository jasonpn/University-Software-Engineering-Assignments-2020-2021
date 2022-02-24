#ifndef TELCO_H
#define TELCO_H

#define MAX_SUB 256

#include "Subscriber.h"
#include "Call.h"
#include "Array.h"
/*
Telco class keeps track of subscribers and calls being made.
calls is an Array object
subs is a primitive array of Subscriber pointers
addSub adds subscribers to calls Array object
addCall adds calls to a the calls object and subscriber's in and out calls
computeFreqCaller computes the most frequent caller
computeFreqCalled computes the number most frequently called


*/
class Telco{

 public:
  Telco(string = "name");
  ~Telco();
  void addSub(Subscriber* s);
  void addCall(string, string, int, int, int, int, int, int);
  void computeFreqCaller(string);
  void computeFreqCalled(string);
  void print();
  

 private:
  Array* calls;
  Subscriber** subs;
  string name;
  int numSubs;
};

#endif

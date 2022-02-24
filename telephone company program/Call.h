#ifndef CALL_H
#define CALL_H

#include "Date.h"
#include "Time.h"

/*
Call class creates a call with numbers, duration, date and time.
*/

class Call
{
 public:
  Call(string = "0000000000", string = "1111111111", int=0, int=0, int=0, int=2000, int=0, int=0);
  ~Call();
  bool greaterThan(Call*);
  string getSrc();
  string getDest();
  void print();

 private:
  string src;
  string dest;
  int duration;
  Date* date;
  Time* start;
};

#endif

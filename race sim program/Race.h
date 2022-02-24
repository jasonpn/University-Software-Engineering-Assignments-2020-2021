#ifndef RACE_H
#define RACE_H

#include "View.h"
#include "Array.h"

//Race control class to control the race
class Race{
 public:
  Race();
  bool isOver(string& outcome);
  void run();
 private:
  View view;
  Array runners;
};

#endif

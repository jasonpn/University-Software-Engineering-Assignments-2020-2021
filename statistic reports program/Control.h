#ifndef CONTROL_H
#define CONTROL_H

#include "ReportGenerator.h"

#include "View.h"
#include <vector>

//control class to launch program
class Control{
 public:
  Control();
  void launch();
 private:
  View view;
  vector<ReportGenerator*> reports;
  ReportGenerator* one;
  ReportGenerator* two;
  ReportGenerator* three;

};

#endif

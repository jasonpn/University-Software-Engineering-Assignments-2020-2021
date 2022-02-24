#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"

/*
Control class initializes data and launches the program
*/
class Control
{
  public:
   void launch();
  private:
   void initData(Telco* tel);
   void initSubscribers(Telco* tel);
   void initCalls(Telco* tel);
   View view;
};

#endif

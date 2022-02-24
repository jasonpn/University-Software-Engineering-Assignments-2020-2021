#ifndef VIEW_H
#define VIEW_H

#define MAX_ROWS 5
#define MAX_COLS 25

#include "Position.h"

//View class creating the display
class View{
 public:
  View();
  ~View();
  void print();
  void update(Position& oldPos, Position& newPos, char avatar);
  bool validPos(Position& pos);
  void printStr(string str);
 private:
  char** display;
  
};

#endif

#ifndef RUNNER_H
#define RUNNER_H

#include "Position.h"
#include "MoveBehaviour.h"

//Runner class storing runner information

class Runner{
  public:
  Runner(string="Name",char='A',int=0,int=0);
  ~Runner();
  string getName();
  char getAvatar();
  Position getPos();
  string getLog();
  void setPos(int,int);
  bool lessThan(Runner* r);
  void update(Position& newPos);
  private:
  string name;
  char avatar;
  int bib;
  int lane;
  Position pos;
  MoveBehaviour* mb;
  string log;
};



#endif

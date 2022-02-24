#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

#include <iostream>
using namespace std;

#include "Position.h"

//Move behaviour abstract class to move the runners in the race
class MoveBehaviour{
 public:
  virtual void move (Position& oldPos, Position& newPos, string& log);
  virtual ~MoveBehaviour();
};

//WalkBehaviour concrete behaviour class deriving from the MoveBehaviour class
class WalkBehaviour : public MoveBehaviour{
 public:
  virtual void move (Position& oldPos, Position& newPos, string& log);
  virtual ~WalkBehaviour();
};
//SleepBehaviour concrete behaviour class deriving from the MoveBehaviour class
class SleepBehaviour : public MoveBehaviour{
 public:
  virtual void move (Position& oldPos, Position& newPos, string& log);
  virtual ~SleepBehaviour();
};
//JumpBehaviour concrete behaviour class deriving from the MoveBehaviour class
class JumpBehaviour : public MoveBehaviour{
 public:
  virtual void move (Position& oldPos, Position& newPos, string& log);
  virtual ~JumpBehaviour();
};
//SlideBehaviour concrete behaviour class deriving from the MoveBehaviour class
class SlideBehaviour : public MoveBehaviour{
 public:
  virtual void move (Position& oldPos, Position& newPos, string& log);
  virtual ~SlideBehaviour();
};
//TeleportBehaviour concrete behaviour class deriving from the MoveBehaviour class
class TeleportBehaviour : public MoveBehaviour{
 public:
  virtual void move (Position& oldPos, Position& newPos, string& log);
  virtual ~TeleportBehaviour();
};


#endif

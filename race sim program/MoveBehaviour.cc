#include <iostream>
using namespace std;
#include <sstream>

#include "MoveBehaviour.h"
#include "random.cc"

//MoveBehaviour abstract class and concrete classes determining movements of runners
void MoveBehaviour::move(Position& oldPos, Position& newPos, string& log){
  
}

//MoveBehaviour destructor
MoveBehaviour::~MoveBehaviour(){
}

//walkbehaviour move function, move runner 1 step on the same row
void WalkBehaviour::move(Position& oldPos, Position& newPos, string& log){
  newPos.setRow(oldPos.getRow());
  newPos.setCol(oldPos.getCol() + 1);
  log = " walked one step";
}
//walkbehaviour destructor
WalkBehaviour::~WalkBehaviour(){
}

//sleepbehaviour move function, keeps the runner in place
void SleepBehaviour::move(Position& oldPos, Position& newPos, string& log){
  newPos = oldPos;
  log = " slept";
}

//sleepbehaviour destructor
SleepBehaviour::~SleepBehaviour(){
}

//jumpbehaviour move function, move the runner randomly between 1 and 8 steps in the same row
void JumpBehaviour::move(Position& oldPos, Position& newPos, string& log){
  stringstream ss; 
  int ran = random(8)+1;
  newPos.setRow(oldPos.getRow());
  newPos.setCol(oldPos.getCol()+ran);
  ss << " jump forward by " << ran << " steps";
  log = ss.str();}

//jumpbehaviour destructor
JumpBehaviour::~JumpBehaviour(){
}

//slide behaviour move function, slide the runner randomly between 1 and 5 steps in the same row to the left
void SlideBehaviour::move(Position& oldPos, Position& newPos, string& log){
  stringstream ss;
  int ran = random(5)+1;
  newPos.setRow(oldPos.getRow());
  newPos.setCol(oldPos.getCol()-ran);
  ss << " slid back by " << ran << " steps";
  log = ss.str();
}

//slidebehaviour destructor
SlideBehaviour::~SlideBehaviour(){
}

//teleport behaviour move function, teleport runner to random place in race
void TeleportBehaviour::move(Position& oldPos, Position& newPos, string& log){
  stringstream ss;
  int ranrow = random(4)+1;
  int rancol = random(24)+1;
  newPos.setRow(ranrow);
  newPos.setCol(rancol);
  ss << " teleported from ("  << oldPos.getRow() << "," << oldPos.getCol()
     << ")" << " to (" << ranrow << "," << rancol << ")";
  log = ss.str();
}

//teleportbehaviour destructor
TeleportBehaviour::~TeleportBehaviour(){
}

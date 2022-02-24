#include <iostream>
using namespace std;
#include <string>

#include "Runner.h"
//#include "random.cc"

//forward declaration of random function
int random(int);

//Runner class storing runner information and runner movement

//runner constructor initialize values, position and movebehaviour
Runner::Runner(string n, char a, int b, int l){
  name = n;
  avatar = a;
  bib = b;
  lane = l;
  pos.setRow(l);
  pos.setCol(0);
  mb = new WalkBehaviour;  
}

//Runner destructor
Runner::~Runner(){
  //delete mb;
}

//get the name of runner
string Runner::getName(){
  return name;
}

//get the avatar of runner
char Runner::getAvatar(){
  return avatar;
}

//get the position of runner
Position Runner::getPos(){
  return pos;
}

//get the log of runner
string Runner::getLog(){
  return log;
}

//set runner position
void Runner::setPos(int r, int c){
  pos.setRow(r);
  pos.setCol(c);
}

//compare runners by bib number
bool Runner::lessThan(Runner* r){
  if(this->bib < r->bib){
    return true;
  }
  else{
    return false;
  }
}

//update runner's movement and position
void Runner::update(Position& newPos){
  //randomly choose a movement behaviour
  //the random percentages didn't work, so this will just choose one of the behaviours at random without percentages
  int ran = random(5)+1;
  Position oldp = pos;
  Position newp = pos;
  string l;

  //set each case movebehaviour and set positions and logs
  if(ran == 1){
    mb = new WalkBehaviour;
    mb->move(oldp,newp,l);
    newPos=newp;
    setPos(newp.getRow(), newp.getCol());
    log = name + l;
    delete mb;
  }
  else if(ran == 2){
    mb = new SleepBehaviour;
    mb->move(oldp,newp,l);
    newPos=newp;
    setPos(newp.getRow(), newp.getCol());
    log = name + l;
    delete mb;
  }
  else if(ran == 3){
    mb = new JumpBehaviour;
    mb->move(oldp,newp,l);
    newPos=newp;
    setPos(newp.getRow(), newp.getCol());
    log = name + l;
    delete mb;
  }
  else if(ran == 4){
    mb = new SlideBehaviour;
    mb->move(oldp,newp ,l);
    newPos=newp;
    setPos(newp.getRow(), newp.getCol());
    log = name + l;
    delete mb;
  }
  else if(ran == 5){
    mb = new TeleportBehaviour;
    mb->move(oldp,newp,l);
    newPos=newp;
    setPos(newp.getRow(), newp.getCol());
    log = name + l;
    delete mb;
  }
}

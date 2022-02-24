#include <iostream>
using namespace std;

#include "Room.h"

Room::Room(ReqRoomType r, int n, float c){
  rt = r;
  roomNum = n;
  cost = c;
};

ReqRoomType Room::getRoomType(){
  return rt;
}

int Room::getRoomNum(){
  return roomNum;
}

float Room::getCost(){
  return cost;
}

void Room::computePoints(int& pts){
  if (rt == C_REG){
    pts = (0.10 * cost);
  }
  else if(rt == C_PREM){
    pts = (0.15 * cost);
  }
  else if(rt == C_SUITE){
    pts = (0.20 * cost);
  }
  else{
  }
}

void Room::print(){
  string rts;
  if(rt == C_REG){
    rts = "Regular";
  }
  else if(rt == C_PREM){
    rts = "Premium";
  }
  else if(rt == C_SUITE){
    rts = "Suite";
  }
  else{
  }
  cout<< rts << " " << roomNum << " $" << cost << endl;
}

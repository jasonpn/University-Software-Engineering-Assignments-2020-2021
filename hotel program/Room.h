#ifndef ROOM_H
#define ROOM_H

#include "defs.h"

/*
Class for making rooms for the hotel

computePoints compute points for guest premiums depending on the type of rooms
*/

class Room{
 public:
  Room(ReqRoomType = C_REG, int = 0, float = 0.0);
  ReqRoomType getRoomType();
  int getRoomNum();
  float getCost();
  void print();
  void computePoints(int& pts);
 private:
  ReqRoomType rt;
  int roomNum;
  float cost;
};

#endif

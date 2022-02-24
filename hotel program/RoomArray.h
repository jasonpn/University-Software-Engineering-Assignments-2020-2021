#ifndef ROOMARRAY_H
#define ROOMARRAY_H

#include "defs.h"
#include "Room.h"

/*
Room array class to keep a collection of rooms
*/
class RoomArray
{
  public:
    RoomArray();
    ~RoomArray();
    void  add(Room*);
    int   getSize();
    Room* get(int);
    void  print();

  private:
    Room* elements[MAX_ARR];
    int   size;
};

#endif


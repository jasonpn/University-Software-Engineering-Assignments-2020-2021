#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR 64

#include "Runner.h"

//Array class to make dynamically allocated array of Runner pointers

class Array
{
  public:
    Array();
    ~Array();
    void add(Runner*);
    Runner* get(int index);
    int getSize();


  private:
    Runner** runners;
    int   size;
};

#endif


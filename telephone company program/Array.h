#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR 256

#include "Call.h"

/*
Array class adds objects to elements array
*/
class Array
{
  public:
    Array();
    Array(Array&);
    ~Array();
    bool add(Call*);
    bool add(Array& arr);
    void cleanup();
    void print();
    int getSize();
    Call* get(int);

  private:
    Call* elements[MAX_ARR];
    int   size;
};

#endif


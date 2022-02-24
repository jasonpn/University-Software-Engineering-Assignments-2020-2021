#ifndef CALENDAR_H
#define CALENDAR_H

#define MAX_ARR 64

#include "Date.h"

/*
Calendar class that keeps a record of date objects.
arr member is a dynamic array that stores Date object pointers.
add function adds a date to calendar.
merge function merges two calendars together using the Date copy constructor
*/

class Calendar
{
  public:
    Calendar(string = "name");
    ~Calendar();
    bool add(Date*);
    string getName();
    void merge(Calendar* c);
    void printDates();
    void print();

  private:
    string name;
    Date** arr;
    int numDates;
};

#endif

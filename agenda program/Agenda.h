#ifndef AGENDA_H
#define AGENDA_H

#define MAX_CAL 4
#include "Calendar.h"
#include "Date.h"

/*
Agenda class that keeps a record of calendars and their dates. 
calendars member is a static array of calendar object pointers.
add function adds a calendar to the agenda.
find function finds a calendar with the matching name and returns it in its parameter.
overloaded add function uses the find function to find matching calendar adds a date to the calendar.
print function uses the Calendar class's merge function and prints the new merged calendar as the agenda.
*/

class Agenda
{
 public:
  Agenda(string = "name");
  ~Agenda();
  bool add(Calendar*);
  bool find(string n, Calendar** c);
  bool add(Date* d, string n);
  void print();
    
 private:
  string name;
  Calendar* calendars[MAX_CAL];
  int numCal;
};

#endif

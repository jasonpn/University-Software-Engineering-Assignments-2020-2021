#ifndef TIME_H
#define TIME_H

/*
Time class creates a Time with hours and minutes
*/

class Time
{
  public:
    Time(int=0, int=0);
    bool greaterThan(Time*);
    void print();

  private:
    int  hours;
    int  minutes;
    void setTime(int, int);
    int  convertToMins();
};

#endif

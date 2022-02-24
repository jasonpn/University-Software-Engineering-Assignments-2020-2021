#ifndef DATE_H
#define DATE_H

/*
Date class creates a date with day, month and year
*/

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    void setDate(int, int, int);
    //void printShort();
    //void printLong();
    //void printLong() const;
    bool lessThan(Date& d);
    bool equals(Date& d);
    void add(int duration);
    void print();

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif

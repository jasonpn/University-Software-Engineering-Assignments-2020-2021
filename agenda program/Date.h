#ifndef DATE_H
#define DATE_H

/*
Date class creates an event date. 
Date object has day, month, year, name, start time, duration, recurrence, recurrence number and validity.
validate function validates values for Date object
lessThan function compares two dates
*/
class Date
{
  public:
//    Date();
    Date(string = "name", int=0, int=0, int=2000, int=0, int=0, int=0, bool = false, int=10);
    Date(Date&);
    void setDate(int,int,int);
    //void printShort();
    //void printLong();
    bool validate(int,int,int,int,int,int);
    bool lessThan(Date* d);
    bool getRecur();
    bool getValid();
    void print();

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr();
    string eventName;
    int start;
    int duration;
    bool recur;
    int recurNum;
    bool valid;
    
};

#endif

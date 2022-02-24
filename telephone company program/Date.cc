#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  //cout<<"in default ctor"<<endl;
  setDate(d, m, y);
}

Date::~Date()
{
  //cout<<"in dtor"<<endl;
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}
/*
void Date::printShort()
{
  cout<<setfill('0')<<setw(2)<<day<<"/"
      <<setfill('0')<<setw(2)<<month<<"/"
      <<setfill('0')<<setw(4)<<year;
}

void Date::printLong() 
{
  cout << "non-const printLong()" << endl;
  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;
  month = 8;
}

void Date::printLong() const
{
  cout << "const printLong()" << endl;
  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;
//  month = 8;
}*/

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = { 
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

bool Date::greaterThan(Date* d){
   if(this->year > d->year){
    return true;
  }
  else if(this->year == d->year){
    if (this->month > d->month){
      return true;
    }
    else if (this->month == d->month){
      if (this->day > d->day){
	return true;
      }
      else{
	return false;
      }
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

bool Date::equals(Date* d){
  if(this->year == d->year){
    if(this->month == d->month){
      if(this->day == d->day){
	return true;
      }
    }
  }
  return false;

}

void Date::print(){
  cout<<setfill('0')<<setw(4)<<year<<"-"
      <<setfill('0')<<setw(2)<<month<<"-"
      <<setfill('0')<<setw(2)<<day;
}

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"


Date::Date(string n, int d, int m, int y, int h, int min, int dur, bool r, int rn)
{
  // cout<<"in default constructor"<<endl;
  setDate(d, m, y);
  eventName = n;
  recur = r;
  if (recur){
    recurNum = rn;
  }
  else{
    recurNum = 10;
  }
  if(validate(d, m, y, h, min, dur)){
    valid = true;
    start = (h*60) + min;
    duration = dur;
  }
  else{
    valid = false;
    start = 0;
    duration = 0;
  }
}

Date::Date(Date& oldDate){
  day = oldDate.day;
  month = oldDate.month;
  year = oldDate.year;
  eventName = oldDate.eventName;
  start = oldDate.start;
  duration = oldDate.duration;
  recur = oldDate.recur;
  recurNum = oldDate.recurNum;
  valid = oldDate.valid; 
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12 ) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

bool Date::getRecur(){
  return recur;
}

bool Date::getValid(){
  return valid;
}

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

string Date::getMonthStr()
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

bool Date::validate(int d, int m, int y, int h, int min, int dur){
  int valid = 0;
  if(d < 0 || d > lastDayInMonth()){
    valid++;
  }

  if( m < 0 || m > 12 ){
    valid++;
  }

  if(y<0){
    valid++;
  }

  if( h < 0 || h > 24 ){
    valid++;
  }

  if( min < 0 || min > 59 ) {
    valid++;
  }

  if (dur < 0){
    valid++;
  }

  if( valid > 0){
    return false;
  }
  else{
    return true;
  }
}

bool Date::lessThan(Date* d){
  if(this->year < d->year){
    return true;
  }
  else if(this->year == d->year){
    if (this->month < d->month){
      return true;
    }
    else if (this->month == d->month){
      if (this->day < d->day){
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

void Date::print()
{
  int h = start/60;
  int m = (start%60);
  int eh = (start+duration)/60;
  int em = ((start+duration)%60);
    
  cout<<"===   "<< setw(33)<< left<< eventName << ": "
      <<setw(10)<<getMonthStr()<<setw(2)<<day<<", "<<setw(5)<<year<< setw(5) << right
      << " @  " << setw(2) <<h<< ":" << setw(2)
      <<m << " - "<< setw(2)<< eh << ":" << setw(2)<<em;
  
  if(recur){
    cout<<", recurs for "<<recurNum<<" weeks";
  }
  cout<<"\n";

 
}

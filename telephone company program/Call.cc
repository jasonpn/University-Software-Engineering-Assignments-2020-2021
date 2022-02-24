#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Call.h"

Call::Call(string sr, string de, int y, int m, int d, int dur, int min, int h){
  src = sr;
  dest = de;
  duration = dur;
  date = new Date(d,m,y);
  start = new Time(h,min);
}

Call::~Call(){
  delete date;
  delete start;
}

bool Call::greaterThan(Call* c){
  if (!this->date->greaterThan(c->date)){
    if(!this->start->greaterThan(c->start)){
      return true;
    }
    else{
      return false;
    }
  }
  if(this->date->equals(c->date)){
    if(!this->start->greaterThan(c->start)){
      return true;
    }
    else{
      return false;
    }
  }
  return false;
}

string Call::getSrc(){
  return src;
}

string Call::getDest(){
  return dest;
}

void Call::print(){
  cout<<"Date: ";
  date->print();
  cout<<" Time: ";
  start->print();
  cout<<" From: "<< src << " To: " << dest << " Duration: " << duration <<endl;
}

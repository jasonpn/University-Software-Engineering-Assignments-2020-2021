#include <iostream>
#include <string>
using namespace std;

#include "Subscriber.h"

Subscriber::Subscriber(string num){
  phoneNum = num;
}

void Subscriber::addIncoming(Call* c){
  incalls.add(c);
}

void Subscriber::addOutgoing(Call* c){
  outcalls.add(c);
}

string Subscriber::getNum(){
  return phoneNum;
}

Array* Subscriber::getIn(){
  return &incalls;
}

Array* Subscriber::getOut(){
  return &outcalls;
}

void Subscriber::print(){
  cout<< endl<<endl<<"Subscriber " << phoneNum << ": "<<endl;
  /*
  Array combine(incalls);
  combine.add(outcalls);
  combine.print();
  */
  incalls.print();
  outcalls.print();
    
}

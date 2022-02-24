#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Call.h"
#include "Array.h"

/*
Subscriber class create subscribers and keeps track of their incoming and outgoing calls

*/
class Subscriber
{
 public:
  Subscriber(string="0000000000");
  void addIncoming(Call*);
  void addOutgoing(Call*);
  string getNum();
  Array* getIn();
  Array* getOut();
  void print();
 private:
  Array incalls;
  Array outcalls;
  string phoneNum;
};

#endif

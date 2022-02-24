#ifndef CLIENT_H
#define CLIENT_H

#include "Identifiable.h"
#include "CriteriaArray.h"

/*
Client class to create client with name and a criteria array. 
*/

class Client: public Identifiable{
 public:
  Client(string = "name");
  string getName();
  CriteriaArray& getCriteria();
  void addCriteria(Criteria*);
  void print();
 private:
  static int nextId;
  string name;
  CriteriaArray criteria;
};

#endif

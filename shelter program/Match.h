#ifndef MATCH_H
#define MATCH_H

#include "Animal.h"
#include "Client.h"

/*
Match class matching animal to client with a score. 
*/
class Match{
 public:
  Match(Animal*, Client*, float = 0.0);
  float getScore();
  string getClientId();
  void print();
 private:
  Animal* animal;
  Client* client;
  float score;
};

#endif

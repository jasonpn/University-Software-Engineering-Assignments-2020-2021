#ifndef SHELTER_H
#define SHELTER_H

#define MAX_ANIMALS 30
#define MAX_CLIENTS 30

#include "Animal.h"
#include "Client.h"
#include "MatchList.h"
#include "MatchListByScore.h"
#include "MatchListByClient.h"

/*
Shelter class to create a shelter, organizing animals and clients, and computing the match between clients and animals.
2 add functions to add animals and clients
computeMatches computes matches between animals and clients, adding them to lists by score and by client id
*/
class Shelter{
 public:
  Shelter(string = "name");
  ~Shelter();
  bool add(Animal*);
  bool add(Client*);
  void computeMatches(MatchListByScore&, MatchListByClient&);
  void printAnimals();
  void printClients();

 private:
  string name;
  Animal* animals[MAX_ANIMALS];
  Client* clients[MAX_CLIENTS];
  int numA;
  int numC;
  
  
};

#endif

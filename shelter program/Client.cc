#include <iostream>
using namespace std;
#include <string>

#include "Client.h"

int Client::nextId = 7001;

Client::Client(string n)
  :Identifiable("C", nextId){
  name = n;
  nextId++;
}

string Client::getName(){
  return name;
}

CriteriaArray& Client:: getCriteria(){
  return criteria;
}

void Client::addCriteria(Criteria* c){
  criteria.add(c);
}

void Client:: print(){
  cout<<this->getId() << " "<< name << "; " << endl;
  criteria.print();
}

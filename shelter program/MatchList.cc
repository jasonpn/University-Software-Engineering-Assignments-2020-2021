#include <iostream>
#include <string>
using namespace std;

#include "MatchList.h"

MatchList::MatchList() : head(NULL) { }

MatchList::~MatchList()
{
}


void MatchList::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}

void MatchList::cleanup(){
  Node* curr;
  Node* next;

  curr = head;

  while (curr != NULL){
    next = curr->next;
    delete curr->data;
    delete curr;
    curr = next;
  }
}


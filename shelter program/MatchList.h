#ifndef LIST_H
#define LIST_H

#include "Match.h"

/*
MatchList base linked list class, creating Node class for use and printing list

*/
class MatchList
{
 protected:
  class Node
  {
    public:
      Match* data;
      Node*    next;
  };

  public:
    MatchList();
    ~MatchList();
    //void add(Match*);
    //void del(const string&, Match**);
    void print() const;
    void cleanup();

  protected:
    Node* head;

};

#endif


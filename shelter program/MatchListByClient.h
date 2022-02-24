#ifndef MATCHLISTBYCLIENT_H
#define MATCHLISTBYCLIENT_H

#include "MatchList.h"

/*
MatchListByClient class inherits MatchList, adds Match to linked list by ascending client ID
*/
class MatchListByClient : public MatchList{
 public:
  void add(Match*);
};

#endif

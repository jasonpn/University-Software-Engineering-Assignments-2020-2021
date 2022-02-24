#ifndef MATCHLISTBYSCORE_H
#define MATCHLISTBYSCORE_H

#include "MatchList.h"

/*
MatchListByScore class inherits MatchList, adds Match to linked list by descending score
*/

class MatchListByScore : public MatchList{
 public:
  void add(Match*);
};

#endif

#ifndef DYNARRAY_H
#define DYNARRAY_H

#include "Criteria.h"
#include "defs.h"

/*
CriteriaArray class creates an array of criterias 
*/

class CriteriaArray
{
  public:
    CriteriaArray();
    ~CriteriaArray();
    void      add(Criteria*);
    int       getSize();
    Criteria* get(int);
    void      print();

  private:
    Criteria* elements[MAX_SIZE];
    int       size;
};

#endif


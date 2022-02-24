#ifndef CRITERIA_H
#define CRITERIA_H

#include <string>
using namespace std;

/*
Criteria class creates criteria to keep track of client preferences. 
*/

class Criteria
{
  public:
    Criteria(string="", string="", int=0);

    string getName();
    string getValue();
    int    getWeight();
    void   print();

  private:
    string name;
    string value;
    int    weight;
};

#endif

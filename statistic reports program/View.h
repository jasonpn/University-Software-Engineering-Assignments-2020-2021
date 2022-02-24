#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

//View class to display menu to users

class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif

#include <iostream>
using namespace std;
#include <string>
#include <sstream>

#include "Identifiable.h"

Identifiable::Identifiable(string n, int i){
  stringstream ss;
  ss << n <<"-"<< i;
  id = ss.str();
}

string Identifiable::getId(){
  return id;
}

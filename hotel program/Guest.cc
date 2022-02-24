#include <iostream>
using namespace std;
#include <string>

#include "Guest.h"

Guest::Guest(string n, bool p){
  name = n;
  prem = p;
  numPoints = 0;
}

string Guest::getName(){
  return name;
}

bool Guest::getPrem(){
  return prem;
}

void Guest::addPts(int p){
  numPoints = numPoints + p;
}
void Guest::print(){
  string p;
  if(prem){
    p = "Premium";
  }
  else{
    p = "Regular";
  }
  cout<< name << " " << p << " " << numPoints << endl;
}

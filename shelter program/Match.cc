#include <iostream>
#include <iomanip>
using namespace std;

#include <string>
#include "Match.h"


Match::Match(Animal* a, Client* c, float s){
  animal = a;
  client = c;
  score = s;
}


float Match::getScore(){
  return score;
}

string Match::getClientId(){
  return client->getId();
}

void Match::print(){
  cout<< getClientId() << " " << setw(6)<< client->getName() << "   :"
      << animal->getId() << " " << setw(10)<< animal->getName() << "   :"
      << score << " ("<< (score/20)*100 << ") "<<endl;
}

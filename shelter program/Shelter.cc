#include <iostream>
using namespace std;
#include <string>
#include <sstream>

#include "Shelter.h"
#include "MatchList.h"

Shelter::Shelter(string n){
  name = n;
  numA = 0;
  numC = 0;
}

Shelter::~Shelter(){
  for(int i =0; i<numA; i++){
    delete animals[i];
  }
  for(int i =0; i<numC; i++){
    delete clients[i];
  }
}

bool Shelter::add(Animal* a){
  animals[numA] = a;
  numA++;
  return true;
}

bool Shelter::add(Client* c){
  clients[numC] = c;
  numC++;
  return true;
}

void Shelter::computeMatches(MatchListByScore& mls, MatchListByClient& mlc){
  Match* newm;
  for(int i = 0; i<numC; i++){
    for(int j = 0; j<numA; j++){
      float s = 0.0;
      for(int x = 0; x<clients[i]->getCriteria().getSize(); x++){
	if(clients[i]->getCriteria().get(x)->getName() == "Species"){
	  if(clients[i]->getCriteria().get(x)->getValue() == animals[j]->getSpecies()){
	    s += 10;
	  }
	}
	else if(clients[i]->getCriteria().get(x)->getName() == "Breed"){
	  if(clients[i]->getCriteria().get(x)->getValue() == animals[j]->getBreed()){
	    s += clients[i]->getCriteria().get(x)->getWeight();
	  }
	  
	}
	else if(clients[i]->getCriteria().get(x)->getName() == "Gender"){
	  if(clients[i]->getCriteria().get(x)->getValue() == animals[j]->getGender()){
	    s += clients[i]->getCriteria().get(x)->getWeight();
	  }
	}
	else if(clients[i]->getCriteria().get(x)->getName() == "Age"){
	  float a = (animals[j]->getAge())/12;
	  stringstream ss;
	  int cage = 0;
	  ss << clients[i]->getCriteria().get(x)->getValue();
	  ss >> cage;
	  float prop = (abs(a-cage))/10;
	  if(prop > 1){
	    prop = 1;
	  }

	  s += (clients[i]->getCriteria().get(x)->getWeight()) * (1 - prop);
	}
      }
      if (s == 0){
      }
      else{
	newm = new Match(animals[j], clients[i], s);
	mls.add(newm);
	mlc.add(newm);
      }
    }    
  }
}

void Shelter::printAnimals(){
  for (int i = 0; i<numA; i++){
    animals[i]->print();
  }
}
void Shelter::printClients(){
  for (int i = 0; i<numC; i++){
    clients[i]->print();
  }
}

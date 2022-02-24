#include <iostream>
#include <string>
using namespace std;

#include "Telco.h"

Telco::Telco(string n){
  numSubs = 0;
  name = n;
  calls = new Array();
  subs = new Subscriber*[MAX_SUB];
}

Telco::~Telco(){
  for(int i = 0; i < numSubs; i++){
    subs[i]->getIn()->cleanup();
    subs[i]->getOut()->cleanup();
    delete subs[i];    
  }
  delete[] subs;
  calls->cleanup();
  delete calls;
}

void Telco::addSub(Subscriber* s){
  subs[numSubs] = s;
  numSubs++;
}

void Telco::addCall(string srcNum, string destNum, int y, int m, int d, int h, int min, int dur){
  Call* newc = new Call(srcNum, destNum, y, m, d, dur, min, h);

  for(int i = 0; i<numSubs; i++){
    if(subs[i]->getNum() == srcNum || subs[i]->getNum() == destNum){
      calls->add(newc);
      if(subs[i]->getNum() == srcNum){
	subs[i]->addOutgoing(newc);
      }
      if(subs[i]->getNum() == destNum){
	subs[i]->addIncoming(newc);
      }
    }
  }

}

void Telco::computeFreqCaller(string destNum){

  if(destNum == "all"){
    int count;
    int max = 1;
    Call* newc;
    for(int i = 0; i<calls->getSize()-1; i++){
      count = 0;
      for(int j = i; j<calls->getSize(); j++){
	if (calls->get(i)->getSrc() == calls->get(j)->getSrc()){
	  count++;
	}
      }
      if (count > max){
	max = count;
	newc = calls->get(i);
      }
    }
    for(int x = 0; x <numSubs; x++){
      if (subs[x]->getNum() == newc->getSrc()){
	cout<<"==> MOST FREQUENT CALLER TO ALL <==";		
	subs[x]->print();
      }
    }
  }

  else{
    int count;
    int max = 1;
    Call* newc;
    Array* a;
    for (int i = 0; i<numSubs; i++){
      if(subs[i]->getNum() == destNum){
	a = subs[i]->getIn();
      }
      else{
	cout<<"ERROR: COULD NOT FIND SUBSCRIBER"<<endl;
	break;
      }
    }

    for(int i = 0; i<a->getSize()-1; i++){
      count = 0;
      for(int j = 0; j<a->getSize();j++){
	if(a->get(i)->getSrc() == a->get(j)->getSrc()){
	  count++;
	}
	
      }
      if (count > max){
	max = count;
	newc = a->get(i);
      }
    }
    
    cout<<"==> MOST FREQUENT CALLER TO " << destNum << " :  "<< newc->getSrc() << endl;	    

    for(int x = 0; x <a->getSize(); x++){
      if (a->get(x)->getSrc() == newc->getSrc()){
	a->get(x)->print();
      }
    }
  }
 
}

void Telco::computeFreqCalled(string srcNum){

  int count;
  int max = 1;
  Call* newc;
  if(srcNum == "all"){
    for(int i = 0; i<calls->getSize()-1; i++){
      count = 0;
      for(int j = i; j<calls->getSize(); j++){
	if (calls->get(i)->getDest() == calls->get(j)->getDest()){
	  count++;
	}
      }
      if (count > max){
	max = count;
	newc = calls->get(i);
      }
    }
    for(int x = 0; x <numSubs; x++){
      if (subs[x]->getNum() == newc->getDest()){
	cout<<"==> MOST FREQUENT CALLED FROM ALL <==";
	subs[x]->print();
      }
    }
  }
  else{
    int count;
    int max = 1;
    Call* newc;
    Array* a;
    for (int i = 0; i<numSubs; i++){
      if(subs[i]->getNum() == srcNum){
	a = subs[i]->getOut();
      }
      else{
	cout<<"ERROR: COULD NOT FIND SUBSCRIBER"<<endl;
	break;
      }
    }
    for(int i = 0; i<a->getSize()-1; i++){
      count = 0;
      for(int j = 0; j<a->getSize();j++){
	if(a->get(i)->getDest() == a->get(j)->getDest()){
	  count++;
	}
	
      }
      if (count > max){
	max = count;
	newc = a->get(i);
      }
    }
    
    cout<<"==> MOST FREQUENT CALLED FROM " << srcNum << " :  "<< newc->getDest() << endl;	    

    for(int x = 0; x <a->getSize(); x++){
      if (a->get(x)->getDest() == newc->getDest()){
	a->print();
      }
    }
  }
}

void Telco::print(){
  for(int i = 0; i<numSubs; i++){
    subs[i]->print();
  }
}

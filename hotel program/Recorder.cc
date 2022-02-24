#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>

#include "Recorder.h"

Recorder::Recorder(string n){
  name = n;
}

void Recorder::printRecords(){
  cout<< "Records for " <<name << endl;
  for (int i = 0; i< records.size();i++){
    cout<<records[i]<<endl;
  }
  cout<<endl;
}

StayRecorder::StayRecorder(string n)
  :Recorder(n){
}

void StayRecorder::update(Reservation* r){
  if (r->getDays() > 3){
    string nrec;
    stringstream rec;
    rec << "Stay record: " << "Guest " << r->getGuest()->getName() << ", " << r->getDays() << " nights";
    nrec = rec.str();
    records.push_back(nrec);
  }
}

GuestRecorder::GuestRecorder(string n)
  :Recorder(n){
}

void GuestRecorder::update(Reservation* r){
  if (!r->getGuest()->getPrem()){
    if(r->getRoom()->getRoomType() == C_PREM || r->getRoom()->getRoomType() == C_SUITE){
      string nrec;
	
      stringstream rec;
      rec << "Premium guest offer for " << r->getGuest()->getName();
      nrec = rec.str();
      records.push_back(nrec);
    }
  }
}

UpgradeRecorder::UpgradeRecorder(string n)
  :Recorder(n){
}

void UpgradeRecorder::update(Reservation* r){
  if (!r->getGuest()->getPrem()){
    if(r->getCharge() > 1500){
      string nrec;
	  
      stringstream rec;
      rec << r->getGuest()->getName() << ", $" << r->getCharge();
      nrec = rec.str();
      records.push_back(nrec);
    }
  }
}

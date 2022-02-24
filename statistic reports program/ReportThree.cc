#include <iostream>
#include <iomanip>
using namespace std;

#include <fstream>
#include <sstream>


#include "ReportThree.h"

ReportThree::ReportThree(){
  CompareBehaviour<int>* d = new DescBehaviour<int>;

  results = new ReportData<int>(d);
}

ReportThree::~ReportThree(){
  delete results;
}

void ReportThree::compute(){
  if(records.size() == 0){
    this->loads();
  }

  Map<string> atemp;
  for(int j = 0; j<animals["Horses-Ponies"].size(); j++){
    if(animals["Horses-Ponies"][j]->getYear() == 2016){
      if(animals["Horses-Ponies"][j]->getSubReg() != "All"){
	if(animals["Horses-Ponies"][j]->getRegion() != "CAN" ){
	  if((findDupe(animals["Horses-Ponies"][j]->getRegion()))){
	    //atemp.add(
	    formatData(results, animals["Horses-Ponies"][j]->getRegion(), animals["Horses-Ponies"][j]->getSubReg(), animals["Horses-Ponies"][j]->getNumA());
	  }
	}
      }
    }
  }

  printReport(results);
}

void ReportThree::formatData(ReportData<int>* r, string k, string sr, int a){
  
  stringstream ss;
  
  ss <<setw(4)<< k << " "<<setw(30)<< sr << setw(10) << a;
  
  string s = ss.str();
  results->add(a,s); 
  

}

bool ReportThree::findDupe(string x){
  for(int j = 0; j<animals["Horses-Ponies"].size(); j++){
    if(animals["Horses-Ponies"][j]->getRegion() == x){
      return true;
    }
    
  }
    
  return false;
  
}

void ReportThree::printReport(ReportData<int>* r){

  ofstream outfile("ReportThree.txt", ios::out);

  if(!outfile){
    cout<< "ERROR: could not open file"<<endl;
    exit(1);
  }
  cout<<"SUBREGION WITH MOST HORSES/PONIES BY REGION IN 2016"<<endl;
  
  cout<<(*r)<<endl;

  outfile<<"SUBREGION WITH MOST HORSES/PONIES BY REGION IN 2016"<<endl;
  
  outfile<<(*r)<<endl;
}

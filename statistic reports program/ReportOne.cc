#include <iostream>
using namespace std;
#include <iomanip>

#include <sstream>
#include <fstream>
#include <string>


#include "ReportOne.h"

ReportOne::ReportOne(){
  if(records.size() == 0){
    this->loads();
  }
  CompareBehaviour<float>* d = new DescBehaviour<float>;
  results = new ReportData<float>(d);
}

ReportOne::~ReportOne(){
  delete results;
}

void ReportOne::compute(){
  int numtotal = 0;
  for(int i = 0; i < regions.getKeySize(); i++){
    for(int j = 0; j<regions[regions.getKeys()[i]].size(); j++){
      if(regions.getKeys()[i] == "CAN"){
      }
      else if(regions[regions.getKeys()[i]][j]->getSubReg() == "All" && regions[regions.getKeys()[i]][j]->getYear() == 2016){
	numtotal = numtotal + regions[regions.getKeys()[i]][j]->getNumF();
      }
    }
  }
  
  vector<float> vals;
  float totalf = 0.0f;
  for(int i = 0; i < regions.getKeySize(); i++){
    if(regions.getKeys()[i] != "CAN"){
      getRegionVal(&vals, regions.getKeys()[i]);
      totalf = (getTotalF(regions.getKeys()[i])*100.0f)/numtotal;
      formatData(results, vals, regions.getKeys()[i], totalf);
      vals.clear();
    }   

  }



  printReport(results);
  

}

void ReportOne::getRegionVal(vector<float>* v, string r){
  float hp = 0.0f;
  for(int i = 0; i < regions.getKeySize(); i++){
    for(int j = 0; j<regions[regions.getKeys()[i]].size(); j++){    
      if(regions.getKeys()[i] == "CAN"){
      }
      else if(regions[regions.getKeys()[i]][j]->getSubReg() == "All" && regions[regions.getKeys()[i]][j]->getYear() == 2016 && regions.getKeys()[i] == r){
	hp = (regions[regions.getKeys()[i]][j]->getNumF() * 100.0f) / getTotal(regions[regions.getKeys()[i]][j]->getAType());
	v->push_back(hp);
	/*
	if(hp == 0.0){
	  v->push_back(0.0f);
	  }*/
      }
    }
  }
}
  

int ReportOne::getTotal(string k){
  
  int total = 0;
  for(int i = 0; i < regions.getKeySize(); i++){
    for(int j = 0; j<regions[regions.getKeys()[i]].size(); j++){
      if(regions.getKeys()[i] == "CAN"){
      }
      else if(regions[regions.getKeys()[i]][j]->getSubReg() == "All" && regions[regions.getKeys()[i]][j]->getYear() == 2016){
	if(regions[regions.getKeys()[i]][j]->getAType() == k){
	  //if(regions[regions.getKeys()[i]][j]->getNumA() > 0){
	    total = total + regions[regions.getKeys()[i]][j]->getNumF();	    
	    // }	  
	}
      }
    }
  }
  return total;
    
}

int ReportOne::getTotalF(string k){
  int totalf  = 0;
  for(int i = 0; i < regions.getKeySize(); i++){
    for(int j = 0; j<regions[regions.getKeys()[i]].size(); j++){
      if(regions.getKeys()[i] == "CAN"){
      }
      else if(regions[regions.getKeys()[i]][j]->getSubReg() == "All" && regions[regions.getKeys()[i]][j]->getYear() == 2016 && regions.getKeys()[i] == k){
	totalf = totalf + regions[regions.getKeys()[i]][j]->getNumF();
      }
    }
  }

  return totalf;
  
}

void ReportOne::formatData(ReportData<float>* r, vector<float> v, string reg, float t){
  stringstream ss;
  ss << setw(4)<<reg << " ";
  
  for(int i = 0; i < v.size(); i++){
    ss << fixed << setprecision(1) << setw(7) << v[i] << " ";
  }
  ss <<setw(7)<< t;
  string s = ss.str();
  results->add(t, s);
      
}

void ReportOne::printReport(ReportData<float>* r){

  ofstream outfile("ReportOne.txt", ios::out);

  if(!outfile){
    cout<< "ERROR: could not open file"<<endl;
    exit(1);
  }
  cout<<"PERCENTAGE OF FARMS BY REGION IN 2016"<<endl;
  cout<<"    "<<setw(10)<< "Horses/" << setw(7)<<"Goats" << setw(7)<<" Llamas/"
      <<setw(7)<< "  Rabbits  "<<setw(7)<<"Bison/ "<<setw(7)<<"Elk/ "
      <<setw(7)<<"Domestic "<<" Mink  " << setw(7)<<"Totals"<< " Wild Boars "<< endl;
  cout<<"    "<<setw(10)<<"Ponies" << setw(17) <<"Alpacas"<<setw(15)<<"Buffalo"<<endl;
  cout<<(*r)<<endl;

  outfile<<"PERCENTAGE OF FARMS BY REGION IN 2016"<<endl;
  outfile<<"    "<<setw(10)<< "Horses/" << setw(7)<<"Goats" << setw(7)<<" Llamas/"
      <<setw(7)<< "  Rabbits  "<<setw(7)<<"Bison/ "<<setw(7)<<"Elk/ "
      <<setw(7)<<"Domestic "<<" Mink  " << setw(7)<<"Totals"<< " Wild Boars "<< endl;
  outfile<<"    "<<setw(10)<<"Ponies" << setw(17) <<"Alpacas"<<setw(15)<<"Buffalo"<<endl;
  outfile<<(*r)<<endl;
 
}

void ReportOne::clean(){
  //delete results;
}

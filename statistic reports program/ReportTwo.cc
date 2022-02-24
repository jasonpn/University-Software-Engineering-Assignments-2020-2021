#include <iostream>
#include <iomanip>
using namespace std;

#include <sstream>
#include <cstdlib>
#include <fstream>


#include "ReportTwo.h"

ReportTwo::ReportTwo(){
  CompareBehaviour<float>* a = new AscBehaviour<float>;

  results = new ReportData<float>(a);
}

ReportTwo::~ReportTwo(){
  delete results;
}

void ReportTwo::compute(){
  if(records.size() == 0){
    this->loads();
  }
  vector<float> vals2011;
  vector<float> vals2016;



  for(int j = 0; j < years[2016].size(); j++){
    if(years[2016][j]->getRegion() == "CAN"){
    getAnimalVal(&vals2016, years[2016][j]->getAType(), 2016);
    }
  }


  vector<float>::iterator itr = vals2016.end()-1;
  vals2016.insert(itr, 0.0f);

  
  for(int j = 0; j < years[2011].size(); j++){
    if(years[2011][j]->getRegion() == "CAN"){
      getAnimalVal(&vals2011, years[2011][j]->getAType(), 2011);
    }
  }

  for(int j = 0; j < vals2011.size(); j++){
    float change = 0.0f;
    stringstream ss;
    change = vals2016[j] - vals2011[j];
    
    formatData(results, years[2011][j]->getAType(),vals2011, vals2016, change, j);

  }

  
  printReport(results);
  
  
}

void ReportTwo::getAnimalVal(vector<float>* v, string k, int y){
  float total = 0.0f;      
  for(int j = 0; j<years[y].size();j++){
    if(years[y][j]->getRegion() == "CAN" && years[y][j]->getAType() == k){
      total = (years[y][j]->getNumA() * 100.0f)/getTotal(y);
      v->push_back(total);
    }
    
  }
  
  
}


int ReportTwo::getTotal(int y){
  int total = 0;
  for(int j = 0; j<years[y].size();j++){
    if(years[y][j]->getRegion() == "CAN"){
      total = total + years[y][j]->getNumA();
    }
    
  }
  

  //cout<<total<<endl;
  return total;
  

}

void ReportTwo::formatData(ReportData<float>* r, string a, vector<float> v1, vector<float> v2, float c, int j){
  
  stringstream ss;
  if(c > 0){
    ss <<setw(15)<< a << " "<< fixed << setprecision(1) << setw(7)<< v1[j] <<setw(7)<< v2[j]
       << "   +"<<c<< " ";
  }
  else{
  ss <<setw(15)<< a << " "<< fixed << setprecision(1) << setw(7)<< v1[j] <<setw(7)<< v2[j]
     << setw(7)<< c<< " ";
  }
  string s = ss.str();
  results->add(c,s);
  
 
  
}

void ReportTwo::printReport(ReportData<float>* r){
  ofstream outfile("ReportTwo.txt", ios::out);

  if(!outfile){
    cout<< "ERROR: could not open file"<<endl;
    exit(1);
  }
  cout<<"PERCENTAGE CHANGE OF ANIMALS (2011-2016)"<<endl;

  cout<<setw(25)<<" 2011 "<< setw(7) << " 2016 "<< setw(7)<<" Change "<<endl;
  cout<<(*r)<<endl;

  outfile<<"PERCENTAGE CHANGE OF ANIMALS (2011-2016)"<<endl;

  outfile<<setw(25)<<" 2011 "<< setw(7) << " 2016 "<< setw(7)<<" Change "<<endl;
  outfile<<(*r)<<endl;
}

void ReportTwo::clean(){
  delete results;
}

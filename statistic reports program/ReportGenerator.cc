#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "ReportGenerator.h"
vector<Record*> ReportGenerator::records;
Map<int> ReportGenerator::years;
Map<string> ReportGenerator::regions;
Map<string> ReportGenerator::animals;

void ReportGenerator::loads(){
  int yr, numa, numf;
  string reg, subreg, atype;

  ifstream infile("farms.dat", ios::in);

  if(!infile){
    cout<<"File could not be opened" << endl;
    exit(1);
  }

  while(infile >> yr >> reg >> subreg >> atype >> numf >> numa){
    Record* rec = new Record(yr, reg, subreg, atype, numf, numa);
    records.push_back(rec);
    years.add(rec->getYear(), rec);
    regions.add(rec->getRegion(), rec);
    animals.add(rec->getAType(), rec);
  }
}

void ReportGenerator::clean(){
  records.clear();
}

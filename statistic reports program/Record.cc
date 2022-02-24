#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Record.h"

Record::Record(int y, string r, string sr, string at, int nf, int na){
  year = y;
  region = r;
  subRegion = sr;
  animalType = at;
  numFarms=nf;
  numAnimals = na;
}

int Record::getYear(){
  return year;
}

string Record::getRegion(){
  return region;
}
string Record::getSubReg(){
  return subRegion;
}
string Record::getAType(){
  return animalType;
}
int Record::getNumF(){
  return numFarms;
}

int Record::getNumA(){
  return numAnimals;
}

ostream& operator<<(ostream& output, Record& r){
  output << "YEAR: " << r.getYear() << "; REGION: " << r.getRegion()
	 << "; Sub Region: " << r.getSubReg()
	 << "; AnimalType: " << r.getAType()
	 <<"; NumFarms: " << r.getNumF()
	 <<"; NumAnimals: " << r.getNumA() << endl;

  return output;
}

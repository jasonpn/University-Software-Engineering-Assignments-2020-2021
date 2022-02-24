#ifndef RECORD_H
#define RECORD_H

//clas to create a record of farms, years, animaltype, regions, subregions.

class Record{
  friend ostream& operator<<(ostream&, Record&);
  
 public:
  Record(int = 2000, string = "region", string = "N/A", string = "type", int = 0, int = 0);
  int getYear();
  string getRegion();
  string getSubReg();
  string getAType();
  int getNumF();
  int getNumA();

 private:
  int year;
  string region;
  string subRegion;
  string animalType;
  int numFarms;
  int numAnimals;

};

#endif

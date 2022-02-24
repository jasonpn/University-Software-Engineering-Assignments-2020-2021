#ifndef REPORTTWO_H
#define REPORTTWO_H

#include "ReportGenerator.h"

//concrete class from reportgenerator to create report two
class ReportTwo: public ReportGenerator {
 public:
  ReportTwo();
  ~ReportTwo();
  virtual void compute();
  int getTotal(int);
  void getAnimalVal(vector<float>*, string, int);
  void formatData(ReportData<float>*, string, vector<float>, vector<float>, float, int);
  void printReport(ReportData<float>*);
  void clean();
  
 private:
  ReportData<float>* results;
};

#endif

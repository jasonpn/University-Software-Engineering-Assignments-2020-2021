#ifndef REPORTTHREE_H
#define REPORTTHREE_H

#include "ReportGenerator.h"

//concrete class from reportgenerator to create report one
class ReportThree: public ReportGenerator {
 public:
  ReportThree();
  ~ReportThree();
  virtual void compute();
  void formatData(ReportData<int>*, string, string, int);
  bool findDupe(string);
  void printReport(ReportData<int>*);
  
 private:
  ReportData<int>* results;
};

#endif

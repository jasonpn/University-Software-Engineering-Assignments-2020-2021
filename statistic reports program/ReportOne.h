#ifndef REPORTONE_H
#define REPORTONE_H

#include "ReportGenerator.h"

//concrete class from reportgenerator to create report one
class ReportOne: public ReportGenerator {
 public:
  ReportOne();
  ~ReportOne();
  virtual void compute();
  void formatData(ReportData<float>*, vector<float>, string, float);
  int getTotal(string);
  void getRegionVal(vector<float>*, string);
  int getTotalF(string);
  void printReport(ReportData<float>*);
  void clean();
  
 private:
  ReportData<float>* results;
};

#endif

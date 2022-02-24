#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include <string>

#include "Record.h"
#include "Map.h"
#include "ReportData.h"

//abstract class to generate reports
class ReportGenerator{
 public:
  static void loads();
  virtual void compute() = 0;
  void clean();

 protected:
  static vector<Record*> records;
  static Map<int> years;
  static Map<string> regions;
  static Map<string> animals;


};








#endif

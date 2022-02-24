#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <string>

#include "CompareBehaviour.h"

//template class to create report data to populate reports. nested ReportRow class to represent rows of data
template <class T>
class ReportData{
 template <class V>
 friend ostream& operator<<(ostream&, ReportData<V>&);
 
 private:
  template <class Y>
  class ReportRow{
   public:
    ReportRow(Y key, string r){
      rowkey = key;
      row = r;
    }
    Y rowkey;
    string row;
  };

  vector<ReportRow<T>*> rows;
  CompareBehaviour<T>* behav;

 public:
  ReportData(CompareBehaviour<T>* = NULL);
  ~ReportData();
  bool add(T key, string row);
  


};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c){
  behav = c;
}

template <class T>
ReportData<T>::~ReportData(){
  rows.clear();
}


template <class T>
bool ReportData<T>::add(T key, string row){
  if(rows.size() == 0){
    ReportRow<T>* r = new ReportRow<T>(key, row);
    rows.push_back(r);
    return true;
  }
  typename vector<ReportRow<T>*>::iterator itr;

  for(itr = rows.begin(); itr != rows.end(); itr++){
    if(behav->compare((*itr)->rowkey,key)){
      ReportRow<T>* r = new ReportRow<T>(key, row);
      rows.insert(itr, r);
      return true;
   
    }
  }

  ReportRow<T>* r = new ReportRow<T>(key, row);
  rows.push_back(r);
  return true;
}

template <class T>
ostream& operator<<(ostream& output, ReportData<T>& r){
  for(int i = 0; i < r.rows.size(); i++){
    output << r.rows[i]->row << endl;
  }

  return output;
}

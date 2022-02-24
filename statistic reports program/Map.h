#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>

#include "Record.h"

//map template class to create a map with keys and values as vectors and vector of record pointer vectors
template <class T>
class Map{

 public:
  bool add(T key, Record* rec);
  int getKeySize();
  vector<T>& getKeys();
  vector<Record*>& operator[](T);
 private:
  vector<T> keys;
  vector<vector<Record*>> values;
};


template <class T>
bool Map<T>::add(T key, Record* rec){
  if (keys.size() == 0){
    vector<Record*> vr; 
    keys.push_back(key);
    vr.push_back(rec);
    values.push_back(vr);
    return true;
  }
  for(int i = 0; i<keys.size(); i++){
    if (keys[i] == key){
      values[i].push_back(rec);
      return true;
    }
  }
  vector<Record*> vr; 
  keys.push_back(key);
  vr.push_back(rec);
  values.push_back(vr);
  return true;
   
}

template <class T>
int Map<T>::getKeySize(){
  return keys.size();
}

template <class T>
vector<T>& Map<T>::getKeys(){
  return keys;
}

template <class T>
vector<Record*>& Map<T>::operator[](T t){

  for(int i = 0; i<keys.size(); i++){
    if(keys[i] == t){
      return values[i];
    }
  }

}

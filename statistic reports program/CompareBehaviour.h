#include <iostream>
using namespace std;


//comparebehaviour class template to compare two parameters, with concrete classes for ascending and descending
template <class T>
class CompareBehaviour{
 public:
  virtual bool compare(T, T) = 0;
};

template <class T>
class AscBehaviour : public CompareBehaviour<T>{
 public:
  virtual bool compare(T,T);
};

template <class T>
class DescBehaviour : public CompareBehaviour<T>{
 public:
  virtual bool compare(T,T);
};

template <class T>
bool AscBehaviour<T>::compare(T t1, T t2){
  if (t1 > t2){
    return true;
  }
  else{
    return false;
  }
}

template <class T>
bool DescBehaviour<T>::compare(T t1, T t2){
  if (t1 < t2){
    return true;
  }
  else{
    return false;
  }
}




#include <iostream>
using namespace std;

#include "Array.h"

Array::Array()
{
  size = 0;
}

Array::~Array()
{

}

Array::Array(Array& a){
  size = a.size;
  for (int i = 0; i<a.size; i++){
    elements[i] = a.get(i);
  }
}

bool Array::add(Call* c)
{
  if(size == MAX_ARR){
    return false;
  }
  if (size == 0){
    elements[size] = c;
    size++;
    return true;
  }

  for(int i = 0; i<size; i++){
    if (c->greaterThan(elements[i])){
      for (int j = size; j>i; j--){
	elements[j] = elements[j-1];
      }
      elements[i] = c;
      size++;
      return true;
    }
  }
  
  elements[size] = c;
  ++size;
  return true;
}

bool Array::add(Array& arr){
  size = arr.size;
  for (int i = 0; i<arr.size; i++){
    elements[i] = arr.get(i);
    return true;
  }
  return false;;  
}

int Array::getSize(){
  return size;
}

Call* Array::get(int index){
  return elements[index];
}

void Array::cleanup(){
  for (int i=0; i<size; ++i)
    delete elements[i];
}
void Array::print()
{
  //cout << endl << endl << "DATES:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  //cout << endl;
}



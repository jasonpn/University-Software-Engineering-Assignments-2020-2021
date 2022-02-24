#include <iostream>
using namespace std;

#include "Array.h"

//Array constructor
Array::Array()
{
  size = 0;
  //create a dynamic runners array
  runners = new Runner*[MAX_ARR];
}

//Array destructor
Array::~Array()
{
  //frees runners and deletes the runner array
  for(int i=0; i<size; ++i){
    delete runners[i];
  }
  delete[] runners;
}

//Add runners to array by bib number
void Array::add(Runner* r)
{
  int k = 0;
  if (size >= MAX_ARR){
    return;
  }
  if (size == 0){
    runners[0] = r;
    ++size;
  }
  else{
    for(int i =0; i<size; i++){
      if (runners[i]->lessThan(r)){ //uses runner's lessThan to compare
	k = i;
	break;
      }
    }
    for (int j = size; j>k; j--){
      runners[j+1] = runners[j];
    }
    runners[k+1] = r;
    ++size;

  }

   
}

//return the runner from the array at index
Runner* Array::get(int index){
  if (runners[index] == NULL){
    return NULL;
  }

  return runners[index];
}

//get the size of the array
int Array::getSize(){
  return size;
}


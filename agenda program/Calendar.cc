#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Calendar.h"

Calendar::Calendar(string n){
  name = n;
  arr = new Date*[MAX_ARR];
  numDates = 0;
}

Calendar::~Calendar(){
  for (int i = 0; i < numDates; i++){
    delete arr[i];
  }
  delete[] arr;
}

bool Calendar::add(Date* d){
  if(d->getValid() == false){
    cout<<"invalid date"<<endl;
    delete d;
    return false;
  }
  else{
    if(numDates == 0){
      arr[numDates] = d;
      numDates++;
      return true;
    }

    for (int i = 0; i<numDates; i++){
      if (d->lessThan(arr[i])){
	for (int j = numDates; j>i; j--){
	  arr[j] = arr[j-1];
	  //cout<<"done"<<endl;
	}
	arr[i] = d;
	numDates++;
	return true;
      
      }
      //break;
    }

    arr[numDates] = d;
    numDates++;
    return true;
  }
}

string Calendar::getName(){
  return name;
}

void Calendar::merge(Calendar* c){
  for(int i = 0; i<c->numDates; i++){
    Date* newd = new Date(*c->arr[i]);
    this->add(newd);
  }
}

void Calendar::printDates(){
  for (int i = 0; i<numDates; i++){
    arr[i]->print();
  }
 
}

void Calendar::print(){
  printDates();
  cout<<" "<<endl;
}

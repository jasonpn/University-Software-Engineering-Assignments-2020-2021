#include <iostream>
using namespace std;

#include "Control.h"
#include "ReportOne.h"
#include "ReportTwo.h"
#include "ReportThree.h"

Control::Control(){
  one = new ReportOne();
  two = new ReportTwo();
  three = new ReportThree();
  reports.push_back(one);
  reports.push_back(two);
  reports.push_back(three);
  
}

void Control::launch(){
  int choice;

  while(1){
    view.showMenu(choice);

    if(choice == 0){
      break;
    }

    if(choice == 1){
      one->compute();
      //one->clean;
    }
    if(choice == 2){
      two->compute();
      //two->clean();
    }
    if(choice == 3){
      three->compute();
    }

  }
}

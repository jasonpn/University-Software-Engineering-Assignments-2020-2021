#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

void Control::launch(){
  Telco* tel = new Telco("TELCO COMPANY");
  int choice;
  string freq;

  initData(tel);

  while (1){
    view.showMenu(choice);

    if(choice == 0){
      break;
    }

    if(choice == 1){
      view.printStr("Enter destination number, or all ");
      view.readStr(freq);
      tel->computeFreqCaller(freq);
      
    }

    if(choice == 2){
      view.printStr("Enter source number, or all ");
      view.readStr(freq);
      tel->computeFreqCalled(freq);
      
    }

    if(choice == 3){
      tel->print();
    }

  }
}

void Control::initData(Telco* tel)
{
  initSubscribers(tel);
  initCalls(tel);
}

void Control::initSubscribers(Telco* tel)
{
  tel->addSub(new Subscriber("6139990000")); 
  tel->addSub(new Subscriber("6133334444"));
  tel->addSub(new Subscriber("6138889999")); 
  tel->addSub(new Subscriber("6131112222"));
  tel->addSub(new Subscriber("6132223333"));
  tel->addSub(new Subscriber("6134445555")); 
}

void Control::initCalls(Telco* tel)
{
  tel->addCall("6139990000", "6133334444", 2020, 1, 1, 0, 31, 12);
  tel->addCall("6139990000", "6132223333", 2019, 2, 2, 10, 54, 2);

  tel->addCall("6132223333", "6139990000", 2019, 2, 23, 6, 33, 11);
  tel->addCall("6132223333", "6139990000", 2019, 3, 2, 10, 54, 2);
  tel->addCall("6132223333", "6139990000", 2019, 2, 20, 14, 22, 5);
  tel->addCall("6132223333", "6131112222", 2019, 12, 18, 4, 5, 15);

  tel->addCall("6131112222", "6132223333", 2019, 6, 30, 6, 2, 5);
  tel->addCall("6131112222", "6139990000", 2019, 8, 9, 8, 29, 7);
  tel->addCall("6131112222", "6130000000", 2019, 8, 9, 8, 29, 7);
  tel->addCall("6131112222", "6138889999", 2019, 3, 10, 15, 12, 11);

  tel->addCall("6134445555", "6138889999", 2019, 3, 10, 15, 22, 1);
  tel->addCall("6134445555", "6138887777", 2019, 3, 10, 15, 24, 10);
}


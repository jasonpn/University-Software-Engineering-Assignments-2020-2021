#include <iostream>
using namespace std;
#include <string>
#include <time.h>

#include "Race.h"
#include "Runner.h"
//Race control class, displays the race and runners
Race::Race(){
  //seed random 
  srand((unsigned)time(NULL ));
  
  Runner* tortoise = new Runner("Tortoise", 'T', 2, 1);
  Runner* hare = new Runner("Hare", 'H', 1, 3);
  runners.add(tortoise);
  runners.add(hare);

  //initialize runners in display
  Position tp = tortoise->getPos();
  Position hp = hare->getPos();
  view.update(tp,tp,tortoise->getAvatar());
  view.update(hp,hp,hare->getAvatar());
}

//check if a runner is at the finish line
bool Race::isOver(string& outcome){
  for(int i =0; i<runners.getSize();i++){
    if(runners.get(i)->getPos().getCol() == 24){
      outcome = runners.get(i)->getName(); //store winner's name in parameter
      return true;
    }
  }
  return false;
}

//main function to run the race
void Race::run(){
  Position newp = Position(0,0);
  Position oldp = Position(0,0);
  string out;
  //loop until the race is over
  while(!isOver(out)){
    view.print();
    for(int i = 0; i<runners.getSize();i++){
      oldp = runners.get(i)->getPos();
      runners.get(i)->update(newp);
      //error checking if move is valid
      if (!view.validPos(newp)){
	runners.get(i)->setPos(oldp.getRow(),oldp.getCol());
	newp = oldp;
      }
      //display race and logs
      cout<<runners.get(i)->getLog()<<endl;
      view.update(oldp, newp, runners.get(i)->getAvatar());
    } 
  }
  view.print();
  cout<< out << " WINS " <<endl;
  
}

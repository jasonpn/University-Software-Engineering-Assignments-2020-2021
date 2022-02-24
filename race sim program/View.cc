#include <iostream>
using namespace std;
#include <string>

#include "View.h"

//View class creating the 2d array display for the race

//View constructor initializing the display dynamic 2d array
View::View(){
  display = new char*[MAX_ROWS];
  for (int i = 0; i < MAX_ROWS; i++){
    display[i] = new char[MAX_COLS];
  }
  for(int i = 0; i<MAX_ROWS; i++){
    for (int j = 0; j<MAX_COLS; j++){
      display[i][j] = ' ';
    }
  }
}

//View destructor freeing the dynamic 2d array
View::~View(){
  for(int i = 0; i<MAX_ROWS; i++){
    delete[] display[i];
  }
  delete[] display;
}

//updating the view to move the avatars to their positions
void View::update(Position& oldPos, Position& newPos, char avatar){
  display[oldPos.getRow()][oldPos.getCol()] = ' ';
  display[newPos.getRow()][newPos.getCol()] = avatar;
}

//check if position is valid
bool View::validPos(Position& pos){
  if (pos.getRow() < 1 || pos.getRow() > 24 || pos.getCol()<0 || pos.getCol()>24){
    return false;
  }
  return true;
}

//print the str string
void View::printStr(string str){
  cout << str;
}

//print the 2d array race course
void View::print(){
  cout<<"---------------------------"<<endl;
  for(int i = 0; i<MAX_ROWS; i++){
    cout<<"|"<<display[i][0];
    for(int j = 1; j<MAX_COLS; j++){
      cout<<display[i][j];
    }
    cout<<"|"<<endl;
  }
  cout<<"---------------------------"<<endl;

}

#include <iostream>
using namespace std;

#include "Position.h"
//Position class storing row and column

//Position constructor initialize row and column
Position::Position(int r, int c){
  row = r;
  col = c;
}

//get the row position
int Position::getRow(){
  return row;
}

//get the column position
int Position::getCol(){
  return col;
}

//set the position row
void Position::setRow(int r){
  row = r;
}

//set the position column
void Position::setCol(int c){
  col = c;
}

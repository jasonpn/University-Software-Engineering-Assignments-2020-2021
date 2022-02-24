#ifndef POSITION_H
#define POSITION_H

//Position class to determine row and column positions
class Position{
 public:
  Position(int=0,int=0);
  int getRow();
  int getCol();
  void setRow(int);
  void setCol(int);
 private:
  int row;
  int col;
};

#endif

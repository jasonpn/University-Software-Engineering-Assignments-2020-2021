#ifndef GUEST_H
#define GUEST_H

/*
Guest class to create a guest for hotel, guests have name and premium points
*/
class Guest{
 public:
  Guest(string = "name", bool = false);
  string getName();
  bool getPrem();
  void addPts(int);
  void print();
 private:
  string name;
  bool prem;
  int numPoints;
  
};

#endif
